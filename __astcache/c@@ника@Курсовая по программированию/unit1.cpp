//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"      //для связи двух форм
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{

	int nm = Form2->StringGrid1->RowCount-1;



	Form2->Show();			//чтобы форма2 (main) отобразилась
	Form1->Hide(); 		// закрыть первую форму (добавить)
	Form2->StringGrid1->Cells[1][nm]=Edit1->Text;  //строка-столбец
	Form2->StringGrid1->Cells[2][nm]=Edit2->Text;
	Form2->StringGrid1->Cells[3][nm]=Edit3->Text;
	Form2->StringGrid1->Cells[4][nm]=Edit4->Text;
	Form2->StringGrid1->Cells[5][nm]=Edit5->Text;
	Form2->StringGrid1->Cells[6][nm]=Edit6->Text;
	Form2->StringGrid1->Cells[7][nm]=Edit7->Text;
	Form2->StringGrid1->Cells[8][nm]=Edit8->Text;
	Form2->StringGrid1->Cells[9][nm]=Edit9->Text;

	++Form2->StringGrid1->RowCount;
}
//---------------------------------------------------------------------------
