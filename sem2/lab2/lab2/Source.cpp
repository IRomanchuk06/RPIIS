#include <iostream>
#include "Header.h"

using namespace std;
using namespace Y;

int main() 
{
	setlocale(LC_ALL, "ru");

	int n = 0;
	short int choice;
	set** exmpl = nullptr;

chs:

	cout << "1.���� � ����������" << endl << "2.�� �����" << endl;
	cin >> choice;

	while (cin.fail()||choice>2||choice<1) 
	{
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "1.���� � ����������" << endl << "2.�� �����" << endl;
		cin >> choice;
	}

	switch (choice) 
	{
	case 1:
		cout << "���������� ��������:";
		cin >> n;

		while (cin.fail() || n < 2)
		{
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "���������� ��������:";
			cin >> n;
		}

		exmpl = new set * [n];
		for (int i = 0; i < n; i++)
		{
			exmpl[i] = new set;
			exmpl[i]->input();
		}

		break;
	case 2:
		exmpl = new set * [1];
		(*exmpl)->file(exmpl, n);

		if (n<2) 
		{
			cout << "������������ ��������" << endl;

			goto chs;
		}

		break;
	}
	for (int i = 0; i < n; i++) (*exmpl)->multiplicity(exmpl[i]->root);
	for (int i = 0; i < n; i++) 
	{
		cout << "��������� " << i + 1 << " :";
		(*exmpl)->output(exmpl[i]);
		cout << endl;
	}
	(*exmpl)->Obed(exmpl, n);
	cout << "�������������� ��������:";
	(*exmpl)->output(exmpl[0]);

}