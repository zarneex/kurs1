//---------------------------------------------------------------------------
#include <vcl.h>
#include <vector>  // ���������� vector ��� ������������� std::vector
#include <Vcl.Controls.hpp>
#include <Vcl.Grids.hpp>   // ���������� StringGrid
//#include <SysUtils.hpp>
using namespace std;

#include "Unit4.h"
#include "Unit3.h"
#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
// ����� ���������� ��������� ���� ��� TDateTimePicker
	//DateTimePicker1->Date = Now();  // ������� ���� �� ���������
	//DateTimePicker2->Date = Now();  // ������� ���� �� ���������
}
//---------------------------------------------------------------------------
// ������� ��� �������� ������ � TDateTime � ������ ��������
auto parseDate = [](AnsiString str) -> TDateTime {
	// ����������� ���� � ������, ������� TryStrToDate ������ ������
	// ��������, ���� ���� � ������� "DD.MM.YYYY", ����������� �� � "YYYY-MM-DD"
	str = StringReplace(str, ".", "-", TReplaceFlags() << rfReplaceAll); // �������� ����� �� ������

	TDateTime date;
	if (!TryStrToDate(str, date)) {
		throw Exception("������: �������� ������ ���� - " + str);
	}
	return date;
};



#include <SysUtils.hpp> // ��� StringReplace

void __fastcall TForm4::Button1Click(TObject *Sender)
{
    static bool isFiltered = false; // ���������� ��� ������������ ��������� ����������
    static TStringList *originalRows = nullptr; // ��� �������� �������� �����

    if (!isFiltered) {
        // ��������� �������� ������ � ������ ���
        if (!originalRows) {
            originalRows = new TStringList;
            for (int row = 1; row < Form2->StringGrid1->RowCount; ++row) {
                String rowData = "";
                for (int col = 0; col < Form2->StringGrid1->ColCount; ++col) {
                    rowData += Form2->StringGrid1->Cells[col][row] + "\t";
                }
                originalRows->Add(rowData);
            }
        }

        // ��������� ����������
        TDateTime Date1 = DateTimePicker1->Date;
        TDateTime Date2 = DateTimePicker2->Date;
        String formattedDate1 = Date1.FormatString("yyyy-mm-dd");
        String formattedDate2 = Date2.FormatString("yyyy-mm-dd");

        TStringList *filteredRows = new TStringList;

        try {
            for (int row = 1; row < Form2->StringGrid1->RowCount; ++row) {
                String cellValue = Form2->StringGrid1->Cells[6][row];
                if (formattedDate1 <= cellValue && formattedDate2 >= cellValue) {
                    String rowData = "";
                    for (int col = 0; col < Form2->StringGrid1->ColCount; ++col) {
                        rowData += Form2->StringGrid1->Cells[col][row] + "\t";
                    }
                    filteredRows->Add(rowData);
                }
            }

            Form2->StringGrid1->RowCount = 1; // ������� ������ (����� ���������)

            for (int i = 0; i < filteredRows->Count; ++i) {
                Form2->StringGrid1->RowCount++;
                TStringList *rowData = new TStringList;
                rowData->Delimiter = '\t';
                rowData->DelimitedText = filteredRows->Strings[i];

                for (int col = 0; col < rowData->Count; ++col) {
                    Form2->StringGrid1->Cells[col][Form2->StringGrid1->RowCount - 1] = rowData->Strings[col];
                }
                delete rowData;
            }
        }
        __finally {
            delete filteredRows;
        }

        isFiltered = true; // ������������� ���� ����������
    } else {
        // ��������������� �������� ������
        Form2->StringGrid1->RowCount = 1; // ������� ������ (����� ���������)

        for (int i = 0; i < originalRows->Count; ++i) {
            Form2->StringGrid1->RowCount++;
            TStringList *rowData = new TStringList;
            rowData->Delimiter = '\t';
            rowData->DelimitedText = originalRows->Strings[i];

            for (int col = 0; col < rowData->Count; ++col) {
                Form2->StringGrid1->Cells[col][Form2->StringGrid1->RowCount - 1] = rowData->Strings[col];
            }
            delete rowData;
        }

        isFiltered = false; // ���������� ���� ����������
    }
}




