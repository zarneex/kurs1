//---------------------------------------------------------------------------
   #include <Windows.h>
#include <vcl.h>
#pragma hdrstop
#include <Vcl.Dialogs.hpp>
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

//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TForm3::Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)
{
	if (Key == VK_RETURN)
    {
        Key = 0; // �������� ��������� ������� Enter � ���� �����
        Button6->SetFocus(); // ��������� ����� �� ������ Button6
        Button6->Click(); // �������� ������� Click ��� ������ Button6
    }
}


//---------------------------------------------------------------------------

void __fastcall TForm3::Edit1Exit(TObject *Sender)
{   Button6->SetFocus(); // ��������� ����� �� ������ Button6
	String text = Edit1->Text.Trim();
	if (!text.IsEmpty()) {
		text = text.SubString(1, 1).UpperCase() + text.SubString(2, text.Length() - 1).LowerCase();
		Edit1->Text = text;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button6Click(TObject *Sender)
{
    UnicodeString searchStr = Edit1->Text;
    UnicodeString foundStrings; // ���������� ��� ���������� ��������� �����

    for (int i = 1; i < Form2->StringGrid1->RowCount; i++) {
        UnicodeString rowStr = "";
        for (int j = 0; j < Form2->StringGrid1->ColCount; j++) {
            rowStr = rowStr + Form2->StringGrid1->Cells[j][i] + " ";
        }
        rowStr = rowStr.SubString(1, rowStr.Length() - 1);

        if (rowStr.Pos(searchStr) != 0) {
            foundStrings = foundStrings + rowStr + "\n";
        }
    }

   if (!foundStrings.IsEmpty()) {
    int save_result = MessageBoxW(NULL, foundStrings.c_str(), L"������ ��������� ���-�� ������?", MB_YESNO | MB_ICONINFORMATION);
    if (save_result == IDYES) {
        if (SaveDialog1->Execute()) {
				UnicodeString fileName = SaveDialog1->FileName;
			// ��� ��� ���������� ����������� � ��������� ���� (fileName)
			MessageBoxW(NULL, L"��������� �������� � ����", L"���������� �����������", MB_OK | MB_ICONINFORMATION);
        } else {
            MessageBoxW(NULL, L"���� ��� ���������� �� ������", L"���������� �����������", MB_OK | MB_ICONINFORMATION);
        }
    }
} else {
    MessageBoxW(NULL, L"������ �� �������", L"��������� ������", MB_OK | MB_ICONINFORMATION);
}
    //Form3->Close();
}


//---------------------------------------------------------------------------

