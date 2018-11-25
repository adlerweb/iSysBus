unit Main;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ComCtrls, iSysBusConnection, iSysBusConnection_rs232, iSysBusTypes,
  StdCtrls, ExtCtrls,httpApp, iSysBusConnection_TCP, iSysBusComponent,
  iSysBusComponent_Lampe;

type
  TForm3 = class(TForm)
    ListView1: TListView;
    Memo1: TMemo;
    Button2: TButton;
    Splitter1: TSplitter;
    Splitter2: TSplitter;
    EdSource: TEdit;
    EdDestination: TEdit;
    EdPort: TEdit;
    Edit1: TEdit;
    Edit2: TEdit;
    Edit3: TEdit;
    Edit4: TEdit;
    Edit5: TEdit;
    Edit6: TEdit;
    Edit7: TEdit;
    Edit8: TEdit;
    EdFlags: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    EdLength: TEdit;
    Label6: TLabel;
    ListBox1: TListBox;
    Button3: TButton;
    Button5: TButton;
    Button6: TButton;
    Button7: TButton;
    isysBusConnection_TCP1: TisysBusConnection_TCP;
    Button10: TButton;
    Button11: TButton;
    Button12: TButton;
    EdId: TEdit;
    Label7: TLabel;
    procedure Button12Click(Sender: TObject);
    procedure Button11Click(Sender: TObject);
    procedure Button10Click(Sender: TObject);

    procedure Button8Click(Sender: TObject);
    procedure ListBox1Click(Sender: TObject);
    procedure Button7Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure isysBusConnection_rs2321Receive(package: TiSysBusPackage);

  private
    procedure Myshowmessage(Msg: TiSysBusPackage);
    function getmessage:TiSysBusPackage;
    procedure setmessage(msg:TiSysBusPackage);
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form3: TForm3;

implementation

{$R *.dfm}

procedure TForm3.Myshowmessage(Msg: TiSysBusPackage);
var
  i: Integer;
  Item:TListitem;
  Data:String;
begin



ListView1.AddItem(inttostr(msg.Source),nil);
Item:=ListView1.Items[ListView1.Items.Count -1];

//Item:=Form1.ListView1.Items.Add;
//Item.Caption :=inttostr(msg.Source);
Item.SubItems.add(inttostr(msg.destination));
Item.SubItems.add(inttostr(msg.Port));
Item.SubItems.add(inttostr(msg.flags));


For i := 0 to msg.length -1 Do  Begin

    Data:=Data+'#'+(inttostr(msg.Data[i]));
    end;
Item.SubItems.add(Data);

end;

procedure TForm3.isysBusConnection_rs2321Receive(package: TiSysBusPackage);
begin
Memo1.Perform(EM_LineScroll, 0 , Memo1.Lines.Count-1); //Memo nach unten scrollen um den neuesten text anzuzeigen
MyShowmessage(package);

end;

procedure TForm3.FormCreate(Sender: TObject);
begin
isysBusConnection_TCP1.LogStrings:= memo1.Lines;
Button7Click(self);
end;

procedure TForm3.Button1Click(Sender: TObject);
begin
//isysBusConnection_r.open;
end;

procedure TForm3.Button2Click(Sender: TObject);
var
msg:TiSysBusPackage;
begin
msg:=getmessage;
//isysBusConnection_rs2321.sendmessage(msg);

While ( isysBusConnection_TCP1.FInUse = true) Do begin
 Application.ProcessMessages ;
end;
//isysBusConnection_TCP1.FInUse := True;
//isysBusConnection_TCP1.FPackageReceived := false;
isysBusConnection_TCP1.sendmessage(msg);
//isysBusConnection_TCP1.Wait4Response(msg.Destination);

//isysBusConnection_TCP1.FInUse := False;

end;

function TForm3.getmessage: TiSysBusPackage;
var
  i: Integer;

begin
with result do Begin
  Source:= StrToInt(EdSource.text);
  Destination := StrToInt(EdDestination.text);
  Port:= StrToInt(EdPort.Text);
  flags:= StrToInt(EdFlags.Text);
  length := StrToInt(EdLength.Text);

  For i := 1 to 8 Do Begin
    Data[i-1]:=StrToInt((FindComponent('Edit' + IntToStr(i)) As TEdit).Text);
  end;

end;
end;

procedure TForm3.setmessage(msg: TiSysBusPackage);
var
  i: Integer;
