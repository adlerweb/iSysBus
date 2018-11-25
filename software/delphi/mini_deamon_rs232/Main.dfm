object Form2: TForm2
  Left = 0
  Top = 0
  Width = 236
  Height = 114
  Caption = 'Form2'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 96
    Top = 16
    Width = 17
    Height = 13
    Caption = 'RX:'
  end
  object LaRx: TLabel
    Left = 136
    Top = 16
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Label3: TLabel
    Left = 96
    Top = 32
    Width = 16
    Height = 13
    Caption = 'TX:'
  end
  object LaTx: TLabel
    Left = 136
    Top = 32
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Label5: TLabel
    Left = 96
    Top = 48
    Width = 36
    Height = 13
    Caption = 'Clients:'
  end
  object LaClients: TLabel
    Left = 136
    Top = 48
    Width = 6
    Height = 13
    Caption = '0'
  end
  object Button1: TButton
    Left = 8
    Top = 16
    Width = 75
    Height = 25
    Caption = 'Settings'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 48
    Width = 75
    Height = 25
    Caption = 'Clear Log'
    TabOrder = 1
  end
  object ComPort1: TComPort
    BaudRate = br38400
    Port = 'COM1'
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
    OnRxChar = ComPort1RxChar
    Left = 176
    Top = 8
  end
  object ServerSocket1: TServerSocket
    Active = True
    Port = 338
    ServerType = stNonBlocking
    OnClientConnect = ServerSocket1ClientConnect
    OnClientRead = ServerSocket1ClientRead
    Left = 176
    Top = 40
  end
end
