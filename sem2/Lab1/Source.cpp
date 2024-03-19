#include <iostream>
#include <string>
#include "Node.h"; 
#include "bor.h";
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	int n = 0;
	string s;
	Node* root = new Node();
	root->back_ptr = new Node(root);
	do
	{
 		cout << "�������� ��������: 1 - �������� ������ � ���, 2 - ������� c����� �� ����, 3 - ����� ������ � ����, 4 - ������� ��� ������ � ����, 0 - ��������� ��������� " << endl;
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "������� ������: ";
			cin >> s;
			AddString(s, root);
			break;
		case 2:
			cout << "������� ������: ";
			cin >> s;
			DelString(s, root);
			break;
		case 3:
			cout << "������� ������: ";
			cin >> s;
			SearchString(s, root);
			break;
		case 4:
			cout << "������ � ����: " << endl;
			ShowBor(root);
			break;
		case 0:
			delete root->back_ptr;
			DelBor(root);
			return 0;
		default:
			cout << "������� �������������� �����";
		}
	} while (true);
}
