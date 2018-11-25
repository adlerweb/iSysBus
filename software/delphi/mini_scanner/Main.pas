unit Main;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, iSysBusConnection, iSysBusConnection_rs232, StdCtrls, iSysBusTypes,
  iSysBusConnection_TCP;

type
  TForm1 = class(TForm)
    ListBox1: TListBox;
    Button1: TButton;
    isysBusConnection_TCP1: TisysBusConnection_TCP;
    procedure isysBusConnection_TCP1Receive(package: TiSysBusPackage);
    procedure Button1Click(Sender: TObject);
   
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}






procedure TForm1.Button1Click(Sender: TObject);
var
i:integer;
begin
For i := 0 to 40 Do Begin
isysBusConnection_TCP1.sendmessage(0,i,10,0,'ff');
end;

end;

procedure TForm1.isysBusConnection_TCP1Receive(package: TiSysBusPackage);
begin
If (package.Destination = 0) then Begin
  ListBox1.Items.Add(inttostr(package.Source));
end;
end;

end.
