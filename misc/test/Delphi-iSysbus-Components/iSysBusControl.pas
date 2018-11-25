unit iSysBusControl;

interface

uses
  SysUtils, Classes, Controls, iSysBusConnection;

type
  TiSysBusBusControl = class(TCustomControl)
  private
    FBusID:integer;
    FPort:integer;
    FFunction:integer;
    FCmd:integer;
    FiSysBusConnection:TiSysBusConnection;
  protected
    { Protected declarations }
  public
    { Public declarations }
    constructor Create(AOwner:TComponent); override;
    destructor Destroy; override;
   // procedure Paint; override; abstract;
  published
    { Published declarations }
    property BusID:integer read FBusID write FBusID;
    property Port:integer read FPort write FPort;
    property FnCode:integer read FFunction write FFunction;
    property Cmd:integer read FCmd write FCmd;
    property iSysBusConnection:TiSysBusConnection read FiSysBusConnection write FiSysBusConnection;
  end;

procedure Register;

implementation

procedure Register;
begin
  RegisterComponents('iSysBus', [TiSysBusBusControl]);
end;

{ TiSysBusBusControl }

constructor TiSysBusBusControl.create(AOwner: TComponent);
begin
Inherited Create(AOwner);
end;

destructor TiSysBusBusControl.destroy;
begin
InHerited destroy;
end;

end.
