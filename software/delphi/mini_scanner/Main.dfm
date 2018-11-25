object Form1: TForm1
  Left = 0
  Top = 0
  Width = 434
  Height = 320
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object ListBox1: TListBox
    Left = 8
    Top = 8
    Width = 121
    Height = 273
    ItemHeight = 13
    TabOrder = 0
  end
  object Button1: TButton
    Left = 224
    Top = 48
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 1
    OnClick = Button1Click
  end
  object isysBusConnection_TCP1: TisysBusConnection_TCP
    OnReceive = isysBusConnection_TCP1Receive
    Port = 0
    Left = 280
    Top = 112
  end
end
