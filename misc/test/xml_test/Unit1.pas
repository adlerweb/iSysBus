unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, xmldom, XMLIntf, Borland.Vcl.ClrXmlDom, System.ComponentModel,
  Borland.Vcl.XmlDoc, Borland.Vcl.StdCtrls, System.Xml.Serialization, System.IO;

type
TMensch = class(TObject)
  public
    Alter: Byte;
    Name: String;
  end;
  TForm1 = class(TForm)
    Button1: TButton;
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.nfm}

procedure TForm1.Button1Click(Sender: TObject);
var Mensch: TMensch;
      Ser: XmlSerializer;
      Writer: StreamWriter;
begin
  Mensch := TMensch.Create;
  Mensch.Alter := 15;
  Mensch.Name := 'fido';

  Writer := StreamWriter.Create('Mensch.xml');
  Ser := XmlSerializer.Create(typeof(TMensch));
  Ser.Serialize(Writer, Mensch);
  Writer.Close;
end;

end.
