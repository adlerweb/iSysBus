object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 425
  ClientWidth = 525
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnCreate = FormCreate
  DesignSize = (
    525
    425)
  PixelsPerInch = 96
  TextHeight = 13
  object active: TSpeedButton
    Left = 124
    Top = 404
    Width = 129
    Height = 21
    AllowAllUp = True
    Anchors = [akLeft, akBottom]
    GroupIndex = 1
    Caption = 'active'
    OnClick = activeClick
  end
  object memo: TMemo
    Left = 4
    Top = 4
    Width = 513
    Height = 398
    Anchors = [akLeft, akTop, akRight, akBottom]
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 0
  end
  object cport: TComPort
    BaudRate = br115200
    Port = 'COM7'
    Parity.Bits = prNone
    StopBits = sbOneStopBit
    DataBits = dbEight
    Events = [evRxChar, evTxEmpty]
    Buffer.InputSize = 2048
    Buffer.OutputSize = 2048
    FlowControl.OutCTSFlow = False
    FlowControl.OutDSRFlow = False
    FlowControl.ControlDTR = dtrDisable
    FlowControl.ControlRTS = rtsDisable
    FlowControl.XonXoffOut = False
    FlowControl.XonXoffIn = False
    OnRxChar = cportRxChar
    OnTxEmpty = cportTxEmpty
    Left = 392
    Top = 60
  end
end
