//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>
#include <Windows.h>
#include <DateUtils.hpp>  //��� ����������� �������� ����
#include <Vcl.Dialogs.hpp>
using namespace std;
#include "Unit2.h"
#include "Unit1.h"
#include "Unit3.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
extern bool rad;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent *Owner)
: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void writeToFile(String fileName) {
	ofstream myfile; // �������� ������� myfile ������ ofstream
	myfile.open(fileName.c_str(), ios::app); // �������� ����� ��� ������ � ������ ����������
	if (myfile.is_open()) // �������� ��������� �������� �����
	{
		ifstream checkFile(fileName.c_str());
		bool isFirstLine = checkFile.peek() == ifstream::traits_type::eof(); // ���������, ������ �� ����
		if (isFirstLine) // ���� ���� ������
	{
		myfile << "�" << '\t' << "�������" << '\t' << "���" << '\t' << "��������" << '\t'
			<< "���-�� ������" << '\t' << "��� ������" << '\t' << "����� �������" <<  '\n';
	}

	// ���������� �������� �� Edit'��, �������� �� ��������� ���������
	myfile << AnsiString(Form1->Edit1->Text).c_str() << '\t';
	myfile << AnsiString(Form1->Edit2->Text).c_str() << '\t';
	myfile << AnsiString(Form1->Edit3->Text).c_str() << '\t';
	myfile << AnsiString(Form1->Edit4->Text).c_str() << '\t';
	myfile << AnsiString(Form1->Edit5->Text).c_str() << '\t';
	myfile << AnsiString(Form1->Edit6->Text).c_str() <<  '\n';


	myfile.close(); // �������� �����
	ShowMessage("������ ������� �������� � ����.");
	}
	else
	{
	ShowMessage("�� ������ �������� ������ � ����.");
	}

}

void readFromFile()
{
	ifstream myfile;
	myfile.open("example.txt");
	if (myfile.is_open())
	{
		string line;
		int row = 0;
		bool firstLine = true;
		while (getline(myfile, line))
		{
			stringstream ss(line);
			int col = 0;
			string value;
			while (getline(ss, value, ','))
			{
				if (!firstLine) // ���� ��� �� ������ ������ �����
				{
					Form2->StringGrid1->Cells[col][row] = value.c_str(); // ������ �������� � ��������������� ������, ������� �� ������ ������
				}
				else // ���� ��� ������ ������ �����
				{
					// ��������� ������ ������ ������
					string expectedHeader = "�,������� ������ �������,��� ������ �������,�������� ������ �������,���-�� ���������(��),���� �����,����� �������";
					if (value != expectedHeader)
					{
						// ������������ ������ ������ ������, ������� �� �������
						ShowMessage("������������ ������ ������ ������ �����.");
						myfile.close();
						return;
					}
					firstLine = false; // ���������� ���� ������ ������ � �������� false
				}
				col++;
			}
			if (!firstLine) // ���� ��� �� ������ ������ �����
			{
				row++; // ��������� ������ ������ ��� ������ � �������
			}
		}
		myfile.close();
		ShowMessage("������ ������� ��������� �� �����.");
	}
	else
	{
		ShowMessage("�� ������� ������� ���� ��� ���� �� ����������.");
	}
}



