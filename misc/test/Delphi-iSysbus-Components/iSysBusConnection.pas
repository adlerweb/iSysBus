unit iSysBusConnection;

interface

uses
  SysUtils,
  Classes,
  iSysBusTypes;

type


  TiSysBusConnection = class(TComponent)
  private
    { Private declarations }

  protected
    { Protected declarations }
  public
    { Public declarations }
    function getvalue(BusID, Port, Cmd, FnCode:integer):TiSysBusValue; virtual; abstract;
    procedure setvalue(BusID, Port, Cmd, FnCode: integer; Value: TiSysBusValue); virtual; abstract;
  published
    { Published declarations }
  end;

procedure Register;

implementation

procedure Register;
begin
  RegisterComponents('iSysBus', [TiSysBusConnection]);
end;

end.
