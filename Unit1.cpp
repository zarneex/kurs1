//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
  #include <System.RegularExpressions.hpp>
#include <System.StrUtils.hpp>
#include "Unit1.h"
#include "Unit2.h"      //для связи двух форм
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
bool rad = false;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int nm = 0;
    if (Form2->Caption == "Добавление") {
        // Оставляем nm без изменений
    } else {
        int selectedRow = Form2->StringGrid1->Selection.Top;
        if (selectedRow >= 1 && selectedRow < Form2->StringGrid1->RowCount) {
            nm = selectedRow;
        } else {
            ShowMessage("Не выбрана строка для редактирования.");
            return;
        }
    }

    // Проверка корректности введенных данных
    if (Edit1->Text.IsEmpty() || Edit2->Text.IsEmpty() || Edit3->Text.IsEmpty() ||
        Edit4->Text.IsEmpty() || Edit5->Text.IsEmpty() || Edit6->Text.IsEmpty()) {
        ShowMessage("Необходимо заполнить все поля.");
        return;
    }

    // Проверка, что в поле "Цена" введено положительное число с десятичной точкой
    double price;
    if (!TryStrToFloat(Edit2->Text, price) || price <= 0) {
        ShowMessage("Введите положительное число в поле 'Цена'.");
        return;
    }

    // Проверка, что в поле "Количество" введено целое положительное число
    int quantity;
    if (!TryStrToInt(Edit3->Text, quantity) || quantity <= 0) {
        ShowMessage("Введите положительное целое число в поле 'Количество'.");
        return;
    }

    // Проверка, что в поле "Срок годности" введено положительное число или -1 (для отсутствия срока)
    int shelfLife;
    if (!TryStrToInt(Edit4->Text, shelfLife) || (shelfLife < -1)) {
        ShowMessage("Введите положительное целое число или -1 в поле 'Срок годности'.");
        return;
    }

    // Проверка, что в полях "Дата изготовления" и "Дата поступления на склад" введены корректные даты
    try {
        TDateTime manufactureDate = StrToDate(Edit5->Text);
        TDateTime stockDate = StrToDate(Edit6->Text);

        if (manufactureDate > stockDate) {
            ShowMessage("Дата изготовления не может быть позже даты поступления на склад.");
            return;
        }
    } catch (...) {
        ShowMessage("Введите корректные даты в поля 'Дата изготовления' и 'Дата поступления на склад'.");
        return;
    }

    // Все проверки пройдены успешно, сохраняем данные в таблицу
    Form2->StringGrid1->Cells[1][nm] = Edit1->Text; // Наименование товара
    Form2->StringGrid1->Cells[2][nm] = Edit2->Text; // Цена
    Form2->StringGrid1->Cells[3][nm] = Edit3->Text; // Количество
    Form2->StringGrid1->Cells[4][nm] = Edit4->Text; // Срок годности
    Form2->StringGrid1->Cells[5][nm] = Edit5->Text; // Дата изготовления
    Form2->StringGrid1->Cells[6][nm] = Edit6->Text; // Дата поступления на склад

    // Закрываем форму Form1
    Close();
}



//--
//---------------------------------------------------------------------------
//Переводить фокус на следующий компонент---------------------------------------------------------------------------

void __fastcall TForm1::Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if(Key == VK_RETURN) Edit2->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if(Key == VK_RETURN) Edit3->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if(Key == VK_RETURN) Edit4->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit4KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
		if(Key == VK_RETURN) Edit5->SetFocus();
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Edit5KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if(Key == VK_RETURN) Edit6->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit6KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if(Key == VK_RETURN) Button1->SetFocus();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Edit1Exit(TObject *Sender)
{
	String text = Edit1->Text.Trim();
	if (!text.IsEmpty()) {
		text = text.SubString(1, 1).UpperCase() + text.SubString(2, text.Length() - 1).LowerCase();
		Edit1->Text = text;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2Exit(TObject *Sender)
{
	String text = Edit2->Text.Trim();
	if (!text.IsEmpty()) {
		text = text.SubString(1, 1).UpperCase() + text.SubString(2, text.Length() - 1).LowerCase();
		Edit2->Text = text;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3Exit(TObject *Sender)
{
	String text = Edit3->Text.Trim();
	if (!text.IsEmpty()) {
		text = text.SubString(1, 1).UpperCase() + text.SubString(2, text.Length() - 1).LowerCase();
		Edit3->Text = text;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit6Exit(TObject *Sender)
{
	String text = Edit6->Text.Trim();
	if (!text.IsEmpty()) {
		text = text.SubString(1, 1).UpperCase() + text.SubString(2, text.Length() - 1).LowerCase();
		Edit6->Text = text;
	}
}
//---------------------------------------------------------------------------


