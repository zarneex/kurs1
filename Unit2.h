//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.ToolWin.hpp>
#include <System.ImageList.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Dialogs.hpp>
#include <string>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	TMenuItem *N9;
	TMenuItem *N10;
	TMenuItem *N11;
	TMenuItem *N12;
	TMenuItem *N13;
	TMenuItem *N14;
	TMenuItem *N15;
	TMenuItem *N16;
	TMenuItem *N17;
	TLabel *Label1;
	TStringGrid *StringGrid1;
	TMenuItem *N18;
	TMenuItem *N28;
	TMenuItem *N29;
	TMenuItem *N30;
	TMenuItem *N35;
	TStatusBar *StatusBar1;

	TSaveDialog *SaveDialog1;
	TMenuItem *N45;
	TMenuItem *N20;
	TMenuItem *N19;
	TMenuItem *N46;
	TOpenDialog *OpenDialog1;
	TMenuItem *N21;
	TPopupMenu *PopupMenu2;
	TMenuItem *N22;
	TMenuItem *N23;
	TDateTimePicker *DateTimePicker1;

	void __fastcall FormCreate(TObject *Sender);
	void __fastcall N8Click(TObject *Sender);
	void __fastcall StringGrid1SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect);
	void __fastcall N9Click(TObject *Sender);
	void __fastcall N10Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall N18Click(TObject *Sender);




	void __fastcall N6Click(TObject *Sender);
	void __fastcall N35Click(TObject *Sender);


	void __fastcall N14Click(TObject *Sender);
	void __fastcall N15Click(TObject *Sender);
	void __fastcall N28Click(TObject *Sender);
	void __fastcall N29Click(TObject *Sender);


	void __fastcall N30Click(TObject *Sender);
	void __fastcall N33Click(TObject *Sender);

	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);

	void __fastcall PopupMenu1Popup(TObject *Sender);
	void __fastcall StringGrid1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall PopupMenu2Popup(TObject *Sender);
	void __fastcall StringGrid1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);

	void __fastcall StatusBar1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);

	void __fastcall N45Click(TObject *Sender);
	void __fastcall N20Click(TObject *Sender);
	void __fastcall N19Click(TObject *Sender);
	void __fastcall N46Click(TObject *Sender);
	 void __fastcall SaveToFile(AnsiString dataToSave);
	void __fastcall N21Click(TObject *Sender);

	    void __fastcall SortTable(int column);
	void __fastcall N23Click(TObject *Sender);
	void __fastcall N22Click(TObject *Sender);


private:            // User declarations
TDateTime startDate;  // ��������� ����
	TDateTime endDate;    // �������� ����

public:	  	// User declarations
	__fastcall TForm2(TComponent* Owner);
	void __fastcall SetDateRange(TDateTime start, TDateTime end);  // ��������� ��������� ���
    void __fastcall FilterItemsByDate();  // ���������� ������� �� �����

};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;

//---------------------------------------------------------------------------
#endif
