unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, iSysBusControl, iSysBusConnection, iSysBusLabel, StdCtrls;

type
  TForm1 = class(TForm)
    iSysBusConnection1: TiSysBusConnection;
    iSysBusBusControlLabel1: TiSysBusBusControlLabel;
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

end.