begin
with msg Do Begin
  EdSource.text:= IntToStr(source);
  EdDestination.text := IntToStr(Destination);
  EdPort.Text:= IntToStr(Port);
  EdFlags.Text:=IntToStr(flags);
  EdLength.Text:=IntToStr(Length);

  For i := 0 to 7 Do Begin
   (FindComponent('Edit'+IntToStr(i+1)) As TEdit).Text := IntToStr(Data[i]);
  end;

end;
end;

procedure TForm3.Button3Click(Sender: TObject);
var
p:pointer;

msg:TiSysBusPackage;
pmsg:^TiSysBusPackage;
o:TObject;
desc:String;
begin

msg := getmessage;
GetMem(pmsg,sizeof(TisysBusPackage));
pmsg^:=msg;
p:=pmsg;
o:=p;
InputQuery('Add','Name für neuen Eintrag',desc);
ListBox1.Items.AddObject(desc,o);
end;

procedure TForm3.Button4Click(Sender: TObject);
var
p:pointer;
msg:TiSysBusPackage;
pmsg:^TiSysBusPackage;
o:TObject;
begin
if ListBox1.ItemIndex = -1 Then Exit;

o:= ListBox1.Items.Objects[Listbox1.ItemIndex];
p:= o;
pmsg:=p;
setmessage(pmsg^);
end;

procedure TForm3.Button5Click(Sender: TObject);
begin
if ListBox1.ItemIndex = -1 Then Exit;
ListBox1.Items.Delete(ListBox1.ItemIndex);
end;

procedure TForm3.Button6Click(Sender: TObject);
var
  i,j:integer;
  s:String;
  f:TextFile;
  pchar:^char;
  p:Pointer;
  pmsg:^TisysBusPackage;
  msg:TiSysBusPackage;
  Buf:Array[0..20] of Char;
begin
AssignFile(f,'save.txt');
rewrite(f);

  For i := 0 to ListBox1.Items.Count -1 Do
  Begin
    s:=ListBox1.Items[i];
    Writeln(f,s);

    p:=ListBox1.Items.Objects[i];
    pmsg :=p;
    msg :=pmsg^;

    with msg Do Begin
      WriteLn(f,Source);
      Writeln(f,Destination);
      WriteLn(F,Port);
      WriteLn(F,Length);
      For j := 0 to 7 Do WriteLn(F,Data[j]);
      WriteLn(F,Flags);

    end;


  end;
Flush(f);
CloseFile(f);
end;



procedure TForm3.Button7Click(Sender: TObject);
var
  i,j:integer;
  s:String;
  f:TextFile;
  pchar:^char;
  p:Pointer;
  o:TObject;
  pmsg:^TisysBusPackage;
  msg:TiSysBusPackage;
  Buf:Array[0..20] of Char;
begin
AssignFile(f,'save.txt');
reset(f);

ListBox1.Clear;


  While Not EOF(f) Do
  Begin
    ReadLn(f,s);


    Getmem(pmsg,SizeOf(TisysBusPAckage));
    msg :=pmsg^;

    with pmsg^ Do Begin
      ReadLn(f,Source);
      Readln(f,Destination);
      ReadLn(F,Port);
      ReadLn(F,Length);
      For j := 0 to 7 Do Begin
      ReadLn(F,i);
      Data[j]:=i;
      end;
      ReadLn(F,Flags);

    end;
    p:= pmsg;
    o:= p;
    ListBox1.Items.AddObject(S,o)

  end;
CloseFile(f);

end;

procedure TForm3.ListBox1Click(Sender: TObject);
begin
Button4Click(self);
end;

procedure TForm3.Button8Click(Sender: TObject);
begin
Showmessage(IntToStr(isysBusConnection_TCP1.getinteger(30,65,2,0)));
end;


procedure TForm3.Button10Click(Sender: TObject);
var
start:Cardinal;
begin
start := gettickCount;
isysBusConnection_TCP1.sendmessage(0,strtoint(edid.Text),10,0,'ping');
isysBusConnection_TCP1.Wait4Response(30);
memo1.Lines.Add('ping: '+ inttostr(GetTickCount - Start) );
end;

procedure TForm3.Button11Click(Sender: TObject);
var
start:Cardinal;
i:Byte;
begin
For i := 0 to 20 Do
Begin
start := gettickCount;
isysBusConnection_TCP1.sendmessage(0,strtoint(edid.Text),10,0,char(i));
isysBusConnection_TCP1.Wait4Response(30);
memo1.Lines.Add('ping: '+ inttostr(GetTickCount - Start) );
end;
end;

procedure TForm3.Button12Click(Sender: TObject);
begin
memo1.Clear;
ListView1.Clear;
end;

end.
