unit Unit1;
interface
uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, CPort, StdCtrls, Buttons, ExtCtrls;

type
  TForm1 = class(TForm)
    cport: TComPort;
    memo: TMemo;
    active: TSpeedButton;
    procedure FormCreate(Sender: TObject);
    procedure cportRxChar(Sender: TObject; Count: Integer);
    procedure cportTxEmpty(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure activeClick(Sender: TObject);
  private
  public
  end;


var
  Form1: TForm1;

type
  Tisb_message = packed record
    startbyte:   Char;
    port:        Byte;
    destination: Word;
    source:      Word;
    flags:       Byte;
    datalength:  Byte;
    data:        array[0..7] of Byte;
    crc:         Word;
    stopbyte:    Char;
  end;

var
  msg: Tisb_message = (
    startbyte: '<';
    port: 1;
    destination: 2;
    source: 3;
    flags: 4;
    datalength: 8;
    data: (0,0,0,0,0,0,0,0);
    crc: 0;
    stopbyte: '>'; 
  );

  rx_buf: array[0..1023] of Byte;
  rx_buf_mask: Word = 1023;
  tail: Word = 0;
  head: Word = 0;
  last_rx: Int64;

  log: Text;
  unk: Text;

implementation

{$R *.dfm}



function calc_crc(msg: Tisb_message): Word;
var
  sum, len: LongWord;
  i: Integer;
begin
  with msg do
  begin
    sum := 0;
    sum := sum + Byte(startbyte) + port * 256;
    sum := sum + destination;
    sum := sum + source;
    sum := sum + flags + datalength * 256;
    len := datalength;
    i := 0;
    while len > 2 do
    begin
      sum := sum + data[i] + data[i+1] * 256;
      i := i + 2;
      len := len - 2;
    end;
    if len > 0 then
      sum := sum + data[i];

    while (sum shr 16) > 0 do
    begin
      len := sum shr 16;
      sum := Word(sum) + len;
    end;

    Result := Word(sum) xor $FFFF;
  end;
end;



procedure SendISBMessage;
begin
  Inc(Int64((@msg.data[0])^));
//  msg.crc := calc_crc(msg);
  msg.crc := 0;
  Form1.cport.Write(msg.startbyte, 8 + msg.datalength);
  Form1.cport.Write(msg.crc, 3);
end;



function DecodeMessage(msg: Tisb_message): String;
var
  i: Integer;
begin
  with msg do
  begin
    Result := startbyte + IntToHex(port, 2) + '.' +
        IntToHex(destination, 4) + '.' + IntToHex(source, 4) + '.' +
        IntToHex(flags, 2) + '.' + IntToHex(datalength, 2) + '.';
    if datalength > 0 then
      for i := 0 to datalength - 1 do
        Result := Result + IntToHex(data[i], 2);
    Result := Result + '.' + IntToHex(crc, 4) + stopbyte;
  end;
end;



function ISBMsgAvail: Boolean;
var
  pos, relpos, startbyte: Word;
  crc: Word;
  length: Byte;
  rx: Tisb_message;

  temps: String;
begin
  relpos := 0;
  startbyte := 0;
  length := 0;
  crc := 0;

  Result := False;
{
  temps := '';
  pos := (tail + 1) and rx_buf_mask;
  while pos <> ((head + 1) and rx_buf_mask) do
  begin
    relpos := relpos + 1;
    temps := temps + IntToHex(rx_buf[pos], 2) + ' ';
    if (relpos mod 19) = 0 then
    begin
      relpos := 0;
      form1.memo.Lines.Add(temps);
      temps := '';
      tail := pos;
      Application.ProcessMessages;
    end;
    pos := (pos + 1) and rx_buf_mask;
  end;

      Form1.Caption := 'Sent: ' + IntToStr(Int64((@msg.data[0])^)) +
        ' - Received: ' + IntToStr(form1.memo.Lines.Count);
}

  pos := (tail + 1) and rx_buf_mask;
  while pos <> ((head + 1) and rx_buf_mask) do
  begin
    if relpos = 0 then
    begin
      if rx_buf[pos] = Ord('<') then
      begin
        relpos := relpos + 1;
        startbyte := pos;
        rx.startbyte := Chr(rx_buf[pos]);
      end
      else
      begin
        Write(unk, IntToHex(rx_buf[pos], 2), ' ');
        tail := pos;
      end;
    end
    else if relpos = 7 then
    begin
      length := rx_buf[pos];
      relpos := relpos + 1;
      rx.datalength := length;
    end
    else if relpos = (length + 10) then
    begin
      if rx_buf[pos] = Ord('>') then
      begin
        rx.stopbyte := Chr(rx_buf[pos]);
//        crc := calc_crc(rx);
        crc := 0;
        if crc = rx.crc then
          Result := True
        else
          ShowMessage('Wrong CRC: ' + IntToHex(crc, 4) + ' - orig: ' + IntToHex(rx.crc, 4));
        Break;
      end
      else
      begin
        pos := startbyte;
        relpos := 0;
      end;
    end
    else
    begin
      case relpos of
        1: rx.port := rx_buf[pos];
        2: rx.destination := rx_buf[pos];
        3: rx.destination := rx.destination + rx_buf[pos] * 256;
        4: rx.source := rx_buf[pos];
        5: rx.source := rx.source + rx_buf[pos] * 256;
        6: rx.flags := rx_buf[pos];
      else
        if relpos in [8..(7+length)] then
          rx.data[relpos - 8] := rx_buf[pos];
        if relpos = (length + 8) then
          rx.crc := rx_buf[pos];
        if relpos = (length + 9) then
          rx.crc := rx.crc + rx_buf[pos] * 256;
      end;
      relpos := relpos + 1;
    end;
    pos := (pos + 1) and rx_buf_mask;
  end;

  if Result then
  begin
    tail := pos;

    if Int64((@rx.data[0])^) <> last_rx + 1 then
      Form1.memo.Lines.Add(
          'Missed ' + IntToStr(Int64((@rx.data[0])^) - last_rx) + ' messages. Last message id: ' + IntToStr(last_rx) +
          ' - current id: ' + IntToStr(Int64((@rx.data[0])^)) );
    last_rx := Int64((@rx.data[0])^);

    WriteLn(unk, '');
    WriteLn(unk, 'ID ', IntToStr(last_rx));

    if not Form1.active.Down then
      Form1.Caption := 'Sent: ' + IntToStr(Int64((@msg.data[0])^)) +
        ' - Received: ' + IntToStr(last_rx);

    WriteLn(log, DecodeMessage(rx) + ' - ' + IntToStr(last_rx));
  end;

end;



function GetByte: Byte;
begin
  Result := $FF;
  if head <> tail then
  begin
    tail := (tail + 1) and rx_buf_mask;
    Result := rx_buf[tail];
  end;
end;



procedure TForm1.cportRxChar(Sender: TObject; Count: Integer);
var
  tmphead: Word;
  data: Byte;
  i: Integer;
begin
  for i := 1 to Count do
  begin
    if cport.Read(data, 1) > 0 then
    begin
      tmphead := (head + 1) and rx_buf_mask;
      if tmphead <> tail then
      begin
        rx_buf[tmphead] := data;
        head := tmphead;
      end;
    end;
  end;
  ISBMsgAvail;
end;



procedure TForm1.activeClick(Sender: TObject);
begin
//  memo.Visible := not active.Down;
  if active.Down then
    SendISBMessage;
  if not active.Down then
    Caption := 'Sent: ' + IntToStr(Int64((@msg.data[0])^)) +
        ' - Received: ' + IntToStr(last_rx);

//  memo.Visible := not active.Down;
end;

procedure TForm1.cportTxEmpty(Sender: TObject);
begin
  if active.Down then
    SendISBMessage;
  if (Int64((@msg.data[0])^) mod 10) = 0 then
    Caption := 'Sent: ' + IntToStr(Int64((@msg.data[0])^)) +
        ' - Received: ' + IntToStr(last_rx);
end;

procedure TForm1.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  cport.Close;
  CloseFile(log);
  CloseFile(unk);
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
  cport.ShowSetupDialog;
  cport.CustomBaudRate := 76800;
  cport.Open;
  AssignFile(log, 'log.txt');
  ReWrite(log);
  AssignFile(unk, 'unknown_data.txt');
  ReWrite(unk);
end;


end.
