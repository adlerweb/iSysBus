unit isbm_Main;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, Menus, ActnList, ImgList, ComCtrls, JvSimpleXML, isb_Types, StdCtrls,
  isb_Conn;

type
  TForm_Main = class(TForm)
    ImageList: TImageList;
    ActionList: TActionList;
    Action_File_New: TAction;
    Action_File_Open: TAction;
    Action_File_Save: TAction;
    Action_File_SaveAs: TAction;
    Action_File_Close: TAction;
    Action_File_Print: TAction;
    Action_File_Quit: TAction;
    Action_Data_Project: TAction;
    Action_Data_Customer: TAction;
    Action_Data_Programer: TAction;
    Action_Modul_Device: TAction;
    Action_Modul_Sniffer: TAction;
    Action_Modul_Visu: TAction;
    Action_Modul_Test: TAction;
    Action_iSysBus_Connect: TAction;
    Action_iSysBus_Disconnect: TAction;
    Action_iSysBus_Properties: TAction;
    MainMenu: TMainMenu;
    mnu_File: TMenuItem;
    mnu_File_New: TMenuItem;
    mnu_File_Open: TMenuItem;
    mnu_File_Save: TMenuItem;
    mnu_File_SaveAs: TMenuItem;
    mnu_File_Close: TMenuItem;
    mnu_File_N1: TMenuItem;
    mnu_File_Print: TMenuItem;
    mnu_File_N2: TMenuItem;
    mnu_File_Quit: TMenuItem;
    mnu_Data: TMenuItem;
    mnu_Data_Project: TMenuItem;
    mnu_Data_Customer: TMenuItem;
    mnu_Data_Programer: TMenuItem;
    mnu_Modul: TMenuItem;
    mnu_Modul_Device: TMenuItem;
    mnu_Modul_Sniffer: TMenuItem;
    mnu_Modul_Visu: TMenuItem;
    mnu_Modul_Test: TMenuItem;
    mnu_iSysBus: TMenuItem;
    mnu_iSysBus_Connect: TMenuItem;
    mnu_iSysBus_Disconnect: TMenuItem;
    mnu_iSysBus_Properties: TMenuItem;
    mnu_Info: TMenuItem;
    StatusBar: TStatusBar;
    GroupBox_Project: TGroupBox;
    Label_Name: TLabel;
    Label_Address: TLabel;
    Label_Postalcode: TLabel;
    Label_City: TLabel;
    Text_Name: TLabel;
    Text_Address: TLabel;
    Text_Postalcode: TLabel;
    Text_City: TLabel;
    GroupBox_State: TGroupBox;
    Label_Version: TLabel;
    Label_Created: TLabel;
    Label_Modified: TLabel;
    Text_Version: TLabel;
    Text_Created: TLabel;
    Text_Modified: TLabel;
    Label_Tel: TLabel;
    Label_Fax: TLabel;
    Text_Tel: TLabel;
    Text_Fax: TLabel;
    procedure Action_Data_ProjectExecute(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure FormCloseQuery(Sender: TObject; var CanClose: Boolean);
    procedure FormResize(Sender: TObject);
    procedure RxMsg(Msg: Tisb_Msg);
    procedure TxMsg(Msg: Tisb_Msg);
    procedure Action_File_NewExecute(Sender: TObject);
    procedure Action_File_OpenExecute(Sender: TObject);
    procedure Action_File_SaveExecute(Sender: TObject);
    procedure Action_File_SaveAsExecute(Sender: TObject);
    procedure Action_File_CloseExecute(Sender: TObject);
    procedure Action_File_PrintExecute(Sender: TObject);
    procedure Action_File_QuitExecute(Sender: TObject);
    procedure Action_Data_CustomerExecute(Sender: TObject);
    procedure Action_Data_ProgramerExecute(Sender: TObject);
    procedure Action_Modul_DeviceExecute(Sender: TObject);
    procedure Action_Modul_SnifferExecute(Sender: TObject);
    procedure Action_Modul_VisuExecute(Sender: TObject);
    procedure Action_Modul_TestExecute(Sender: TObject);
    procedure Action_iSysBus_ConnectExecute(Sender: TObject);
    procedure Action_iSysBus_DisconnectExecute(Sender: TObject);
    procedure Action_iSysBus_PropertiesExecute(Sender: TObject);
  private
    { Private-Deklarationen }
    procedure Refresh();
    function DataXML_New(): Boolean;
    function DataXML_SelectLoad(): Boolean;
    function DataXML_Load(const AFile: String): Boolean;
    function DataXML_Close(): Boolean;
    function DataXML_Save(): Boolean;
    function DataXML_SaveAs(): Boolean;
  public
    { Public-Deklarationen }
    ConfXML: TJvSimpleXML;
    DataXML_File: String;
    DataXML_Directory: String;
    DataXML: TJvSimpleXML;
    DataXML_IsChanged: Boolean;
  end;

var
  Form_Main: TForm_Main;

implementation

uses
  isbm_Data_Project, isbm_Data_Customer, isbm_Data_Programer,
  isbm_Device, isbm_Sniffer, isbm_Visu, isbm_Test;

var
  isb_Conn: Tisb_Conn;

{$R *.dfm}

procedure TForm_Main.FormShow(Sender: TObject);
begin
  with ConfXML.Root
  do
    begin
      if not Assigned(Items.ItemNamed['Form_Main'])
      then Items.Add('Form_Main');
      with Items.ItemNamed['Form_Main']
      do
        begin
          if not Assigned(Properties.ItemNamed['width'])
          then Width := 800
          else Width := Properties.ItemNamed['width'].IntValue;
          if not Assigned(Properties.ItemNamed['height'])
          then Height := 600
          else Height := Properties.ItemNamed['height'].IntValue;
          if not Assigned(Properties.ItemNamed['left'])
          then Left := (Screen.WorkAreaWidth - Width) div 2
          else Left := Properties.ItemNamed['left'].IntValue;
          if not Assigned(Properties.ItemNamed['top'])
          then Top := (Screen.WorkAreaHeight - Height) div 2
          else Top := Properties.ItemNamed['top'].IntValue;
        end;
    end;
//  Action_File_NewExecute(Sender);
end;

procedure TForm_Main.FormClose(Sender: TObject; var Action: TCloseAction);
begin
  with ConfXML.Root
  do
    begin
      if not Assigned(Items.ItemNamed['Form_Main'])
      then Items.Add('Form_Main');
      with Items.ItemNamed['Form_Main']
      do
        begin
          if not Assigned(Properties.ItemNamed['left'])
          then Properties.Add('left', 0);
          Properties.ItemNamed['left'].IntValue := Left;
          if not Assigned(Properties.ItemNamed['top'])
          then Properties.Add('top', 0);
          Properties.ItemNamed['top'].IntValue := Top;
          if not Assigned(Properties.ItemNamed['width'])
          then Properties.Add('width', 0);
          Properties.ItemNamed['width'].IntValue := Width;
          if not Assigned(Properties.ItemNamed['height'])
          then Properties.Add('height', 0);
          Properties.ItemNamed['height'].IntValue := Height;
        end;
    end;
end;

procedure TForm_Main.FormCloseQuery(Sender: TObject; var CanClose: Boolean);
begin
  if(DataXML_IsChanged = false)
  then
    begin
      CanClose := true;
    end
  else
    begin
      case MessageDlg('Möchten Sie die Änderungen an Ihrem Projekt speichern?',
        mtWarning, [mbYes, mbNo, mbCancel], 0) of
        mrYes:
          begin
            if(DataXML_Save() = true)
            then
              begin
                CanClose := true;
              end
            else
              begin
                CanClose := false;
              end;
          end;
        mrNo:
          begin
            CanClose := true;
          end;
        mrCancel:
          begin
            CanClose := false;
          end;
      end;
    end;
end;

procedure TForm_Main.FormResize(Sender: TObject);
begin
  //
end;

procedure TForm_Main.RxMsg(Msg: Tisb_Msg);
begin
  Form_Device.RxMsg(Msg);
  Form_Sniffer.RxMsg(Msg);
  Form_Visu.RxMsg(Msg);
  Form_Test.RxMsg(Msg);
end;

procedure TForm_Main.TxMsg(Msg: Tisb_Msg);
begin
// Diese Funktion empfängt Nachrichten von den Modulen
// und leitet diese über die iSysBus_Connection weiter.
  if Assigned(isb_Conn) then
  begin
    if isb_Conn.IsConnected = true then
    begin
      isb_Conn.Send(Msg);
    end;
  end;
  RxMsg(Msg);
end;

procedure TForm_Main.Action_File_NewExecute(Sender: TObject);
begin
  if(DataXML_IsChanged = false)
  then
    begin
      DataXML_New();
    end
  else
    begin
      case MessageDlg('Möchten Sie die Änderungen an Ihrem Projekt speichern?',
        mtWarning, [mbYes, mbNo, mbCancel], 0) of
        mrYes:
          begin
            if(DataXML_Save() = true)
            then
              begin
                DataXML_New();
              end;
          end;
        mrNo:
          begin
            DataXML_New();
          end;
        mrCancel:
          begin
          end;
        else
          begin
          end;
      end;
    end;
end;

procedure TForm_Main.Action_File_OpenExecute(Sender: TObject);
begin
  if(DataXML_IsChanged = false)
  then
    begin
      DataXML_SelectLoad();
    end
  else
    begin
      case MessageDlg('Möchten Sie die Änderungen an Ihrem Projekt speichern?',
        mtWarning, [mbYes, mbNo, mbCancel], 0) of
        mrYes:
          begin
            if(DataXML_Save() = true)
            then
              begin
                DataXML_SelectLoad();
              end;
          end;
        mrNo:
          begin
            DataXML_SelectLoad();
          end;
        mrCancel:
          begin
          end;
        else
          begin
          end;
      end;
    end;
end;

procedure TForm_Main.Action_File_SaveExecute(Sender: TObject);
begin
  DataXML_Save();
end;

procedure TForm_Main.Action_File_SaveAsExecute(Sender: TObject);
begin
  DataXML_SaveAs();
end;

procedure TForm_Main.Action_File_CloseExecute(Sender: TObject);
begin
  if(DataXML_IsChanged = false)
  then
    begin
      DataXML_Close();
    end
  else
    begin
      case MessageDlg('Möchten Sie die Änderungen an Ihrem Projekt speichern?',
        mtWarning, [mbYes, mbNo, mbCancel], 0) of
        mrYes:
          begin
            if(DataXML_Save() = true)
            then
              begin
                DataXML_Close();
              end;
          end;
        mrNo:
          begin
            DataXML_Close();
          end;
        mrCancel:
          begin
          end;
        else
          begin
          end;
      end;
    end;
end;

procedure TForm_Main.Action_File_PrintExecute(Sender: TObject);
begin
  ShowMessage('Feature not implementet.');
end;

procedure TForm_Main.Action_File_QuitExecute(Sender: TObject);
begin
  Close();
end;

procedure TForm_Main.Action_Data_ProjectExecute(Sender: TObject);
begin
  Form_Project.ShowModal();
  Refresh();
end;

procedure TForm_Main.Action_Data_CustomerExecute(Sender: TObject);
begin
  Form_Customer.ShowModal();
  Refresh();
end;

procedure TForm_Main.Action_Data_ProgramerExecute(Sender: TObject);
begin
  Form_Programer.ShowModal();
  Refresh();
end;

procedure TForm_Main.Action_Modul_DeviceExecute(Sender: TObject);
begin
  Form_Device.Show();
end;

procedure TForm_Main.Action_Modul_SnifferExecute(Sender: TObject);
begin
  Form_Sniffer.Show();
end;

procedure TForm_Main.Action_Modul_VisuExecute(Sender: TObject);
begin
  Form_Visu.Show();
end;

procedure TForm_Main.Action_Modul_TestExecute(Sender: TObject);
begin
  Form_Test.Show();
end;

procedure TForm_Main.Action_iSysBus_ConnectExecute(Sender: TObject);
begin
  // Verbindung zum iSysBus herstellen.
  if not Assigned(isb_Conn) then
  begin
    isb_Conn := Tisb_Conn.CreateConn('RS232');
    isb_Conn.Settings['comport'] := 'COM1';
    isb_Conn.Settings['baudrate'] := '115200';
    isb_Conn.Settings['databits'] := '8';
    isb_Conn.Settings['stopbits'] := '1';
    isb_Conn.Settings['parity'] := 'N';
    isb_Conn.Settings['handshake'] := 'N';
    isb_Conn.OnReceive := RxMsg;
    if(isb_Conn.Connect() = true) then
    begin
      ShowMessage('Connect');
    end;
  end;
end;

procedure TForm_Main.Action_iSysBus_DisconnectExecute(Sender: TObject);
begin
  // Verbindung zum iSysBus trennen.
  if Assigned(isb_Conn) then
  begin
    if (isb_Conn.IsConnected = true) then
      isb_Conn.Disconnect();
    isb_Conn.Free();
    isb_Conn := nil;
  end;
end;

procedure TForm_Main.Action_iSysBus_PropertiesExecute(Sender: TObject);
begin
  //
end;

procedure TForm_Main.Refresh();
begin
  with DataXML.Root
  do
    begin
      if not Assigned(Items.ItemNamed['Global'])
      then Items.Add('Global');
      with Items.ItemNamed['Global']
      do
        begin
          if not Assigned(Items.ItemNamed['ProjectData'])
          then Items.Add('ProjectData');
          with Items.ItemNamed['ProjectData']
          do
            begin
              if not Assigned(Items.ItemNamed['Name'])
              then Text_Name.Caption := ''
              else Text_Name.Caption := Items.ItemNamed['Name'].Value;
              if not Assigned(Items.ItemNamed['Address'])
              then Text_Address.Caption := ''
              else Text_Address.Caption := Items.ItemNamed['Address'].Value;
              if not Assigned(Items.ItemNamed['Postalcode'])
              then Text_Postalcode.Caption := ''
              else Text_Postalcode.Caption := Items.ItemNamed['Postalcode'].Value;
              if not Assigned(Items.ItemNamed['City'])
              then Text_City.Caption := ''
              else Text_City.Caption := Items.ItemNamed['City'].Value;
              if not Assigned(Items.ItemNamed['Tel'])
              then Text_Tel.Caption := ''
              else Text_Tel.Caption := Items.ItemNamed['Tel'].Value;
              if not Assigned(Items.ItemNamed['Fax'])
              then Text_Fax.Caption := ''
              else Text_Fax.Caption := Items.ItemNamed['Fax'].Value;
            end;
          if not Assigned(Items.ItemNamed['Version'])
          then Text_Version.Caption := ''
          else Text_Version.Caption := Items.ItemNamed['Version'].Value;
          if not Assigned(Items.ItemNamed['CreationDate'])
          then Text_Created.Caption := ''
          else Text_Created.Caption := Items.ItemNamed['CreationDate'].Value;
          if not Assigned(Items.ItemNamed['LastChange'])
          then Text_Modified.Caption := ''
          else Text_Modified.Caption := Items.ItemNamed['LastChange'].Value;
        end;
    end;
end;

function TForm_Main.DataXML_New(): Boolean;
begin
  if(Assigned(DataXML) = true)
  then
    begin
      DataXML.Free();
    end;
  DataXML := TJvSimpleXML.Create(nil);
  DataXML.Root.Name := 'BusConfig';
  DataXML_IsChanged := False;
  DataXML_File := '';
  StatusBar.Panels.Items[0].Text := 'Neu';
  StatusBar.Panels.Items[1].Text := '-';
  StatusBar.Panels.Items[2].Text := 'Neu (noch nicht gespeichert)';
Refresh();
  Result := True;
end;

function TForm_Main.DataXML_SelectLoad(): Boolean;
var
  OpenDialog: TOpenDialog;
begin
  Result := False;
  OpenDialog := TOpenDialog.Create(nil);
  OpenDialog.InitialDir := DataXML_Directory;
  OpenDialog.Filter := 'iSysBus-Dateien (*.isb)|*.isb';
  OpenDialog.DefaultExt := 'isb';
  if OpenDialog.Execute
  then
    begin
      if FileExists(OpenDialog.FileName)
      then
        begin
          Result := DataXML_Load(OpenDialog.FileName);
        end;
    end;
  OpenDialog.Free;
end;

function TForm_Main.DataXML_Load(const AFile: String): Boolean;
begin
  Result := False;
  if(FileExists(AFile) = true)
  then
    begin
      if(Assigned(DataXML) = true)
      then
        begin
          DataXML.Free();
        end;
      DataXML := TJvSimpleXML.Create(nil);
      DataXML.LoadFromFile(AFile);
      if(DataXML.Root.Name = 'BusConfig')
      then
        begin
          DataXML_IsChanged := False;
          DataXML_File := AFile;
          StatusBar.Panels.Items[0].Text := '-';
          StatusBar.Panels.Items[1].Text := '-';
          StatusBar.Panels.Items[2].Text := AFile;
Refresh();
          Result := True;
        end;
    end;
end;

function TForm_Main.DataXML_Close(): Boolean;
begin
  if(Assigned(DataXML) = true)
  then
    begin
      DataXML.Free();
    end;
  DataXML := nil;
  DataXML_IsChanged := False;
  DataXML_File := '';
  StatusBar.Panels.Items[0].Text := '-';
  StatusBar.Panels.Items[1].Text := '-';
  StatusBar.Panels.Items[2].Text := '-';
Refresh();
  Result := True;
end;

function TForm_Main.DataXML_Save(): Boolean;
begin
  Result := False;
  if(DataXML_File <> '')
  then
    begin
      if(FileExists(DataXML_File) = true)
      then
        begin
          DataXML.SaveToFile(DataXML_File);
          DataXML_IsChanged := False;
          StatusBar.Panels.Items[0].Text := '-';
          StatusBar.Panels.Items[1].Text := '-';
          StatusBar.Panels.Items[2].Text := DataXML_File;
          Result := True;
        end;
    end;
end;

function TForm_Main.DataXML_SaveAs(): Boolean;
var
  SaveDialog: TSaveDialog;
begin
  Result := False;
  SaveDialog := TSaveDialog.Create(nil);
  SaveDialog.InitialDir := DataXML_Directory;
  SaveDialog.Filter := 'iSysBus-Dateien (*.isb)|*.isb';
  SaveDialog.DefaultExt := 'isb';
  if SaveDialog.Execute
  then
    begin
      if not FileExists(SaveDialog.FileName)
      then
        begin
          DataXML.SaveToFile(SaveDialog.FileName);
          DataXML_IsChanged := False;
          DataXML_File := SaveDialog.FileName;
          StatusBar.Panels.Items[0].Text := '-';
          StatusBar.Panels.Items[1].Text := '-';
          StatusBar.Panels.Items[2].Text := SaveDialog.FileName;
          Result := True;
        end
      else
        begin
          case MessageDlg('Die von Ihnen ausgewählte Datei existiert bereits.\nSoll sie überschrieben werden?' , mtConfirmation, [mbYes, mbNo], 0) of
            mrYes:
              begin
                DataXML.SaveToFile(SaveDialog.FileName);
                DataXML_IsChanged := False;
                DataXML_File := SaveDialog.FileName;
                StatusBar.Panels.Items[0].Text := '-';
                StatusBar.Panels.Items[1].Text := '-';
                StatusBar.Panels.Items[2].Text := SaveDialog.FileName;
                Result := True;
              end;
            mrNo:
              begin
                MessageDlg('Der Vorgang speichern wurde abgebrochen.' , mtError, [mbOk], 0);
                Result := False;
              end;
          end
        end;
    end;
  SaveDialog.Free;
end;

end.
