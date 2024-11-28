//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
void __fastcall TForm3::Button1Click(TObject *Sender)
{
  // Получаем фамилию для поиска
 AnsiString surname = Form3->Edit1->Text;

 // Перебираем строки таблицы
 for (int nom = 1; nom < Form2->StringGrid1->RowCount; nom++)
 {
  AnsiString lastName = Form2->StringGrid1->Cells[1][nom];
  // Если фамилия в ячейке содержит искомое значение,
  // то выделяем эту строку в таблице
  if (lastName.Pos(surname) > 0)
  {
	Form2->StringGrid1->Row = nom;
	Form2->StringGrid1->Col = 1;
	break;
  }
 }
 Form2->Show(); // отобразить форму2 (main)
 Form3->Hide(); // скрыть форму3 (добавить)
}
//---------------------------------------------------------------------------
