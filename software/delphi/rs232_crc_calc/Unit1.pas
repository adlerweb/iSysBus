unit Unit1;
interface
uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ComCtrls, CrossEdit;

type
  TForm1 = class(TForm)
    edit_flags: TCrossEdit;
    edit_startbyte: TEdit;
    edit_data0: TCrossEdit;
    edit_dlc: TEdit;
    updown_dlc: TUpDown;
    edit_data1: TCrossEdit;
    edit_data2: TCrossEdit;
    edit_data3: TCrossEdit;
    edit_data4: TCrossEdit;
    edit_data5: TCrossEdit;
    edit_data6: TCrossEdit;
    edit_data7: TCrossEdit;
    edit_crc1: TEdit;
    edit_crc2: TEdit;
    edit_stop: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Label6: TLabel;
    Label7: TLabel;
    edit_dest1: TCrossEdit;
    edit_dest2: TCrossEdit;
    edit_source1: TCrossEdit;
    edit_source2: TCrossEdit;
    procedure updown_dlcClick(Sender: TObject; Button: TUDBtnType);
    procedure data_change(Sender: TObject);
  private
  public
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}


procedure TForm1.data_change(Sender: TObject);
type
  TMsg = packed record
    Len: Byte;
    Flags: Byte;
    Dest1: Byte;
    Dest2: Byte;
    Source1: Byte;
    Source2: Byte;
    Data: array [0..7] of Byte;
  end;
var
  sum: Integer;
  tmp: Word;
  msg: TMsg;
  ptr: ^Word;
begin
  Msg.Flags := edit_flags.GetInteger;
  Msg.Dest1 := edit_dest1.GetInteger;
  Msg.Dest2 := edit_dest2.GetInteger;
  Msg.Source1 := edit_source1.GetInteger;
  Msg.Source2 := edit_source2.GetInteger;
  Msg.Data[0] := edit_data0.GetInteger;
  Msg.Data[1] := edit_data1.GetInteger;
  Msg.Data[2] := edit_data2.GetInteger;
  Msg.Data[3] := edit_data3.GetInteger;
  Msg.Data[4] := edit_data4.GetInteger;
  Msg.Data[5] := edit_data5.GetInteger;
  Msg.Data[6] := edit_data6.GetInteger;
  Msg.Data[7] := edit_data7.GetInteger;
  Msg.Len := 5+updown_dlc.Position;
  ptr := @Msg.Flags;
  sum := 0;
  while Msg.Len > 1 do
  begin
    sum := sum + ptr^;
    ptr := Pointer(Integer(ptr)+2);
    Msg.Len := Msg.Len - 2;
  end;
  if Msg.Len > 0 then
    sum := sum + ptr^ and $ff;
  while ((sum shr 16) and $ffff) > 0 do
  begin
    tmp := (sum shr 16) and $ffff;
    sum := (sum and $ffff) + tmp; 
  end;
  sum := (sum and $ffff) xor $ffff;
  edit_crc1.Text := IntToHex(sum and $ff, 2);
  edit_crc2.Text := IntToHex(sum shr 8, 2);
end;

procedure TForm1.updown_dlcClick(Sender: TObject; Button: TUDBtnType);
begin
  edit_data0.Enabled := updown_dlc.Position > 0;
  edit_data1.Enabled := updown_dlc.Position > 1;
  edit_data2.Enabled := updown_dlc.Position > 2;
  edit_data3.Enabled := updown_dlc.Position > 3;
  edit_data4.Enabled := updown_dlc.Position > 4;
  edit_data5.Enabled := updown_dlc.Position > 5;
  edit_data6.Enabled := updown_dlc.Position > 6;
  edit_data7.Enabled := updown_dlc.Position > 7;
  data_change(Self);
end;

end.
