object Form3: TForm3
  Left = 0
  Top = 0
  Caption = #1055#1086#1080#1089#1082' '#1074' '#1089#1087#1080#1089#1082#1077
  ClientHeight = 218
  ClientWidth = 454
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Label1: TLabel
    Left = 160
    Top = 27
    Width = 97
    Height = 15
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1079#1085#1072#1095#1077#1085#1080#1077
  end
  object Edit1: TEdit
    Left = 104
    Top = 56
    Width = 201
    Height = 23
    TabOrder = 0
    OnExit = Edit1Exit
    OnKeyDown = Edit1KeyDown
  end
  object Button6: TButton
    Left = 88
    Top = 120
    Width = 233
    Height = 76
    Caption = #1048#1089#1082#1072#1090#1100
    TabOrder = 1
    WordWrap = True
    OnClick = Button6Click
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = '*.txt'
    FileName = #1060#1072#1081#1083
    Filter = 'Txt files|*.txt|Any files|*.*'
    InitialDir = 
      'C:\Users\'#1040#1088#1089#1077#1085#1080#1081'\Desktop\'#1050#1091#1088#1089#1086#1074#1072#1103' '#1087#1086' '#1087#1088#1086#1075#1088#1072#1084#1084#1080#1088#1086#1074#1072#1085#1080#1102'\'#1050#1091#1088#1089#1086#1074#1072#1103' '#1087 +
      #1086' '#1087#1088#1086#1075#1088#1072#1084#1084#1080#1088#1086#1074#1072#1085#1080#1102
    Title = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1082'..'
    Left = 395
    Top = 8
  end
end
