unit isb_Item;

interface

uses
  SysUtils, Classes, Controls, Dialogs, JvSimpleXml,
  isb_Types;

type
  Tisb_TxMsg = procedure(Msg: Tisb_Msg) of object;

type
  Tisb_Item = class(TCustomControl)
  private
    { Private-Deklarationen }
    FId: integer;
    FParentId: integer;
    FTyp: string;
    Xml: TJvSimpleXmlElem;
//    FIsysbusNodeId: integer;
//    FIsysbusModulId: integer;
//    FIsysbusIndexId: integer;
//    FOnTx: Tisb_TxMsg;
  protected
    { Protected-Deklarationen }
  public
    { Public-Deklarationen }
    constructor Create(AOwner: TComponent); override;
    destructor Destroy(); override;
//    procedure Paint(); virtual;
    function LoadXml(AXml: TJvSimpleXmlElem): Boolean; virtual;
    function SaveXml(): Boolean; virtual;
    procedure OnRxMsg(Msg: Tisb_Msg); virtual;
  published
    { Published-Deklarationen }
    property PopupMenu;
    property OnClick;
    property OnDblClick;
    property OnMouseDown;
    property OnMouseMove;
    property OnMouseUp;
    property Id: integer read FId write FId;
    property ParentId: integer read FParentId write FParentId;
    property Typ: string read FTyp write FTyp;
//    property ItemXml: TJvSimpleXmlProps read FItemXml write FItemXml;
//    property IsysbusNodeId: integer read FIsysbusNodeId write FIsysbusNodeId;
//    property IsysbusModulId: integer read FIsysbusModulId write FIsysbusModulId;
//    property IsysbusIndexId: integer read FIsysbusIndexId write FIsysbusIndexId;
//    property OnTx: Tisb_TxMsg read FOnTx write FOnTx;
  end;

procedure Register;

implementation

procedure Register;
begin
  RegisterComponents('iSysBus', [Tisb_Item]);
end;

{ Tisb_Item }

constructor Tisb_Item.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
//  ItemId := 0;
//  ItemParentId := 0;
//  ItemTyp := 'Tisb_Item';
//  ItemXml := nil;
//  IsysbusNodeId := 0;
//  IsysbusModulId := 0;
//  IsysbusIndexId := 0;
end;

destructor Tisb_Item.Destroy();
begin
  inherited Destroy;
end;

//procedure Tisb_Item.Paint();
//begin
//  ;
//end;

function Tisb_Item.LoadXml(AXml: TJvSimpleXmlElem): Boolean;
begin
  Result := false;
  if Assigned(AXml) then
  begin
    Xml := AXml;
    // PosX
    if not Assigned(Xml.Items.ItemNamed['PosX']) then
    begin
      Xml.Items.Add('PosX', '0');
    end;
    Left := Xml.Items.ItemNamed['PosX'].IntValue;
    // PosY
    if not Assigned(Xml.Items.ItemNamed['PosY']) then
    begin
      Xml.Items.Add('PosY', '0');
    end;
    Top := Xml.Items.ItemNamed['PosY'].IntValue;
    // Width
    if not Assigned(Xml.Items.ItemNamed['Width']) then
    begin
      Xml.Items.Add('Width', '20');
    end;
    Width := Xml.Items.ItemNamed['Width'].IntValue;
    // Height
    if not Assigned(Xml.Items.ItemNamed['Height']) then
    begin
      Xml.Items.Add('Height', '20');
    end;
    Height := Xml.Items.ItemNamed['Height'].IntValue;
    Result := true;
  end;
end;

function Tisb_Item.SaveXml(): Boolean;
begin
  Result := false;
  if Assigned(Xml) then
  begin
    // PosX
    if not Assigned(Xml.Items.ItemNamed['PosX']) then
    begin
      Xml.Items.Add('PosX', '0');
    end;
    Xml.Items.ItemNamed['PosX'].Value := IntToStr(Left);
    // PosY
    if not Assigned(Xml.Items.ItemNamed['PosY']) then
    begin
      Xml.Items.Add('PosY', '0');
    end;
    Xml.Items.ItemNamed['PosY'].Value := IntToStr(Top);
    // Width
    if not Assigned(Xml.Items.ItemNamed['Width']) then
    begin
      Xml.Items.Add('Width', '20');
    end;
    Xml.Items.ItemNamed['Width'].Value := IntToStr(Width);
    // Height
    if not Assigned(Xml.Items.ItemNamed['Height']) then
    begin
      Xml.Items.Add('Height', '20');
    end;
    Xml.Items.ItemNamed['Height'].Value := IntToStr(Height);
    Result := true;
  end;
end;

procedure Tisb_Item.OnRxMsg(Msg: Tisb_Msg);
begin
  ;
end;

end.