void __fastcall TForm2::FormCreate(TObject *Sender)
{
StringGrid1->Cells[0][0] = "�"; //�������-������
StringGrid1->Cells[1][0] = "������������ ������";
StringGrid1->Cells[2][0] = "����";
StringGrid1->Cells[3][0] = "����������";
StringGrid1->Cells[4][0] = "���� ��������";
StringGrid1->Cells[5][0] = "���� ������������";
StringGrid1->Cells[6][0] = "���� �����������.";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N8Click(TObject *Sender)
{
    bool fileOpened = false; // ���������� ��� �������� �������� �����

    // �������� �������� �����
    if (Form2->Caption != "����������") {
        fileOpened = true;
    }

    if (StringGrid1->RowCount > 1 && !fileOpened) {
        // ���� ���� ������ � ���� �� ������, ��������� ������ � �����
        int newRow = StringGrid1->RowCount; // ����� ������ ����� ��������� � �����
        StringGrid1->RowCount++; // ����������� ���������� ����� � ������� �� 1

        // ��������� ����� ������ ������� ����������
        StringGrid1->Cells[0][newRow] = IntToStr(newRow - 1); // ����� ������ (�������� �����)
        StringGrid1->Cells[1][newRow] = ""; // ������������ ������
        StringGrid1->Cells[2][newRow] = ""; // ����
        StringGrid1->Cells[3][newRow] = ""; // ����������
        StringGrid1->Cells[4][newRow] = ""; // ���� ��������
        StringGrid1->Cells[5][newRow] = ""; // ���� ������������
        StringGrid1->Cells[6][newRow] = ""; // ���� �����������

        // ������������� ��������� �� ����� ������
        StringGrid1->Row = newRow;
        StringGrid1->Col = 1;

        StatusBar1->SimpleText = "��������� ����� ������ � �����";
    } else {
        // ���� ������� ������ ��� ���� ������, ��������� ������ � ������
        StringGrid1->RowCount++; // ����������� ���������� ����� �� 1

        // �������� ������ ����
        for (int i = StringGrid1->RowCount - 1; i > 1; i--) {
            for (int j = 0; j < StringGrid1->ColCount; j++) {
                StringGrid1->Cells[j][i] = StringGrid1->Cells[j][i - 1];
            }
        }

        // ��������� ����� ������ ������
        StringGrid1->Cells[0][1] = "1"; // ����� ������
        StringGrid1->Cells[1][1] = ""; // ������������ ������
        StringGrid1->Cells[2][1] = ""; // ����
        StringGrid1->Cells[3][1] = ""; // ����������
        StringGrid1->Cells[4][1] = ""; // ���� ��������
        StringGrid1->Cells[5][1] = ""; // ���� ������������
        StringGrid1->Cells[6][1] = ""; // ���� �����������

        // ������������� ��������� �� ����� ������
        StringGrid1->Row = 1;
        StringGrid1->Col = 1;

        // ��������� ������ �����
        for (int i = 1; i < StringGrid1->RowCount; i++) {
            StringGrid1->Cells[0][i] = IntToStr(i);
        }

        StatusBar1->SimpleText = "��������� ����� ������ � ������";
    }

	// ������� ���� ����� � ������ �����, ���� ��� ������� � ��������
    Form1->Edit1->Clear();
    Form1->Edit2->Clear();
    Form1->Edit3->Clear();
    Form1->Edit4->Clear();
    Form1->Edit5->Clear();
    Form1->Edit6->Clear();
    Form1->Show();
}




//---------------------------------------------------------------------------

void __fastcall TForm2::StringGrid1SelectCell(TObject *Sender, int ACol, int ARow, bool &CanSelect)
{
	int nom = ARow;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N9Click(TObject *Sender)
{
	// ���������, ��� ������� �����-�� ������
	if (StringGrid1->Selection.Top > 0) {
		// �������� ������ ��������� ������
		int nom = StringGrid1->Selection.Top;
		Form1->Button1->Caption = "��������������";
		Form1->Caption = "��������������";
		Form1->Edit1->Text = Form2->StringGrid1->Cells[1][nom];
		Form1->Edit2->Text = Form2->StringGrid1->Cells[2][nom];
		Form1->Edit3->Text = Form2->StringGrid1->Cells[3][nom];
		Form1->Edit4->Text = Form2->StringGrid1->Cells[4][nom];
		Form1->Edit5->Text = Form2->StringGrid1->Cells[5][nom];
		Form1->Edit6->Text = Form2->StringGrid1->Cells[6][nom];
		Form1->Show();
		StatusBar1->SimpleText = "��������� �������������� ������";
	}
	else {
		StatusBar1->SimpleText = "�� ������� ������ ��� ��������������";
	}

}

//---------------------------------------------------------------------------

void __fastcall TForm2::N10Click(TObject *Sender)
{
	int Top = StringGrid1->Selection.Top;
	if (MessageDlg("�� ������������� ������ ������� ������ " + IntToStr(Top) + " ?", mtConfirmation,
		TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
	{
		// ������� ��������� ������
		for (int i = Top; i < StringGrid1->RowCount - 1; ++i)
		{
			for (int j = 0; j < StringGrid1->ColCount; ++j)
			{
				StringGrid1->Cells[j][i] = StringGrid1->Cells[j][i + 1];
			}
		}
		StringGrid1->RowCount--;
		for (int i = 1; i < StringGrid1->RowCount-1; i++)
{
	StringGrid1->Rows[i]->Strings[0] = IntToStr(i);
}


		StatusBar1->SimpleText = "��������� �������� ��������� ������";
	}
	
}


//---------------------------------------------------------------------------



void __fastcall TForm2::N2Click(TObject *Sender)
{
	TOpenDialog *OpenDialog = new TOpenDialog(this);
	OpenDialog->Title = "�������� ����";
	OpenDialog->Filter = "��������� ����� (*.txt)|*.txt";

	if (OpenDialog->Execute()) // ���� ������������ ������ ����
	{
		// �������� ���������� ����� ��� ������
		ifstream myfile;
		myfile.open(OpenDialog->FileName.c_str());
		if (myfile.is_open()) // �������� ��������� �������� �����
		{
			string line;
			int row = 0;
			bool firstLine = true;

			while (getline(myfile, line)) // ������ ����� �� �����
			{
				if (firstLine) // ���� ��� ������ ������ �����
				{
					// ��������� ������ ������ ������
					string expectedHeader = "�,������������ ������,����,����������,���� ��������,���� ������������,���� ����������� �� �����";
					if (line != expectedHeader)
					{
						// ������������ ������ ������ ������, ������� �� �������
						ShowMessage("������������ ������ ������ ������ �����.");
						myfile.close();
						return;
					}

					stringstream ss(line);
					int col = 0;
					string value;
					while (getline(ss, value, ',')) // ���������� ������ �� ������ �� �������
					{
						Form2->StringGrid1->Cells[col][row] = String(value.c_str()); // ������ �������� � ��������������� ������
						col++;
					}
					firstLine = false; // ���������� ���� ������ ������ � �������� false
				}
				else // ���� ��� �� ������ ������ �����
				{
					// ������� ������ �������� ������ � ����� ������, ���� �� ����
					if (!line.empty() && line[line.length() - 1] == '\n')
					{
						line.erase(line.length() - 1);
					}

					stringstream ss(line);
					int col = 0;

					string value;
					while (getline(ss, value, ',')) // ���������� ������ �� ������ �� �������
					{
						Form2->StringGrid1->Cells[col][row] = String(value.c_str()); // ������ �������� � ��������������� ������
						col++;
					}
				}
				row++;
			}

			myfile.close(); // �������� �����
			ShowMessage("������ ������� ��������� �� �����.");
		}
		else
		{
			ShowMessage("�� ������� ������� ����.");
		}
	}
	StatusBar1->SimpleText = "��������� �������� �����";
}





//---------------------------------------------------------------------------


void __fastcall TForm2::N4Click(TObject *Sender)
{
	// ������ ���������� �����

	if (SaveDialog1->Execute()) // ���� ������������ ������ ���� ��� ����������
	{
	// �������� ����� ��� ������
	ofstream myfile;
	myfile.open(SaveDialog1->FileName.c_str(), ios::trunc);

	if (myfile.is_open()) // �������� ��������� �������� �����
	{
		// ������ ������ �� ������� � ����
		for (int row = 0; row < StringGrid1->RowCount; row++)
		{
			for (int col = 0; col < StringGrid1->ColCount; col++)
			{
				myfile << AnsiString(StringGrid1->Cells[col][row]).c_str();
				if (col < StringGrid1->ColCount - 1)
				{
					myfile << ",";
				}
			}
			myfile << endl;
		}

		myfile.close(); // �������� �����
		StatusBar1->SimpleText = ("������ ������� ��������� � ����.");
	}
	else
	{
		ShowMessage("�� ������� ��������� ����.");
	}
	}
		 StatusBar1->SimpleText = "��������� ���������� � ��������� ����";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N3Click(TObject *Sender) {
    // ��� ����� ��� ����������
    AnsiString fileName = "example.txt";

    // �������� ����� ��� ������
    ofstream myfile;
    myfile.open(fileName.c_str(), ios::trunc); // �������������� ����

    if (myfile.is_open()) { // �������� ��������� �������� �����
        // ������ ������ �� ������� � ����
        for (int row = 0; row < StringGrid1->RowCount; row++) {
            for (int col = 0; col < StringGrid1->ColCount; col++) {
                myfile << AnsiString(StringGrid1->Cells[col][row]).c_str();
                if (col < StringGrid1->ColCount - 1) { // ����������� ����� ���������
                    myfile << ",";
                }
            }
            myfile << endl; // ������� �� ����� ������
        }

        myfile.close(); // �������� �����
		StatusBar1->SimpleText = ("������ ������� ��������� � ����: " + fileName);
    } else {
        ShowMessage("�� ������� ��������� ����: " + fileName);
    }

    // ���������� �������
    StatusBar1->SimpleText = "������ ��������� � " + fileName;
}


//---------------------------------------------------------------------------


void __fastcall TForm2::N18Click(TObject *Sender)
{
	Form3 = new TForm3(Application);
	Form3->Show();


}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void CheckDataSaved()
{
	bool unsavedData = true;
	if (!unsavedData) { // ���� ������ ���������, �� ������ �� ������
		Application->Terminate();
	}

	int result = MessageBoxW(NULL, L"������ �� ���������. ������ ��������� �� ����� �������?",
		L"��������", MB_YESNOCANCEL | MB_ICONWARNING);

	if (result == IDYES) { // ������������ ����� ��������� ������ ����� �������
		Form2->N4Click(NULL); // ��������� ������ � ����
		Application->Terminate(); // ������� ���������
	} else if (result == IDNO) { // ������������ �� ����� ��������� ������ ����� �������
		Application->Terminate(); // ������� ���������
	} else { // ������������ ������� �������� ���������
		return;
	}
}

void __fastcall TForm2::N6Click(TObject *Sender)
{
	CheckDataSaved();
	Close();
}
//---------------------------------------------------------------------------



void __fastcall TForm2::N35Click(TObject *Sender) {
    double totalCost = 0.0; // ����� ��������� �������

    // ��������� �� ������� �������, ������� �� ������ ������ (������ ������ - �����)
    for (int i = 1; i < StringGrid1->RowCount; i++) {
        // �������� ����
        UnicodeString priceStr = StringGrid1->Cells[2][i].Trim(); // ������� ������ �������
        if (priceStr.IsEmpty()) {
            continue; // ���������� ������, ���� ���� �� �������
        }

        // �������������� ���� � ������ �����������
        priceStr = StringReplace(priceStr, ".", ",", TReplaceFlags() << rfReplaceAll);
        double price = StrToFloatDef(priceStr, -1); // ���� ���� �����������, ������������ -1
        if (price < 0) {
            ShowMessage("������������ �������� ���� � ������ " + IntToStr(i + 1));
            continue;
        }

        // �������� ����������
        UnicodeString quantityStr = StringGrid1->Cells[3][i].Trim(); // ������� ������ �������
        if (quantityStr.IsEmpty()) {
            continue; // ���������� ������, ���� ���������� �� �������
        }

        int quantity = StrToIntDef(quantityStr, -1); // ���� ���������� �����������, ������������ -1
        if (quantity < 0) {
            ShowMessage("������������ �������� ���������� � ������ " + IntToStr(i + 1));
            continue;
        }

        // ����������� ����� ���������
        totalCost += price * quantity;
    }

    // ���������, ����������� �� ���������
    if (totalCost == 0.0) {
        MessageBoxW(NULL, L"������ �� ������� ��� �����������. ��������� �������.", L"������", MB_OK | MB_ICONERROR);
        return;
    }

    // ������� ����������
    UnicodeString message = "����� ��������� �������: " + FloatToStrF(totalCost, ffFixed, 15, 2) + " ���.";
    UnicodeString caption = "���������";
    MessageBoxW(NULL, message.c_str(), caption.c_str(), MB_OK | MB_ICONINFORMATION);

    // ���������� � ������������, ����� �� ��������� ���������� � ����
    int save_result = MessageBoxW(NULL, L"������ ��������� ���������� � ����?", L"���������� �����������", MB_YESNO | MB_ICONINFORMATION);
    if (save_result == IDYES) {
        UnicodeString data_to_save = "����� ��������� �������: " + FloatToStrF(totalCost, ffFixed, 15, 2) + " ���.";
        SaveToFile(data_to_save);
        MessageBoxW(NULL, L"��������� �������� � ����", L"���������� �����������", MB_OK | MB_ICONINFORMATION);
    } else {
        MessageBoxW(NULL, L"��������� �� �������� � ����", L"���������� �����������", MB_OK | MB_ICONINFORMATION);
    }
}


//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
void TForm2::SortTable(int column) {
    Form1->Caption = "����������";

    int rowCount = StringGrid1->RowCount;
    int colCount = StringGrid1->ColCount;

    if (rowCount <= 1) {
        MessageBoxW(NULL, L"������������ ������ ��� ����������.", L"������", MB_OK | MB_ICONERROR);
        return;
    }

    vector<vector<AnsiString>> rows;
    for (int i = 1; i < rowCount; ++i) {
        vector<AnsiString> row;
        for (int j = 0; j < colCount; ++j) {
            row.push_back(StringGrid1->Cells[j][i]);
        }
        rows.push_back(row);
    }

    auto parseNumber = [](AnsiString str) -> double {
        try {
            str = StringReplace(str, ".", ",", TReplaceFlags() << rfReplaceAll);
            return str.ToDouble();
        } catch (...) {
            throw Exception("������: �������� ������ ����� - " + str);
        }
    };

    // ������ ��� ��������� ����
    auto parseDate = [](AnsiString str) -> TDateTime {
        TFormatSettings formatSettings;
        formatSettings.ShortDateFormat = "yyyy-mm-dd";
        formatSettings.DateSeparator = '-';

        TDateTime date;
        if (!TryStrToDate(str, date, formatSettings)) {
            throw Exception("������: �������� ������ ���� - " + str);
        }
        return date;
    };

    try {
        switch (column) {
            case 1:
                sort(rows.begin(), rows.end(), [](const vector<AnsiString>& a, const vector<AnsiString>& b) {
                    return a[1].LowerCase() < b[1].LowerCase();
                });
                break;

            case 2:
                sort(rows.begin(), rows.end(), [&](const vector<AnsiString>& a, const vector<AnsiString>& b) {
                    return parseNumber(a[2]) < parseNumber(b[2]);
                });
                break;

            case 3:
                sort(rows.begin(), rows.end(), [](const vector<AnsiString>& a, const vector<AnsiString>& b) {
                    return a[3].ToInt() < b[3].ToInt();
                });
                break;

            case 4:
                sort(rows.begin(), rows.end(), [](const vector<AnsiString>& a, const vector<AnsiString>& b) {
                    return a[4].ToInt() < b[4].ToInt();
                });
                break;

            case 5:
                sort(rows.begin(), rows.end(), [&](const vector<AnsiString>& a, const vector<AnsiString>& b) {
                    return parseDate(a[5]) < parseDate(b[5]);
                });
                break;

            case 6:
                sort(rows.begin(), rows.end(), [&](const vector<AnsiString>& a, const vector<AnsiString>& b) {
                    return parseDate(a[6]) < parseDate(b[6]);
                });
                break;

            default:
				MessageBoxW(NULL, L"������������ ����� ������� ��� ����������.", L"������", MB_OK | MB_ICONERROR);
                return;
        }
    } catch (Exception& e) {
        MessageBoxW(NULL, e.Message.c_str(), L"������", MB_OK | MB_ICONERROR);
        return;
    }

    for (int i = 1; i <= rows.size(); ++i) {
        for (int j = 0; j < colCount; ++j) {
            StringGrid1->Cells[j][i] = rows[i - 1][j];
        }
    }

	StatusBar1->SimpleText = "���������� ���������.";
}





 //---------------------------------------------------------------------------------------
void __fastcall TForm2::N14Click(TObject *Sender)
{
	   SortTable(1);
}



//---------------------------------------------------------------------------

void __fastcall TForm2::N15Click(TObject *Sender)
{
 SortTable(2);


}
//---------------------------------------------------------------------------

void __fastcall TForm2::N28Click(TObject *Sender)
{
 SortTable(3);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N29Click(TObject *Sender)
{
SortTable(4);
}



//---------------------------------------------------------------------------



void __fastcall TForm2::N30Click(TObject *Sender)
{
SortTable(5);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N33Click(TObject *Sender)
{
SortTable(6);
}
//---------------------------------------------------------------------------



void __fastcall TForm2::FormCloseQuery(TObject *Sender, bool &CanClose)
{
 if (rad)
  {

	switch (MessageDlg("������ ��������� ����?",  mtConfirmation,mbYesNoCancel,0))
	case mrYes:  N4Click(Sender);
	mrNo:   CanClose=true; //Application->Terminate();
  }
}
//---------------------------------------------------------------------------




void __fastcall TForm2::PopupMenu1Popup(TObject *Sender)
{
	// �������� � ��������� ������� ����
TPopupMenu* popupMenu = new TPopupMenu(this);

TMenuItem* itemOpen = new TMenuItem(popupMenu);
itemOpen->Caption = "�������";
itemOpen->OnClick = &N2Click;

TMenuItem* itemSave = new TMenuItem(popupMenu);
itemSave->Caption = "���������";
itemSave->OnClick = &N3Click;

TMenuItem* itemSave2 = new TMenuItem(popupMenu);
itemSave2->Caption = "��������� ���..";
itemSave2->OnClick = &N4Click;

TMenuItem* itemFind = new TMenuItem(popupMenu);
itemFind->Caption = "�����";
itemFind->OnClick = &N18Click;

TMenuItem* itemFam = new TMenuItem(popupMenu);
itemFam->Caption = "���������� �� �������";
itemFam->OnClick = &N14Click;

TMenuItem* itemName = new TMenuItem(popupMenu);
itemName->Caption = "���������� �� �����";
itemName->OnClick = &N15Click;

TMenuItem* itemPart = new TMenuItem(popupMenu);
itemPart->Caption = "���������� �� ��������";
itemPart->OnClick = &N28Click;

TMenuItem* itemYear = new TMenuItem(popupMenu);
itemYear->Caption = "���������� �� ���-�� ������";
itemYear->OnClick = &N29Click;

TMenuItem* itemGender = new TMenuItem(popupMenu);
itemGender->Caption = "���������� �� ���� ������";
itemGender->OnClick = &N30Click;



TMenuItem* itemChild = new TMenuItem(popupMenu);
itemChild->Caption = "���������� �� ������ �������";
itemChild->OnClick = &N21Click;



TMenuItem* itemZad1 = new TMenuItem(popupMenu);
itemZad1->Caption = "����������� ������ ���������� ����";
itemZad1->OnClick = &N35Click;



popupMenu->Items->Add(itemOpen);
popupMenu->Items->Add(itemSave);
popupMenu->Items->Add(itemSave2);
popupMenu->Items->Add(itemFind);
popupMenu->Items->Add(itemFam);
popupMenu->Items->Add(itemName);
popupMenu->Items->Add(itemPart);
popupMenu->Items->Add(itemYear);
popupMenu->Items->Add(itemGender);

popupMenu->Items->Add(itemChild);



popupMenu->Items->Add(itemZad1);


// ���������� ������������ ����
StringGrid1->PopupMenu = popupMenu;
}

void __fastcall TForm2::StringGrid1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y)
{
	TPopupMenu* popupMenu = new TPopupMenu(this);
	if (Button == mbRight) // ���� ������ ������ ������ ����
	{
		popupMenu->Popup(X + StringGrid1->Left, Y + StringGrid1->Top); // ���������� ����������� ���� � ����������� �������
	}
}


void __fastcall TForm2::PopupMenu2Popup(TObject *Sender)
{
TPopupMenu* popupMenu = new TPopupMenu(this);

TMenuItem* itemAdd = new TMenuItem(popupMenu);
itemAdd->Caption = "����������";
itemAdd->OnClick = &N8Click;

TMenuItem* itemEdit = new TMenuItem(popupMenu);
itemEdit->Caption = "��������������";
itemEdit->OnClick = &N9Click;

TMenuItem* itemDelete = new TMenuItem(popupMenu);
itemDelete->Caption = "��������";
itemDelete->OnClick = &N10Click;

popupMenu->Items->Add(itemAdd);
popupMenu->Items->Add(itemEdit);
popupMenu->Items->Add(itemDelete);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::StringGrid1MouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
		if (Button == mbRight) // ���� ������ ������ ������ ����
	{
		int ACol, ARow;
		StringGrid1->MouseToCell(X, Y, ACol, ARow);
		if ((ACol >= 0) && (ARow >= 0)) // ���� ������������ ����� �� ������
		{
			StringGrid1->Col = ACol; // ������������� ��������� �������
			StringGrid1->Row = ARow; // ������������� ��������� ������
			PopupMenu2->Popup(X + StringGrid1->Left, Y + StringGrid1->Top); // ���������� ����������� ���� � ����������� �������
		}
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm2::StatusBar1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
StatusBar1->SimpleText = "������";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N45Click(TObject *Sender)
{
	//� ���������
	String message =  "�������� ������������ ��������: Rad Studio \n"
						"������ ������������ ��������: Embarcadero� C++Builder 12 Version 29.0.53982.0329\n"
					 "���� ��������� ��������� � ���������: 27.11.24\n"
					 "�����: ������ ������\n"
					 "E-mail: 3kavos@gmail.com";

	// ������� ��������� � ������������ �������
	ShowMessage(message);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N20Click(TObject *Sender)
{
	//���������� �������
	String message =  "�������� ���������, ����������� ������ ������������ ������� � ��������� �������, ����������� �� ����� � ��������� ������, ��������� ����� ��������� �������, ���������� �� ������. ��������� �������� ������: ������������ ������, ����, ����������, ���� ��������, ���� ������������, ���� ����������� �� �����.";

	// ������� ��������� � ������������ �������
	ShowMessage(message);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N19Click(TObject *Sender)
{
	//�������
	TFileStream *fileStream = new TFileStream("�������.txt", fmOpenRead);
	try {
		int fileSize = fileStream->Size;
		AnsiString data = "";
		data.SetLength(fileSize);

		// ������ ���������� ����� � �����
		fileStream->Read(data.c_str(), fileSize);

		// ����������� ���������� ����� �� UTF-8 � UnicodeString
		UnicodeString unicodeData = UTF8Decode(data);

		// ������� ���������� ����� �� �����
		ShowMessage(unicodeData);
	} catch(...) {
		ShowMessage("������ ��� ������ �����");
	}

	fileStream->Free();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::N46Click(TObject *Sender)
{
		TStringList *recentFiles = new TStringList;
	recentFiles->LoadFromFile("recent_files.txt"); // �������� ����� ����������� ������

	// ���������� �������� ��������� ����� � ������, ���� ���� ������
	if (OpenDialog1->Execute()) {
		recentFiles->Add(OpenDialog1->FileName);
			recentFiles->SaveToFile("recent_files.txt");
		ShowMessage("������ ����� �������� ������ �������� � ����");
	}
	else {
		ShowMessage("���� �� ������.\n"
				   "������ ��� ���������� ������ ����� �������� ������ � ����.");
	}


	recentFiles->Free();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::SaveToFile(AnsiString dataToSave)
{
	// ������� ���������� ���� ���������� �����
	TSaveDialog *SaveDialog1 = new TSaveDialog(this);
	SaveDialog1->Filter = "��������� ����� (*.txt)|*.txt";

	if (SaveDialog1->Execute())
	{
		// ��������� ���� �� ������
		TStringList *StringList = new TStringList;
		StringList->Add(dataToSave);
		StringList->SaveToFile(SaveDialog1->FileName);
		delete StringList;
	}

	delete SaveDialog1;
}

void __fastcall TForm2::N21Click(TObject *Sender)
{
	SortTable(6);
}
//---------------------------------------------------------------------------
auto parseDate = [](AnsiString str) -> TDateTime {
    TFormatSettings formatSettings;
    formatSettings.DateSeparator = '-'; // ������������� �����������
    formatSettings.ShortDateFormat = "yyyy-mm-dd"; // ��������� ������ ����

    TDateTime date;
    if (!TryStrToDate(str, date, formatSettings)) {
        throw Exception("������: �������� ������ ���� - " + str);
    }
    return date;
};

void __fastcall TForm2::SetDateRange(TDateTime start, TDateTime end)
{
    // ��������� ��������� ����
    startDate = start;
    endDate = end;
}

void __fastcall TForm2::FilterItemsByDate()
{
    // ��������� ���������� �� �����
    for (int i = 1; i < StringGrid1->RowCount; i++) {
        String dateStr = StringGrid1->Cells[6][i];  // �����������, ��� ���� ����������� �� ����� ��������� � 7-� �������

        if (dateStr == "") continue;

		try {
            TDateTime itemDate = StrToDate(dateStr);  // ����������� ������ � ����

			// ���������, ������ �� ���� ������ � ��������� ��������
			if (itemDate >= startDate && itemDate <= endDate) {
				// ����� ������������� ��������� ���
				// ����� �� ������, ��������, �������� ������ ��� ���-�� ���
			}

		} catch (...) {
		}

    }
}

void __fastcall TForm2::N23Click(TObject *Sender)
{
    // ��������� ����� TForm4 ��� ������ ��������� ���
    TForm4 *form4 = new TForm4(this);
    form4->ShowModal();  // ���������� ����� TForm4 � ��������� ������

    // ����� ���� ��� ����� ���������, ��������� ������ �� ���������� ��������� ���
    FilterItemsByDate();
}



void __fastcall TForm2::N22Click(TObject *Sender)
{
    static bool isFiltered = false; // ���� ��������� ����������
    static TStringList *originalRows = nullptr; // ������ ��� ���������� �������� �����

    TMenuItem *menuItem = dynamic_cast<TMenuItem *>(Sender);
    if (menuItem) {
        menuItem->Checked = !menuItem->Checked; // ����������� ��������� Checked
    }

    if (!isFiltered) {
        // ��������� �������� ������ ��� ������ �������
        if (!originalRows) {
            originalRows = new TStringList;
            for (int row = 1; row < StringGrid1->RowCount; ++row) {
                String rowData = "";
                for (int col = 0; col < StringGrid1->ColCount; ++col) {
                    rowData += StringGrid1->Cells[col][row] + "\t";
                }
                originalRows->Add(rowData);
            }
        }

        // ��������� ���������� ������������ �������
        TDateTime currentDate = DateTimePicker1->Date; // ������� ����
        TStringList *expiredRows = new TStringList;

        try {
            TFormatSettings formatSettings;
            formatSettings.DateSeparator = '-';
            formatSettings.ShortDateFormat = "yyyy-mm-dd";

            for (int row = 1; row < StringGrid1->RowCount; ++row) {
                String manufactureDateStr = StringGrid1->Cells[5][row];
                String shelfLifeStr = StringGrid1->Cells[4][row];
                shelfLifeStr = shelfLifeStr.Trim();

                TDateTime manufactureDate;
                int shelfLifeDays;

				// ����������� ������
                if (TryStrToDate(manufactureDateStr, manufactureDate, formatSettings) &&
                    TryStrToInt(shelfLifeStr, shelfLifeDays)) {
                    TDateTime expiryDate = manufactureDate + shelfLifeDays;

                    if (expiryDate < currentDate) {
                        String rowData = "";
                        for (int col = 0; col < StringGrid1->ColCount; ++col) {
                            rowData += StringGrid1->Cells[col][row] + "\t";
                        }
                        expiredRows->Add(rowData);
                    }
                }
            }

            // ������� ������ (����� ����������)
            StringGrid1->RowCount = 1;

            // ��������� ������������ ������ � �������
            for (int i = 0; i < expiredRows->Count; ++i) {
                StringGrid1->RowCount = StringGrid1->RowCount + 1;
                TStringList *rowData = new TStringList;
                rowData->Delimiter = '\t';
                rowData->DelimitedText = expiredRows->Strings[i];

                for (int col = 0; col < rowData->Count; ++col) {
                    StringGrid1->Cells[col][StringGrid1->RowCount - 1] = rowData->Strings[col];
                }
                delete rowData;
            }
        }
        __finally {
            delete expiredRows;
        }

        isFiltered = true; // ������������� ���� ����������
    } else {
        // ��������������� �������� ������
        StringGrid1->RowCount = 1; // ������� ������ (����� ����������)

        for (int i = 0; i < originalRows->Count; ++i) {
            StringGrid1->RowCount = StringGrid1->RowCount + 1;
            TStringList *rowData = new TStringList;
            rowData->Delimiter = '\t';
            rowData->DelimitedText = originalRows->Strings[i];

            for (int col = 0; col < rowData->Count; ++col) {
                StringGrid1->Cells[col][StringGrid1->RowCount - 1] = rowData->Strings[col];
            }
            delete rowData;
        }

        isFiltered = false; // ���������� ���� ����������
    }
}

