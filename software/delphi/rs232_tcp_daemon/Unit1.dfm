object Form1: TForm1
  Left = 192
  Top = 107
  Width = 715
  Height = 710
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 56
    Top = 96
    Width = 51
    Height = 13
    Caption = 'Empf'#228'nger'
  end
  object Label1: TLabel
    Left = 56
    Top = 64
    Width = 34
    Height = 13
    Caption = 'Sender'
  end
  object Label3: TLabel
    Left = 56
    Top = 128
    Width = 34
    Height = 13
    Caption = 'fnCode'
  end
  object Button7: TButton
    Left = 56
    Top = 328
    Width = 153
    Height = 25
    Caption = 'Send'
    TabOrder = 0
    OnClick = Button7Click
  end
  object Edit2: TEdit
    Left = 112
    Top = 96
    Width = 81
    Height = 21
    TabOrder = 1
    Text = '15'
  end
  object Edit3: TEdit
    Left = 352
    Top = 152
    Width = 121
    Height = 21
    TabOrder = 2
    Text = '55'
  end
  object Button1: TButton
    Left = 256
    Top = 232
    Width = 75
    Height = 25
    Caption = 'Receive'
    TabOrder = 3
    OnClick = Button1Click
  end
  object ListBox1: TListBox
    Left = 216
    Top = 0
    Width = 121
    Height = 97
    ItemHeight = 13
    TabOrder = 4
  end
  object DeviceBox: TListBox
    Left = 216
    Top = 288
    Width = 121
    Height = 97
    ItemHeight = 13
    TabOrder = 5
  end
  object Button2: TButton
    Left = 264
    Top = 160
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 6
    OnClick = Button2Click
  end
  object Edit1: TEdit
    Left = 112
    Top = 64
    Width = 81
    Height = 21
    TabOrder = 7
    Text = '55'
  end
  object Edit4: TEdit
    Left = 112
    Top = 128
    Width = 81
    Height = 21
    TabOrder = 8
    Text = '31'
  end
  object Memo1: TMemo
    Left = 481
    Top = 0
    Width = 292
    Height = 432
    Align = alRight
    Lines.Strings = (
      'Memo1')
    ScrollBars = ssVertical
    TabOrder = 9
  end
  object Edit_Data: TEdit
    Left = 368
    Top = 56
    Width = 113
    Height = 21
    TabOrder = 10
  end
  object Button_Send: TButton
    Left = 376
    Top = 88
    Width = 75
    Height = 25
    Caption = 'Send'
    Default = True
    TabOrder = 11
    OnClick = Button_SendClick
  end
  object Edit5: TEdit
    Left = 112
    Top = 160
    Width = 121
    Height = 21
    TabOrder = 12
    Text = '1'
  end
  object Edit6: TEdit
    Left = 112
    Top = 192
    Width = 121
    Height = 21
    TabOrder = 13
    Text = '33'
  end
  object ListView1: TListView
    Left = 0
    Top = 432
    Width = 773
    Height = 235
    Align = alBottom
    Columns = <
      item
        Caption = 'Source'
      end
      item
        Caption = 'Destination'
      end
      item
        Caption = 'fnCode'
      end
      item
        Caption = 'length'
      end
      item
        Caption = 'data'
      end>
    TabOrder = 14
    ViewStyle = vsReport
  end
  object Button3: TButton
    Left = 328
    Top = 216
    Width = 75
    Height = 25
    Caption = 'Clear'
    TabOrder = 15
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 384
    Top = 312
    Width = 75
    Height = 25
    Caption = 'OpenCom'
    TabOrder = 16
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 384
    Top = 344
    Width = 75
    Height = 25
    Caption = 'CloseCom'
    TabOrder = 17
    OnClick = Button5Click
  end
  object Edit7: TEdit
    Left = 112
    Top = 224
    Width = 121
    Height = 21
    TabOrder = 18
    Text = '1'
  end
  object Edit8: TEdit
    Left = 112
    Top = 256
    Width = 121
    Height = 21
    TabOrder = 19
    Text = '1'
  end
  object Button6: TButton
    Left = 56
    Top = 360
    Width = 145
    Height = 25
    Caption = 'Bootload'
    TabOrder = 20
    OnClick = Button6Click
  end
  object Button8: TButton
    Left = 56
    Top = 392
    Width = 145
    Height = 25
    Caption = 'abort bootload'
    TabOrder = 21
    OnClick = Button8Click
  end
  object BusTimer: TTimer
    Enabled = False
    OnTimer = BusTimerTimer
    Left = 648
    Top = 8
  end
  object ComPort1: TComPort
    Connected = True
    BaudRate = br4800
    Port = 'COM2'
    Parity.Bits = prNone
    StopBits = sbOneStopBit
    DataBits = dbEight
    Events = [evRxChar, evTxEmpty, evRxFlag, evRing, evBreak, evCTS, evDSR, evError, evRLSD, evRx80Full]
    FlowControl.OutCTSFlow = False
    FlowControl.OutDSRFlow = False
    FlowControl.ControlDTR = dtrDisable
    FlowControl.ControlRTS = rtsDisable
    FlowControl.XonXoffOut = False
    FlowControl.XonXoffIn = False
    OnAfterOpen = ComPort1AfterOpen
    OnAfterClose = ComPort1AfterClose
    OnRxChar = ComPort1RxChar
    Left = 416
    Top = 16
  end
  object IdTCPServer1: TIdTCPServer
    Bindings = <
      item
        IP = '0.0.0.0'
        Port = 338
      end>
    DefaultPort = 338
    OnConnect = IdTCPServer1Connect
    OnExecute = IdTCPServer1Execute
    Left = 8
    Top = 8
  end
  object ServerSocket1: TServerSocket
    Active = True
    Port = 338
    ServerType = stNonBlocking
    OnClientConnect = ServerSocket1ClientConnect
    OnClientRead = ServerSocket1ClientRead
    Left = 48
    Top = 8
  end
end
