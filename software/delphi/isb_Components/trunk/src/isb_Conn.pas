unit isb_Conn;

interface

uses
  SysUtils, Classes, Dialogs, isb_Types;

type
  Tisb_ReceiveEvent = procedure(Msg: Tisb_Msg) of object;

type
  Tisb_Conn = class(TComponent)
  private
    { Private-Deklarationen }
    FOnReceive: Tisb_ReceiveEvent;
  protected
    { Protected-Deklarationen }
    function GetConnected: Boolean; virtual; abstract;
    function GetSetting(Name: String): String; virtual; abstract;
    procedure SetSetting(Name: String; Value: String); virtual; abstract;
  public
    class function CreateConn(ConnType: String): Tisb_Conn;
    { Public-Deklarationen }
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function Connect(): boolean; virtual; abstract;
    function Disconnect(): boolean; virtual; abstract;
    property IsConnected: Boolean read GetConnected;
    procedure Send(Msg: Tisb_Msg); virtual;
    property Settings[Name: String]: String read GetSetting write SetSetting;
  published
    { Published-Deklarationen }
    property OnReceive: Tisb_ReceiveEvent read FOnReceive write FOnReceive;
  end;

procedure Register;

implementation

uses
  isb_ConnRs232;

type
  TconnClass = class of Tisb_Conn;
  TconnType = record
    Name: String;
    FClass: TconnClass;
  end;

const
  connTypes: array[0..0] of TconnType = (
    (Name: 'RS232'; FClass: Tisb_ConnRs232)
  );

procedure Register;
begin
  RegisterComponents('iSysBus', [Tisb_Conn]);
end;

constructor Tisb_Conn.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
end;

destructor Tisb_Conn.Destroy;
begin
  inherited Destroy;
end;

class function Tisb_Conn.CreateConn(ConnType: String): Tisb_Conn;
var
  i: Integer;
begin
  Result := nil;
  for i := 0 to High(connTypes) do
    if connTypes[i].Name = ConnType then
      break;
  if i < Length(connTypes) then
    Result := connTypes[i].FClass.Create(nil);
end;

procedure Tisb_Conn.Send(Msg: Tisb_Msg);
begin
  OnReceive(Msg);
end;

end.

