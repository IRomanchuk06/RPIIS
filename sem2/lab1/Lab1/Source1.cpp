#include "Header.h"
#include <iostream>
using namespace Y;
using namespace std;
int main() {
	int choice;
	setlocale(LC_ALL, "ru");
	cout << "1.����" << endl << "2.����"<<endl;
	cin >> choice;
	while (cin.fail() || choice < 1 || choice>2) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "1.����" << endl << "2.����" << endl;
		cin >> choice;
	}
	Deck* exmpl= new Deck;
	switch (choice) {
	case 1:
		exmpl->file();
		break;
	case 2:
		exmpl->crtdeck();

	}
	exmpl->output();
	Deck* end = exmpl;
	while (end->next != nullptr)
		end = end->next;
	again:
	cout <<endl<< "1.������� � �����" << endl << "2.������� � ������" << endl << "3.�������� � �����" << endl << "4.�������� � ������" << endl << "5.�����������" << endl << "6.���������";
	cin >> choice;
	while (cin.fail()||choice<1||choice>6) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "������� ��������:";
		cin >> choice;
	}
	switch (choice) {
	case 1:
		exmpl->delback(end,exmpl);
		if (end == nullptr) {
			exmpl = nullptr;
			break;
		}
		goto again;
	case 2:
		exmpl->delfront(exmpl);
		if (exmpl==nullptr)
		{
			break;
		}
		goto again;
	case 3:
		exmpl->addback(end);
		goto again;
	case 4:
		exmpl->addfront(exmpl);
		goto again;
	case 5:
		exmpl->output();
		goto again;
	case 6:
		break;
	}
	while (exmpl!=nullptr&&end!=nullptr) {
		exmpl->delfront(exmpl);
	}
	return 0;
}