program isb_Manager;

uses
  Forms,
  Dialogs,
  SysUtils,
  JvSimpleXml,
  isbm_Main in 'src\isbm_Main.pas' {Form_Main},
  isbm_Device in 'src\isbm_Device\isbm_Device.pas' {Form_Device},
  isbm_Sniffer in 'src\isbm_Sniffer\isbm_Sniffer.pas' {Form_Sniffer},
  isbm_Visu in 'src\isbm_Visu\isbm_Visu.pas' {Form_Visu},
  isbm_Options in 'src\isbm_Options\isbm_Options.pas' {Form_Options},
  isbm_SplashScreen in 'src\isbm_SplashScreen.pas' {Form_SplashScreen},
  isbm_Test in 'src\isbm_Test\isbm_Test.pas' {Form_Test},
  isbm_Data_Programer in 'src\isbm_Data\isbm_Data_Programer.pas' {Form_Programer},
  isbm_Data_Customer in 'src\isbm_Data\isbm_Data_Customer.pas' {Form_Customer},
  isbm_Data_Project in 'src\isbm_Data\isbm_Data_Project.pas' {Form_Project};

{$R *.res}

var
  // Conf
  ConfXML: TJvSimpleXml;
  ConfXML_File: string;

begin
  Application.Initialize;
  Application.Title := 'iSysBus-Manager';
  // Form_SplashScreen
  Form_SplashScreen := TForm_SplashScreen.Create(nil);
  Form_SplashScreen.ProgressBar.Max := 100;
  Form_SplashScreen.ProgressBar.Position := 0;
  Form_SplashScreen.Show();
  Form_SplashScreen.Update();
  Form_SplashScreen.ProgressBar.Position :=
    Form_SplashScreen.ProgressBar.Position + 2;
  // ConfFile
  ConfXML_File := ExtractFilePath(ParamStr(0)) + 'isb_Manager.xml';
  ConfXml := TJvSimpleXML.Create(nil);
  if FileExists(ConfXML_File)
  then
    begin
      ConfXml.LoadFromFile(ConfXML_File);
      if not(ConfXml.Root.Name = 'Manager')
      then
        begin
          ConfXml.Free;
          ConfXml := TJvSimpleXML.Create(nil);
          ConfXml.Root.Name := 'Manager';
        end;
    end
  else ConfXml.Root.Name := 'Manager';
  // Wartezeit
  sleep(500);
  Form_SplashScreen.ProgressBar.Position := Form_SplashScreen.ProgressBar.Position + 2;
  // Form_Main
  Application.CreateForm(TForm_Main, Form_Main);
  Form_Main.ConfXML := ConfXML;
  Form_SplashScreen.ProgressBar.Position := Form_SplashScreen.ProgressBar.Position + 2;
  // Form_Project
  Application.CreateForm(TForm_Project, Form_Project);
  Form_SplashScreen.ProgressBar.Position := Form_SplashScreen.ProgressBar.Position + 2;
  // Form_Customer
  Application.CreateForm(TForm_Customer, Form_Customer);
  Form_SplashScreen.ProgressBar.Position := Form_SplashScreen.ProgressBar.Position + 2;
  // Form_Programer
  Application.CreateForm(TForm_Programer, Form_Programer);
  Form_SplashScreen.ProgressBar.Position := Form_SplashScreen.ProgressBar.Position + 2;
  // Form_Device
  Application.CreateForm(TForm_Device, Form_Device);
  Form_Device.ConfXML := ConfXML;
  Form_SplashScreen.ProgressBar.Position := Form_SplashScreen.ProgressBar.Position + 2;
  // Form_Sniffer
  Application.CreateForm(TForm_Sniffer, Form_Sniffer);
  Form_Sniffer.ConfXML := ConfXML;
  Form_SplashScreen.ProgressBar.Position := Form_SplashScreen.ProgressBar.Position + 2;
  // Form_Visu
  Application.CreateForm(TForm_Visu, Form_Visu);
  Form_Visu.ConfXML := ConfXML;
  Form_SplashScreen.ProgressBar.Position := Form_SplashScreen.ProgressBar.Position + 2;
  // Form_Test
  Application.CreateForm(TForm_Test, Form_Test);
  Form_Test.ConfXML := ConfXML;
  Form_SplashScreen.ProgressBar.Position := Form_SplashScreen.ProgressBar.Position + 2;
  // Form_Options
  Application.CreateForm(TForm_Options, Form_Options);
  Form_Options.ConfXML := ConfXML;
  Form_SplashScreen.ProgressBar.Position := Form_SplashScreen.ProgressBar.Position + 2;
  // Wartezeit
  sleep(500);
  // Form_SplashScreen
  Form_SplashScreen.ProgressBar.Position := 100;
  Form_SplashScreen.Close();
  Application.Run;
  // ConfFile
  ConfXml.SaveToFile(ConfXML_File);
  ConfXml.Free;
end.
