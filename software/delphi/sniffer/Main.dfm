object Form3: TForm3
  Left = 0
  Top = 0
  Width = 800
  Height = 787
  Caption = 'Form3'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 0
    Top = 511
    Width = 792
    Height = 2
    Cursor = crVSplit
    Align = alBottom
  end
  object Splitter2: TSplitter
    Left = 790
    Top = 0
    Width = 2
    Height = 511
    Align = alRight
  end
  object Label1: TLabel
    Left = 16
    Top = 8
    Width = 33
    Height = 13
    Caption = 'Source'
  end
  object Label2: TLabel
    Left = 16
    Top = 56
    Width = 54
    Height = 13
    Caption = 'Destination'
  end
  object Label3: TLabel
    Left = 16
    Top = 104
    Width = 20
    Height = 13
    Caption = 'Port'
  end
  object Label4: TLabel
    Left = 16
    Top = 152
    Width = 25
    Height = 13
    Caption = 'Flags'
  end
  object Label5: TLabel
    Left = 16
    Top = 208
    Width = 23
    Height = 13
    Caption = 'Data'
  end
  object Label6: TLabel
    Left = 144
    Top = 208
    Width = 27
    Height = 13
    Caption = 'Lenth'
  end
  object Label7: TLabel
    Left = 216
    Top = 72
    Width = 33
    Height = 13
    Caption = 'Ping Id'
  end
  object ListView1: TListView
    Left = 0
    Top = 513
    Width = 792
    Height = 247
    Align = alBottom
    Columns = <
      item
        Caption = 'Source'
      end
      item
        Caption = 'Destination'
      end
      item
        Caption = 'Port'
      end
      item
        Caption = 'Flags'
      end
      item
        Caption = 'Data'
      end>
    TabOrder = 0
    ViewStyle = vsReport
  end
  object Memo1: TMemo
    Left = 454
    Top = 0
    Width = 336
    Height = 511
    Align = alRight
    Lines.Strings = (
      'Memo1')
    TabOrder = 1
  end
  object Button2: TButton
    Left = 152
    Top = 16
    Width = 75
    Height = 25
    Caption = 'send'
    TabOrder = 2
    OnClick = Button2Click
  end
  object EdSource: TEdit
    Left = 16
    Top = 24
    Width = 121
    Height = 21
    TabOrder = 3
    Text = '0'
  end
  object EdDestination: TEdit
    Left = 16
    Top = 72
    Width = 121
    Height = 21
    TabOrder = 4
    Text = '0'
  end
  object EdPort: TEdit
    Left = 16
    Top = 120
    Width = 121
    Height = 21
    TabOrder = 5
    Text = '0'
  end
  object Edit1: TEdit
    Left = 16
    Top = 224
    Width = 121
    Height = 21
    TabOrder = 6
    Text = '0'
  end
  object Edit2: TEdit
    Left = 16
    Top = 256
    Width = 121
    Height = 21
    TabOrder = 7
    Text = '0'
  end
  object Edit3: TEdit
    Left = 16
    Top = 288
    Width = 121
    Height = 21
    TabOrder = 8
    Text = '0'
  end
  object Edit4: TEdit
    Left = 16
    Top = 320
    Width = 121
    Height = 21
    TabOrder = 9
    Text = '0'
  end
  object Edit5: TEdit
    Left = 16
    Top = 352
    Width = 121
    Height = 21
    TabOrder = 10
    Text = '0'
  end
  object Edit6: TEdit
    Left = 16
    Top = 384
    Width = 121
    Height = 21
    TabOrder = 11
    Text = '0'
  end
  object Edit7: TEdit
    Left = 16
    Top = 416
    Width = 121
    Height = 21
    TabOrder = 12
    Text = '0'
  end
  object Edit8: TEdit
    Left = 16
    Top = 448
    Width = 121
    Height = 21
    TabOrder = 13
    Text = '0'
  end
  object EdFlags: TEdit
    Left = 16
    Top = 168
    Width = 121
    Height = 21
    TabOrder = 14
    Text = '0'
  end
  object EdLength: TEdit
    Left = 72
    Top = 200
    Width = 25
    Height = 21
    TabOrder = 15
    Text = '0'
  end
  object ListBox1: TListBox
    Left = 328
    Top = 8
    Width = 121
    Height = 497
    ItemHeight = 13
    TabOrder = 16
    OnClick = ListBox1Click
  end
  object Button3: TButton
    Left = 160
    Top = 344
    Width = 89
    Height = 25
    Caption = 'Add'
    TabOrder = 17
    OnClick = Button3Click
  end
  object Button5: TButton
    Left = 160
    Top = 376
    Width = 89
    Height = 25
    Caption = 'Remove'
    TabOrder = 18
    OnClick = Button5Click
  end
  object Button6: TButton
    Left = 160
    Top = 408
    Width = 89
    Height = 25
    Caption = 'Save to File'
    TabOrder = 19
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 160
    Top = 440
    Width = 89
    Height = 25
    Caption = 'Load From File'
    TabOrder = 20
    OnClick = Button7Click
  end
  object Button10: TButton
    Left = 216
    Top = 112
    Width = 75
    Height = 25
    Caption = 'ping'
    TabOrder = 21
    OnClick = Button10Click
  end
  object Button11: TButton
    Left = 216
    Top = 144
    Width = 73
    Height = 25
    Caption = 'Multi Ping'
    TabOrder = 22
    OnClick = Button11Click
  end
  object Button12: TButton
    Left = 232
    Top = 480
    Width = 75
    Height = 25
    Caption = 'Clear'
    TabOrder = 23
    OnClick = Button12Click
  end
  object EdId: TEdit
    Left = 216
    Top = 88
    Width = 73
    Height = 21
    TabOrder = 24
    Text = '30'
  end
  object isysBusConnection_TCP1: TisysBusConnection_TCP
    OnReceive = isysBusConnection_rs2321Receive
    Host = '127.0.0.1'
    Port = 0
    Left = 256
    Top = 16
  end
end
