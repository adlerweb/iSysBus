unit Main;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ScktComp, CPort, IniFiles;

type
  TPacket = record
    Source,Destination:Word;
    fncode,length:Byte;
    Data:Array[0..7] of Byte;
    flags:Byte;
    used:boolean;
    ready:boolean;
    //CRC:integer;
  end;

  TForm2 = class(TForm)
    ComPort1: TComPort;
    ServerSocket1: TServerSocket;
    Button1: TButton;
    Button2: TButton;
    Label1: TLabel;
    LaRx: TLabel;
    Label3: TLabel;
    LaTx: TLabel;
    Label5: TLabel;
    LaClients: TLabel;
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure ServerSocket1ClientConnect(Sender: TObject;
      Socket: TCustomWinSocket);
    procedure ServerSocket1ClientRead(Sender: TObject;
      Socket: TCustomWinSocket);
    procedure ComPort1RxChar(Sender: TObject; Count: Integer);
    procedure FormCreate(Sender: TObject);
    procedure Button1Click(Sender: TObject);
  private
    procedure incClients;
    procedure sendmsg(Msg: TPacket);
    function decodenet(MessageString: String): TPacket;
    function HexToInt(HexNum: string): LongInt;
    procedure sendnet(Msg: TPacket);
    { Private declarations }


    procedure SaveSettings;
    procedure LoadSettings;
    procedure Log(S:String);
    procedure incRx;
    procedure incTx;
  public
    { Public declarations }
  end;


var
  Form2: TForm2;

  RxBufCount:integer=-1;
  RxBuf:TPacket;
  RxBufPointer:^Byte;


const
UartPacketSize = 15;

implementation

{$R *.dfm}


procedure TForm2.Button1Click(Sender: TObject);
begin
ComPort1.ShowSetupDialog;
SaveSettings ;
ComPort1.Close;
ComPort1.Open;
end;

procedure TForm2.LoadSettings;
var
ini:TiniFile;
b:byte;
begin
ini:=TIniFile.Create(ExtractFilePath(Application.ExeName)+ 'settings.ini');
ComPort1.Port:= ini.ReadString('comport','port','com1');
b:=ini.ReadInteger('comport','baudrate',0);
ComPort1.BaudRate:=TBaudRate(b);
ini.Free;

end;

procedure TForm2.SaveSettings;
var
ini:TiniFile;
b:byte;
begin
ini:=TIniFile.Create(ExtractFilePath(Application.ExeName)+'settings.ini');
ini.WriteString('comport','port',ComPort1.Port);
b:=Byte(ComPort1.BaudRate);
ini.WriteInteger('comport','baudrate',b);

ini.Free;
end;

procedure TForm2.FormCreate(Sender: TObject);
begin
LoadSettings;
ComPort1.Open;
end;

procedure TForm2.ComPort1RxChar(Sender: TObject; Count: Integer);
var
  Str: String;
  i: Integer;
  b:byte;

begin

for i := 0 to Count-1 Do Begin
  ComPort1.ReadStr(Str, 1);
 // comport1.read(B,1);
  //str := char(b);
 // if count > 1 then showmessage('größer '+ inttostr(count));
  Log( Str);


  If (RxBufCount =-1) then Begin
    If str='!' then Begin           //Packet Start Received

      RxBufCount := 0;
      RxBufPointer:=@RxBuf;
    end;
  end else Begin
   RxBufPointer ^ :=ord(Str[1]);
   inc(RxBufPointer);
   inc(RxBufCount);
   If RxBufCount = UartPacketSize  Then Begin     //Packet fertig empfangen


     sendnet(RxBuf);
     incRx;
     RxBufCount:=-1;




   end;


  end;

end;
end;

procedure TForm2.Log(S: String);
var
F:TextFile;
begin
If FileExists('log.txt') then AssignFile(F,'log.txt') else Rewrite(F,'log.txt');
Append(F);
Write(F,S);
CloseFile(F);
end;

procedure TForm2.sendnet(Msg: TPacket);
var
  i:integer;
  MessageString:String;

begin

MessageString:= Format('!CAN %4.4x %4.4x %2.2x %2.2x %2.2x ',[msg.Destination,msg.Source,msg.fncode, msg.flags, msg.length]);
For i := 0 to (msg.length -1) Do
Begin
 Messagestring := Messagestring + inttohex(msg.data[i],2);
end;


For i := 0 to ServerSocket1.Socket.ActiveConnections -1 Do
  Begin
    try
      ServerSocket1.Socket.Connections[i].SendText(MessageString);
    except end;
  end;
end;

procedure TForm2.incRx;
begin
LaRx.Caption:=inttostr(strtoint(LaRx.caption)+1);
end;

procedure TForm2.incTx;
begin
LaTx.Caption:=inttostr(strtoint(LaTx.caption)+1);
end;

procedure TForm2.incClients;
begin
LaClients.Caption:=inttostr(strtoint(LaClients.caption)+1);
end;

procedure TForm2.ServerSocket1ClientRead(Sender: TObject;
  Socket: TCustomWinSocket);
var
  s: string;
  msg:TPacket;
begin
s:= Socket.ReceiveText;
log(s);
 msg:=decodenet(s);
 sendmsg(msg);
end;

function TForm2.decodenet(MessageString: String): TPacket;
var
 s:String;
 dataString:string;
 Strings:TStringList;
 i:integer;
begin
 if length(messagestring) = 0 then exit;
 if messagestring[1] <> '!' then exit;

 Strings:= TStringList.Create;
 Strings.Delimiter:= ' ';
 Strings.DelimitedText:= messagestring;

 if Strings.Count >=7 then
 if Strings[0]='!CAN' then
 Begin
   with Result do Begin
     Destination:=HexToInt(Strings[1]);
     Source     :=HexToInt(Strings[2]);
     fncode     :=HexToInt(Strings[3]);
     flags      :=HexToInt(Strings[4]);
     length     :=HexToInt(Strings[5]);
     DataString :=Strings[6];
     for i := 0 to length -1 do
     begin
       s:=Copy(Strings[6],i*2+1,2);
       data[i] := HexToInt(s);
     end;
   end;

 end;

 Strings.Free;

end;

function TForm2.HexToInt(HexNum: string): LongInt;
begin
  Result:=StrToInt('$' + HexNum);
end;

procedure TForm2.sendmsg(Msg:TPacket);
var
J:integer;
P:^Byte;
  i: Integer;
Begin
//StartByte

  Comport1.WriteStr('!');
  p:=@Msg;

  For i := 0 to UartPacketSize -1 Do Begin
    Comport1.TransmitChar (char(p^));
    inc(p);
  end;
  incTx;
end;

procedure TForm2.ServerSocket1ClientConnect(Sender: TObject;
  Socket: TCustomWinSocket);
begin
Log('Client Added');

end;

procedure TForm2.FormClose(Sender: TObject; var Action: TCloseAction);
begin
ComPort1.Close;
end;

end.
