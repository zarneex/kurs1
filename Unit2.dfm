object Form2: TForm2
  Left = 0
  Top = 0
  Caption = #1057#1087#1080#1089#1086#1082
  ClientHeight = 608
  ClientWidth = 1122
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  Menu = MainMenu1
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  TextHeight = 15
  object Label1: TLabel
    Left = 501
    Top = 90
    Width = 144
    Height = 15
    Caption = #1057#1087#1080#1089#1086#1082' '#1090#1086#1074#1072#1088#1086#1074' '#1085#1072' '#1089#1082#1083#1072#1076#1077
  end
  object StringGrid1: TStringGrid
    Left = 24
    Top = 128
    Width = 1066
    Height = 281
    Color = clBtnFace
    ColCount = 7
    Ctl3D = True
    DefaultColWidth = 156
    RowCount = 10
    FixedRows = 0
    ParentCtl3D = False
    TabOrder = 0
    OnMouseDown = StringGrid1MouseDown
    OnMouseUp = StringGrid1MouseUp
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 568
    Width = 1122
    Height = 40
    Panels = <>
    ParentColor = True
    SimplePanel = True
    SimpleText = #1055#1088#1086#1075#1088#1072#1084#1084#1072'..'
    OnMouseUp = StatusBar1MouseUp
  end
  object DateTimePicker1: TDateTimePicker
    Left = 10000
    Top = 320
    Width = 186
    Height = 23
    Date = 45624.000000000000000000
    Time = 0.119930567132541900
    TabOrder = 2
    Visible = False
  end
  object MainMenu1: TMainMenu
    Left = 1064
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N2: TMenuItem
        Caption = #1054#1090#1082#1088#1099#1090#1100
        ShortCut = 16449
        OnClick = N2Click
      end
      object N3: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        ShortCut = 16450
        OnClick = N3Click
      end
      object N4: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1082'...'
        ShortCut = 16451
        OnClick = N4Click
      end
      object N5: TMenuItem
        Caption = '--------'
      end
      object N6: TMenuItem
        Caption = #1042#1099#1093#1086#1076
        OnClick = N6Click
      end
      object N46: TMenuItem
        Caption = #1060#1086#1088#1084#1080#1088#1086#1074#1072#1085#1080#1077' '#1089#1087#1080#1089#1082#1072' '#1088#1072#1085#1077#1077' '#1086#1090#1082#1088#1099#1074#1072#1074#1096#1080#1093#1089#1103' '#1092#1072#1081#1083#1086#1074
        OnClick = N46Click
      end
    end
    object N7: TMenuItem
      Caption = #1055#1088#1072#1074#1082#1072
      object N8: TMenuItem
        Caption = #1044#1086#1073#1072#1074#1080#1090#1100
        ShortCut = 16453
        OnClick = N8Click
      end
      object N9: TMenuItem
        Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100
        ShortCut = 16454
        OnClick = N9Click
      end
      object N10: TMenuItem
        Caption = #1059#1076#1072#1083#1080#1090#1100
        ShortCut = 16455
        OnClick = N10Click
      end
    end
    object N11: TMenuItem
      Caption = #1054#1073#1088#1072#1073#1086#1090#1082#1072
      object N12: TMenuItem
        Caption = #1055#1086#1080#1089#1082
        object N18: TMenuItem
          Caption = #1055#1086' '#1083#1102#1073#1086#1084#1091' '#1080#1079' '#1087#1072#1088#1072#1084#1077#1090#1088#1086#1074
          OnClick = N18Click
        end
      end
      object N13: TMenuItem
        Caption = #1057#1086#1088#1090#1080#1088#1086#1074#1082#1072
        object N14: TMenuItem
          Caption = #1055#1086' '#1085#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1102' '#1090#1086#1074#1072#1088#1072
          ShortCut = 16457
          OnClick = N14Click
        end
        object N15: TMenuItem
          Caption = #1055#1086' '#1094#1077#1085#1077
          ShortCut = 16459
          OnClick = N15Click
        end
        object N28: TMenuItem
          Caption = #1055#1086' '#1082#1086#1083#1080#1095#1077#1089#1090#1074#1091
          OnClick = N28Click
        end
        object N29: TMenuItem
          Caption = #1055#1086' '#1089#1088#1086#1082#1091' '#1075#1086#1076#1085#1086#1089#1090#1080
          OnClick = N29Click
        end
        object N30: TMenuItem
          Caption = #1055#1086' '#1076#1072#1090#1077' '#1080#1079#1075#1086#1090#1086#1074#1083#1077#1085#1080#1103
          OnClick = N30Click
        end
        object N21: TMenuItem
          Caption = #1055#1086' '#1076#1072#1090#1077' '#1087#1086#1089#1090#1091#1087#1083#1077#1085#1080#1103' '#1085#1072' '#1089#1082#1083#1072#1076
          OnClick = N21Click
        end
      end
    end
    object N16: TMenuItem
      Caption = #1047#1072#1076#1072#1085#1080#1077
      object N17: TMenuItem
        Caption = #1047#1072#1076#1072#1085#1080#1077
        object N35: TMenuItem
          Caption = #1054#1087#1088#1077#1076#1077#1083#1080#1090#1100' '#1086#1073#1097#1091#1102' '#1089#1090#1086#1080#1084#1086#1089#1090#1100' '#1090#1086#1074#1072#1088#1086#1074
          ShortCut = 16433
          OnClick = N35Click
        end
        object N22: TMenuItem
          Caption = #1054#1090#1086#1073#1088#1072#1079#1080#1090#1100' '#1089#1087#1080#1089#1086#1082' '#1087#1088#1086#1089#1088#1086#1095#1077#1085#1085#1099#1093' '#1090#1086#1074#1072#1088#1086#1074
          ShortCut = 16434
          OnClick = N22Click
        end
        object N23: TMenuItem
          Caption = #1054#1090#1086#1073#1088#1072#1079#1080#1090#1100' '#1089#1087#1080#1089#1086#1082' '#1090#1086#1074#1072#1088#1086#1074' '#1079#1072' '#1086#1087#1088#1077#1076#1077#1083#1077#1085#1085#1099#1081' '#1087#1077#1088#1080#1086#1076
          ShortCut = 16435
          OnClick = N23Click
        end
      end
      object N20: TMenuItem
        Caption = #1055#1086#1089#1090#1072#1085#1086#1074#1082#1072' '#1079#1072#1076#1072#1085#1080#1103
        OnClick = N20Click
      end
    end
    object N45: TMenuItem
      Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
      ShortCut = 16464
      OnClick = N45Click
    end
    object N19: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      ShortCut = 16456
      OnClick = N19Click
    end
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = '*.txt'
    FileName = #1060#1072#1081#1083
    Filter = 'Txt files|*.txt|Any files|*.*'
    InitialDir = 'C:\'#1085#1080#1082#1072'\'#1082#1091#1088#1089#1086#1074#1072#1103' '#1087#1086' '#1087#1088#1086#1075#1088#1072#1084#1084#1080#1088#1086#1074#1072#1085#1080#1102
    Title = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1082'..'
    Left = 984
  end
  object OpenDialog1: TOpenDialog
    Left = 744
  end
  object PopupMenu2: TPopupMenu
    Left = 904
  end
end
