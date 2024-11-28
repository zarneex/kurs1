//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
  #include <System.RegularExpressions.hpp>
#include <System.StrUtils.hpp>
#include "Unit1.h"
#include "Unit2.h"      //��� ����� ���� ����
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
    if (Form2->Caption == "����������") {
        // ��������� nm ��� ���������
    } else {
        int selectedRow = Form2->StringGrid1->Selection.Top;
        if (selectedRow >= 1 && selectedRow < Form2->StringGrid1->RowCount) {
            nm = selectedRow;
        } else {
            ShowMessage("�� ������� ������ ��� ��������������.");
            return;
        }
    }

    // �������� ������������ ��������� ������
    if (Edit1->Text.IsEmpty() || Edit2->Text.IsEmpty() || Edit3->Text.IsEmpty() ||
        Edit4->Text.IsEmpty() || Edit5->Text.IsEmpty() || Edit6->Text.IsEmpty()) {
        ShowMessage("���������� ��������� ��� ����.");
        return;
    }

    // ��������, ��� � ���� "����" ������� ������������� ����� � ���������� ������
    double price;
    if (!TryStrToFloat(Edit2->Text, price) || price <= 0) {
        ShowMessage("������� ������������� ����� � ���� '����'.");
        return;
    }

    // ��������, ��� � ���� "����������" ������� ����� ������������� �����
    int quantity;
    if (!TryStrToInt(Edit3->Text, quantity) || quantity <= 0) {
        ShowMessage("������� ������������� ����� ����� � ���� '����������'.");
        return;
    }

    // ��������, ��� � ���� "���� ��������" ������� ������������� ����� ��� -1 (��� ���������� �����)
    int shelfLife;
    if (!TryStrToInt(Edit4->Text, shelfLife) || (shelfLife < -1)) {
        ShowMessage("������� ������������� ����� ����� ��� -1 � ���� '���� ��������'.");
        return;
    }

    // ��������, ��� � ����� "���� ������������" � "���� ����������� �� �����" ������� ���������� ����
    try {
        TDateTime manufactureDate = StrToDate(Edit5->Text);
        TDateTime stockDate = StrToDate(Edit6->Text);

        if (manufactureDate > stockDate) {
            ShowMessage("���� ������������ �� ����� ���� ����� ���� ����������� �� �����.");
            return;
        }
    } catch (...) {
        ShowMessage("������� ���������� ���� � ���� '���� ������������' � '���� ����������� �� �����'.");
        return;
    }

    // ��� �������� �������� �������, ��������� ������ � �������
    Form2->StringGrid1->Cells[1][nm] = Edit1->Text; // ������������ ������
    Form2->StringGrid1->Cells[2][nm] = Edit2->Text; // ����
    Form2->StringGrid1->Cells[3][nm] = Edit3->Text; // ����������
    Form2->StringGrid1->Cells[4][nm] = Edit4->Text; // ���� ��������
    Form2->StringGrid1->Cells[5][nm] = Edit5->Text; // ���� ������������
    Form2->StringGrid1->Cells[6][nm] = Edit6->Text; // ���� ����������� �� �����

    // ��������� ����� Form1
    Close();
}



//--
//---------------------------------------------------------------------------
//���������� ����� �� ��������� ���������---------------------------------------------------------------------------

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


