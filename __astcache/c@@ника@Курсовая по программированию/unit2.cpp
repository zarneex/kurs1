//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormCreate(TObject *Sender)
{
	StringGrid1->Cells[0][0]="№"; //колонка-строка
	StringGrid1->Cells[1][0]="Фамилия";
	StringGrid1->Cells[2][0]="Имя";
	StringGrid1->Cells[3][0]="Отчество";
	StringGrid1->Cells[4][0]="Год рождения";
	StringGrid1->Cells[5][0]="Пол";
	StringGrid1->Cells[6][0]="Адрес местожительства (город)";
	StringGrid1->Cells[7][0]="Образование";
	StringGrid1->Cells[8][0]="Кол-во детей";
	StringGrid1->Cells[9][0]="Место работы";
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N8Click(TObject *Sender)
{
	Form2->Caption = "Добавление";
	Form2->Show();
}
//---------------------------------------------------------------------------

