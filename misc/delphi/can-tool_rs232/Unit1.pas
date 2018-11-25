unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs,PortInc, StdCtrls, ExtCtrls,oshb, CPort, ComCtrls,HTTPApp;

type
   DynamicByteArray=Array of Byte;
  TForm1 = class(TForm)
    Button7: TButton;
    Edit2: TEdit;
    Label2: TLabel;
    Edit3: TEdit;
    Button1: TButton;
    ListBox1: TListBox;
    DeviceBox: TListBox;
    BusTimer: TTimer;
    Button2: TButton;
    Label1: TLabel;
    Edit1: TEdit;
    Label3: TLabel;
    Edit4: TEdit;
    ComPort1: TComPort;
    Memo1: TMemo;
    Edit_Data: TEdit;
    Button_Send: TButton;
    Edit5: TEdit;
    Edit6: TEdit;
    ListView1: TListView;
    Button3: TButton;
    Button4: TButton;
    Button5: TButton;
    Edit7: TEdit;
    Edit8: TEdit;
    Button6: TButton;
    Button8: TButton;
    procedure Button8Click(Sender: TObject);
    procedure ComPort1AfterClose(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button_SendClick(Sender: TObject);
    procedure ComDataPacket2Packet(Sender: TObject; const Str: string);
    procedure ComDataPacket1Packet(Sender: TObject; const Str: string);
    procedure ComPort1AfterOpen(Sender: TObject);
    procedure ComPort1RxChar(Sender: TObject; Count: Integer);
    procedure Button2Click(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure BusTimerTimer(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure Button7Click(Sender: TObject);
  private
    procedure Myshowmessage(Msg: TPacket);
    { Private-Deklarationen }
    function GetFreeRxBuf:integer;
    function GetFreeTxBuf:integer;
    procedure clearbufs;
    procedure sendmsg(Msg:TPacket);
    procedure rsSend(Sender,Target:Word;fncode,flags:Byte; Data:String);
    function resmsg(address: integer):TPacket;
    function bootProgrammPage(Data:DynamicByteArray;const page,pagesize:integer):boolean;
  public
    { Public-Deklarationen }
  end;






const Bufcount = 10000;
var
  Form1: TForm1;
  RxBuf,TxBuf:Array[0..BufCount-1]of TPacket;
    BusStop:boolean;
    RxBufCount:integer=-1;
    RxBufIndex:integer=-1;
    RxBufPointer:^Byte;
    bootloadexit:boolean = false;

//  DeviceList:Array of Integer;

implementation

uses Unit2;

{$R *.dfm}

procedure TForm1.FormCreate(Sender: TObject);
begin
//IF OPENCOM(Pchar('COM2:4800,N,8,1'))= 0 then Showmessage('error open com Port');;
ComPort1.Open;
end;

procedure TForm1.Button7Click(Sender: TObject);
var
addr:integer ;
mmsg:TPacket;
begin
mmsg.source:= strtoint(edit1.Text);
mmsg.Destination:= strtoint(edit2.Text);
mmsg.fncode:=strtoint(edit4.Text);
mmsg.length:=0;
mmsg.flags:=0;//RTR
mmsg.length:=4;
mmsg.Data[0]:= strtoint(edit5.text);
mmsg.Data[1]:= strtoint(edit6.text);
mmsg.Data[2]:= strtoint(edit7.text);
mmsg.Data[3]:= strtoint(edit8.text);


SendMsg(mmsg);

//OPENCOM(Pchar('COM1:9600,N,8,1'));
//Start



{addr := strtoint (edit2.text);
SENDBYTE(0);

SENDBYTE(addr mod  256);
SENDBYTE(addr div 256);


SENDBYTE(strtoint (edit2.text) mod 256);
SENDBYTE(strtoint (edit2.text) div 256);




//port
SENDBYTE(2);
//length
SENDBYTE(2);

SENDBYTE(strtoint (edit3.text) );
SENDBYTE(25);

//CRC
SENDBYTE(25);
SENDBYTE(25);   }

end;

procedure TForm1.Button1Click(Sender: TObject);
const
addr=55;
var

i:integer;
Mbyte:integer;
begin
//OPENCOM(Pchar('COM3:9600,N,8,1'));
//Start
{For i := 0 to 16 Do SENDBYTE(255);

SENDBYTE(0);


SENDBYTE(strtoint (edit2.text) mod  256);
SENDBYTE((strtoint (edit2.text) div 256) +128);    }
Listbox1.Clear;


For i := 0 to 100 Do Begin
MByte:=ReadByte;
if MByte <> -1 then
ListBOx1.Items.add(INttostr(MByte));
Application.ProcessMessages;
end;

//SENDBYTE( addr mod  256);
//SENDBYTE((addr div 256) +128);

 {
SENDBYTE(strtoint (edit2.text) mod 256);
SENDBYTE(strtoint (edit2.text) div 256);




//port
SENDBYTE(2);
//length
SENDBYTE(2);

SENDBYTE(strtoint (edit3.text) );
SENDBYTE(25);

//CRC
SENDBYTE(25);
SENDBYTE(25);  }


end;

procedure TForm1.BusTimerTimer(Sender: TObject);
var
  i,N: Integer;

  D:INteger;
  Packet:TPacket;
  j: Integer;
  k: Integer;
begin
BusTimer.Enabled:= false;

//Init Bus;

For i := 0 to 16 Do SENDBYTE(255);

 BusStop:= false;
while not Busstop Do Begin
Application.ProcessMessages;
//Send
  repeat
       N:= -1;
      for j:= 0 to Bufcount -1 do
      begin
        If TxBuf[j].used then Begin N:=j; break;end;

      end;
      If N <> -1 then BEgin;
      //Something to send;

      PAcket:=TxBuf[N];
      TxBuf[N].used := false;

      {SENDBYTE(0);

      SENDBYTE(Packet.Sender mod  256);
      SENDBYTE(Packet.Sender div 256);


      SENDBYTE(Packet.Target mod 256);
      SENDBYTE(Packet.Target div 256);




      //port
      SENDBYTE(Packet.Port);
      //length
      SENDBYTE(Packet.length);
      For j := 0 to Packet.length-1 Do
      SENDBYTE(Packet.Data[i] );


      //CRC
      SENDBYTE(Packet.CRC mod 256);
      SENDBYTE(Packet.CRC div 256);


        }



      end;
      until N = -1;

//Bus Polling
  For i := 0 to DeviceBox.Items.Count -1 Do Begin




    //receive
   { SENDBYTE(0);
    SENDBYTE(strtoint (DeviceBox.Items[i]) mod  256);
    SENDBYTE((strtoint (DeviceBox.Items[i]) div 256) +128);
    Packet.Source:=strtoint (DeviceBox.Items[i]);
    Packet.Destination:=READBYTE+READBYTE*256;
    Packet.fncode:= ReadByte;
    Packet.length:= ReadByte;
    if Packet.length > 0 then BEgin
      For j := 0 to Packet.length -1  Do Packet.data[i] := ReadByte;
      //Packet.CRC:=READBYTE+READBYTE*256;

      //Write to buffer
      N:= -1;
      for j:= 0 to Bufcount -1 do
      begin
        If not RxBuf[j].enabled then Begin N:=j; break;end;

      end;
      If N = -1 then Showmessage('Buffer full');
      RxBuf[N] := packet;
      RxBuf[N].enabled := true;
    end;    }
    if Packet.length = -1 Then Begin

    For k := 0 to 16 Do SENDBYTE(255);
   // Showmessage( 'Device not Responding');
    end;
  end;
end;
end;

procedure TForm1.FormClose(Sender: TObject; var Action: TCloseAction);
begin
BusStop:=True;
ComPort1.close;

end;

procedure TForm1.Button2Click(Sender: TObject);
begin
DeviceBox.Items.add(Edit3.Text);
end;
procedure TForm1.rsSend(Sender,Target:Word;fncode,flags:Byte; Data:String);
var
  N: Integer;
  j: Integer;
  packet: TPacket;

Begin
      packet.Source:=Sender;
      packet.Destination:= Target;
      packet.fncode:=fncode;
      packet.length:=length(Data);
      packet.flags:= 0;
      if length(Data) > 8 then BEgin Showmessage('Data too long'); packet.length:=8 end;

      For j := 0 to packet.length -1 Do
      packet.Data[j] := ord(Data[j+1]);

      //Crc = claccrc

       SendMsg(packet);
      {


      N:= -1;
      for j:= 0 to Bufcount -1 do
      begin
        If not TxBuf[j].enabled then Begin N:=j; break;end;

      end;
      If N = -1 then Showmessage('Buffer full') else Begin
      TxBuf[N] := packet;
      TxBuf[N].enabled := true;
      end;   }
end;

procedure TForm1.sendmsg(Msg:TPacket);
var
J:integer;
P:^Byte;
  i: Integer;
Begin
//StartByte
          // Form1.ComPort1.Close;
          // Form1.Comport1.Open;
      //Form1.Comport1.TransmitChar ('!');
       Comport1.WriteStr('!');
      p:=@Msg;
      //Form1.Comport1.WriteStr('!');
      //Form1.Comport1.Write(p,UartPacketSize);
      For i := 0 to UartPacketSize -1 Do Begin
      Comport1.TransmitChar (char(p^));
      inc(p);


      end;


      {SENDBYTE(33);         //StartByte

      SENDBYTE(Msg.source mod  256);
      SENDBYTE(msg.Source div 256);


      SENDBYTE(Msg.Destination mod 256);
      SENDBYTE(Msg.Destination div 256);




      //fncode
      SENDBYTE(Msg.fncode);
      //length
      SENDBYTE(Msg.length);
      For j := 0 to Msg.length-1 Do
      SENDBYTE(Msg.Data[j] );


      //CRC
      //SENDBYTE(Packet.CRC mod 256);
      //SENDBYTE(Packet.CRC div 256);
       SENDBYTE(msg.flags);   }
end;

procedure TForm1.ComPort1RxChar(Sender: TObject; Count: Integer);
 var
  Str: String;
  i: Integer;

begin
  
for i := 0 to Count-1 Do Begin
  ComPort1.ReadStr(Str, 1);
 // if count > 1 then showmessage('größer '+ inttostr(count));
  Memo1.Text := Memo1.Text + Str;

  Memo1.Perform(EM_LineScroll, 0 , Memo1.Lines.Count-1);

  If (RxBufCount =-1) then Begin
    If str='!' then Begin           //Packet Start Received
     RxBufIndex:=GetFreeRxBuf;
      RxBufCount := 0;
      RxBufPointer:=@RxBuf[RxBufIndex]
    end;
  end else Begin
   RxBufPointer ^ :=ord(Str[1]);
   inc(RxBufPointer);
   inc(RxBufCount);
   If RxBufCount = UartPacketSize  Then Begin     //Packet fertig empfangen

     Myshowmessage(RxBuf[RxBufIndex]);
     RxBuf[RxBufIndex].Ready:= true;
     RxBufIndex:= -1;
     RxBufCount:=-1;
     Listbox1.Items.add('Packet Rec');
   end;


  end;

end;
end;

procedure TForm1.ComPort1AfterOpen(Sender: TObject);
begin
Memo1.Lines.add('Com Connected');
end;

procedure TForm1.ComDataPacket1Packet(Sender: TObject; const Str: string);
begin
showmessage('Packet reseive' + Str);
end;

procedure TForm1.ComDataPacket2Packet(Sender: TObject; const Str: string);
//var
//str:String;
begin
 //ComPort1.ReadStr(Str, Count);

  Memo1.Text := Memo1.Text + Str;
end;

function TForm1.GetFreeRxBuf: integer;
var
N,J:integer;
begin
 N:= -1;
      for j:= 0 to Bufcount -1 do
      begin
        If not RxBuf[j].used then Begin
          N:=j;
          RxBuf[j].used := true;
          break;
        end;

      end;
      If N = -1 then Showmessage('RxBuffer Full');
     result := N;
end;

procedure TForm1.clearbufs;
var
  i: Integer;
begin
For i := 0 to Bufcount -1 Do Begin
  RxBuf[i].used:= false;
  TxBuf[i].used:= false;

  RxBuf[i].ready:= false;
  TxBuf[i].ready:= false;
end;
end;

function TForm1.GetFreeTxBuf: integer;
var
N,J:integer;
begin
 N:= -1;
      for j:= 0 to Bufcount -1 do
      begin
        If not TxBuf[j].used then Begin
          N:=j;
          TxBuf[j].used := true;
          break;
        end;

      end;
      If N = -1 then Showmessage('RxBuffer Full');
     result := N;

end;

procedure TForm1.Button_SendClick(Sender: TObject);
  var
  Str: String;
begin
  Str := Edit_Data.Text;
  
  ComPort1.WriteStr(Str);
end;

procedure TForm1.Myshowmessage(Msg: TPacket);
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
Item.SubItems.add(inttostr(msg.fncode));
Item.SubItems.add(inttostr(msg.length));


For i := 0 to msg.length -1 Do  Begin

    Data:=Data+'#'+(inttostr(msg.Data[i]));
    end;
Item.SubItems.add(Data);

end;

procedure TForm1.Button3Click(Sender: TObject);
begin
ListView1.Clear;
memo1.clear;
end;

procedure TForm1.Button4Click(Sender: TObject);
begin
ComPort1.Open;
end;

procedure TForm1.Button5Click(Sender: TObject);
begin
ComPort1.close;
end;

procedure TForm1.Button6Click(Sender: TObject);
const senderID= 1;
const CommandID=55;
const SendDataID=56;
const Page_size = 128; //Flashpagesize in byte;
var
  i,j: Integer;
  n:Byte;
  Data:DynamicByteArray;
begin
bootloadexit := false;
N:=0;
rsSend(senderID,CommandID,0,0,#1#100); //Select device
resmsg(senderID);
setlength(Data,PAge_size);

For i := 0 to 1 Do begin
  For j := 0 to Page_size -1 Do begin
    Data[j]:= N;
    inc(N);
  end;

  bootProgrammPage(Data,i,page_size);
  if bootloadexit then exit;
end;


//For i:= 0 to 16 Do begin end;


end;

function TForm1.resmsg(address: integer):TPacket;
var
  i: Integer;
  leave: Boolean;
  starttime:Cardinal;
begin
starttime := GetTickCount;
  leave := False;
While not leave do Begin
Application.ProcessMessages;
If gettickcount-starttime > 1500 then
begin
memo1.Lines.add('timeout');
exit;
end; //timeout
For i := 0 to BufCount -1 Do Begin
 if RxBuf[i].ready then Begin
   if RxBuf[i].destination=address then Begin
     result :=RxBuf[i];
     RxBuf[i].ready:=false;
     RxBuf[i].used:=false;
     
     exit;
   end;



 end;
end;
end;
end;

procedure TForm1.ComPort1AfterClose(Sender: TObject);
begin
Memo1.Lines.Add('com closed');
end;

function TForm1.bootProgrammPage(Data: DynamicByteArray; const page,
  pagesize: integer): boolean;
  //pagesize in Byte
const senderID= 1;
const CommandID=55;
const SendDataID=56;
var
tpage:Word;
h,l:Byte;
s:String;
  i,t: Integer;
  j: Integer;
begin
t:= page*pagesize;

h:=t div 256;
l:= t mod 256;
//tpage=page;
rsSend(senderID,CommandID,0,0,#2+char(h)+char(l)); //erase page
resmsg(senderID);
for i:= 0 to (pagesize div 8) -1 do Begin

//setlength(s,8);
s:='';
for j := 0 to 7 do begin
  s:=s+char(Data[i*8+j]);
end;
if bootloadexit then exit;

rsSend(senderID,sendDataID,i*8,0,s); //fill Buff
resmsg(senderID);

end;

rsSend(senderID,CommandID,0,0,#3+char(h)+char(l)); //write page
resmsg(senderID);
end;

procedure TForm1.Button8Click(Sender: TObject);
begin
bootloadexit := true;
end;

end.
