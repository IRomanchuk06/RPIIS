#include <iostream>
#include "Header.h"
using namespace std;
using namespace Y;
int main() {
	int n = 0; short int choice; set** exmpl = nullptr;
	setlocale(LC_ALL, "ru");
	chs:
	std::cout << "1.���� � ����������"<<endl<<"2.�� �����"<<endl;
	cin >> choice;
	while (cin.fail()||choice>2||choice<1) {
		cin.clear();
		cin.ignore(10000, '\n');
		std::cout << "1.���� � ����������" << endl << "2.�� �����" << endl;
		cin >> choice;
	}
	switch (choice) {
	case 1:
		std::cout << "���������� ��������:";
		std::cin >> n;
		while (std::cin.fail() || n < 2) {
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cout << "���������� ��������:";
			std::cin >> n;
		}
		exmpl = new set * [n];
		for (int i = 0; i < n; i++) {
			exmpl[i] = new set;
			exmpl[i]->input();
		}
		break;
	case 2:
		exmpl = new set * [1];
		(*exmpl)->file(exmpl, n);
		if (n<2) {
			std::cout << "������������ ��������" << std::endl;
			goto chs;
		}
		break;
	}
	for (int i = 0; i < n; i++)
		(*exmpl)->multiplicity(exmpl[i]->root);
	for (int i = 0; i < n; i++) {
		std::cout << "��������� " << i + 1 << " :";
		(*exmpl)->output(exmpl[i]); std::cout << endl;
	}
	(*exmpl)->Obed(exmpl, n);
	std::cout << "�����������:";
	(*exmpl)->output(exmpl[0]);

}