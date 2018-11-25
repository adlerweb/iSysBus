unit Unit2;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs,oshb, StdCtrls, comctrls, HTTPApp;

type
  TForm2 = class(TForm)
    Label1: TLabel;
    Edit1: TEdit;
    Label2: TLabel;
    Edit2: TEdit;
    Label3: TLabel;
    Edit3: TEdit;
    Label4: TLabel;
    Edit4: TEdit;
    ListBox1: TListBox;
    ListBox2: TListBox;
  private
    { Private declarations }
  public
    procedure showmessage(Msg :TPacket);
  end;

var
  Form2: TForm2;

implementation
uses Unit1;

{$R *.dfm}

{ TForm2 }

procedure TForm2.showmessage(Msg: TPacket);
var
  i: Integer;
  Item:TListitem;
  Data:String;
begin
Edit1.Text:= inttostr(msg.Source);
Edit2.Text:= inttostr(msg.Destination);
Edit3.Text:= inttostr(msg.fncode);
Edit4.Text:= inttostr(msg.length);
ListBox1.Clear;

Item:=Form1.ListView1.Items.Add;
Item.Caption :=inttostr(msg.Source);
Item.SubItems.add(inttostr(msg.destination));
Item.SubItems.add(inttostr(msg.fncode));
Item.SubItems.add(inttostr(msg.length));


For i := 0 to msg.length -1 Do  Begin
    Listbox1.Items.Add(inttostr(msg.Data[i]));
    Data:=Data+'#'+(inttostr(msg.Data[i]));
    end;
Item.SubItems.add(Data);
Form2.Show;
end;


end.
