unit iSysBusLabel;

interface

uses
  SysUtils, Classes, Controls, iSysBusControl, stdCtrls;

type
  TiSysBusBusControlLabel = class(TiSysBusBusControl)
  private
    { Private declarations }
    FLabel: TLabel;
  protected
    { Protected declarations }
  public
    { Public declarations }
    constructor Create(AOwner:TComponent); override;
    destructor Destroy; override;
    procedure Paint; override;
  published
    { Published declarations }
  end;

procedure Register;

implementation

procedure Register;
begin
  RegisterComponents('iSysBus', [TiSysBusBusControlLabel]);
end;

{ TiSysBusBusControl1 }

constructor TiSysBusBusControlLabel.create(AOwner: TComponent);
begin
inherited Create(AOwner);
FLabel:=TLabel.Create(Self);
FLabel.Parent:=Self;
FLabel.caption := 'Hallo iSysBus';
end;

destructor TiSysBusBusControlLabel.destroy;
begin

FLabel.destroy;
inherited destroy;
end;

procedure TiSysBusBusControlLabel.Paint;
begin
  inherited;
//FLabel.Paint;
self.Canvas.TextOut(0,20,'Hello World');
end;

end.
