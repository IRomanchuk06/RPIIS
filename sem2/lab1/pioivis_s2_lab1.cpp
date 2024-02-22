#include "youngtbl.hpp"
#include <string>
#include <sstream>
using namespace std;

int main()
{
	// ������������ ������� ��������
	setlocale(LC_ALL, "Russian");
	
	// ������� ����, ������ ��� ������� ���������� � header-�����
	YoungTableau t;
	
	cout << "������������!\n";
	while (1)
	{
		cout << "\n1) �������� ������� �� �����";
		cout << "\n2) ����������� �������";
		cout << "\n3) �������� ������� � �������";
		cout << "\n4) ������� ������� �� �������";
		cout << "\n5) �������� ������� � ����";
		cout << "\n6) ����� �� ���������";
		cout << "\n��� �����: ";
		int choice;
		cin >> choice;
		switch(choice)
		{
			// ������ ������� �� �����
			case 1:
			{
				string ifname;
				cout << "\n������� �������� ���������� �����, �� �������� ����� ������������� ����, ��� ����������: ";
				cin >> ifname;
				ifstream fin(ifname + ".txt");
				
				if (!fin)
				{
					cout << "���� �� ����������.\n";
					break;
				}
				
				// �������� ������� �� n ������ �������� ��� ������ ������� ����
				int n;
				fin >> n;
				t.initialize(n);

				// ���� ������� ���������
				for (int i = 0; i <= n; i++)
				{
					string u;
					getline(fin, u);
					istringstream iss(u);
					int num;
					while (iss >> num)
						t.add(i, num);
				}
				
				cout << "������� �� " << ifname << ".txt ���� ������� ���������.\n";
				break;
			}

			// ����� ������� �� �����
			case 2:
			{
				t.print();
				break;
			}

			// ���������� �������� � �������
			case 3:
			{
				int k, e;
				cout << "\n�������� ������, � ������� �� ������ �������� �������: ";
				cin >> k;
				if (k<1 || k>t.width())
				{
					cout << "������� ����� ����� ������.\n";
					break;
				}
				cout << "������� �������, ������� �� ������ ��������: ";
				cin >> e;
				t.add(k, e);
				cout << "� ������ �" << k << " ��� �������� ������� " << e << ".\n";
				break;
			}

			// �������� �������� �� �������
			case 4:
			{
				int r_ch, e;
				cout << "\n������� e: ";
				cin >> e;
				cout << "��� �� ������ �������?";
				cout << "\n1) ������ e, ������������� � �������";
				cout << "\n2) ��� e � �������";
				cout << "\n��� ����� : ";
				cin >> r_ch;
				switch (r_ch)
				{
					case 1:
						t.remove(e);
						break;
					case 2:
						t.removeAll(e);
						break;
					default:
						cout << "������!\n\n";
				}
				break;
			}

			// ����� ������� � ����
			case 5:
			{
				string ofname;
				cout << "\n������� �������� ���������� �����, � ������� ������ ���������� �����, ��� ����������: ";
				cin >> ofname;
				t.printToFile(ofname + ".txt");
				break;
			}

			// ���������� ������
			case 6:
			{
				cout << "\n�� ��������!\n";
				return 0;
			}
			
			// ����� �������� �� ������������� ������� ������������
			default:
			{
				cout << "������!\n\n";
			}
		}
	}
}