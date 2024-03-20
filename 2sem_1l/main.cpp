#include <iostream>
#include "Set.h"

using namespace std;
//���������. ���������� �������� �� ���������. �������� �������� ��
//���������.����� �������� �� ���������.����������� ����
//��������.����������� ���� ��������.
int main() {
    setlocale(LC_ALL, "RU");
    MySet set;

    int choice;
    do {
        cout << "����:" << endl;
        cout << "1. ���������� ��������� �� ���������" << endl;
        cout << "2. �������� �������� �� ���������" << endl;
        cout << "3. ����� �������� �� ���������" << endl;
        cout << "4. �������� ���������" << endl;
        cout << "5. ����������� � ����������� ��������" << endl;
        cout << "0. ����� �� ���������." << endl;
        cout << "�������� ����� ����: ";
        while (!(cin >> choice)) {
            cout << "������. ������� ���������� ��������." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
        case 1: {
            int size;
            cout << "������� ���������� ����������� ���������: ";
            while (!(cin >> size)) {
                cout << "������. ������� ���������� ��������." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            for (int i = 1; i <= size; i++) {
                int element;
                cout << "������� ������� " << set.size() + 1 << " ���������: ";
                while (!(cin >> element)) {
                    cout << "������. ������� ���������� ��������." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                set.insert(element);
            }

            set.print();
        }
            break;
        case 2:
            int element;
            cout << "������� ������� ��� ��������: ";
            while (!(cin >> element)) {
                cout << "������. ������� ���������� ��������." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if (set.contains(element)) {
                set.remove(element);
                cout << "������� �����"<<endl;
                set.print();
            }
            else {
                cout << "������� " << element << " �� ������ � ���������." << endl;
            }

            break;
        case 3:
            cout << "������� ������� ��� ������: ";
            while (!(cin >> element)) {
                cout << "������. ������� ���������� ��������." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (set.contains(element)) {
                cout << "������� " << element << " ������ � ��������� ��� ������� " << set.contains2(element) + 1 << endl;
            }
            else {
                cout << "������� " << element << " �� ������ � ���������." << endl;
            }
          
            break;
        case 4:
            set.print();
            break;
        case 5: {
            MySet set1;
            MySet set2;

            int size1;
            cout << "������� ������ ��������� 1: ";
            while (!(cin >> size1)) {
                cout << "������. ������� ���������� ��������." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            for (int i = 0; i < size1; i++) {
                int element;
                cout << "������� ������� " << i + 1 << " ������� ���������: ";
                while (!(cin >> element)) {
                    cout << "������. ������� ���������� ��������." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                set1.insert(element);
            }

            int size2;
            cout << "������� ������ ��������� 2: ";
            while (!(cin >> size2)) {
                cout << "������. ������� ���������� ��������." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            for (int i = 0; i < size2; i++) {
                int element;
                cout << "������� ������� " << i + 1 << " ������� ���������: ";
                while (!(cin >> element)) {
                    cout << "������. ������� ���������� ��������." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                set2.insert(element);
            }

            MySet intersectionSet = set1.intersection(set2);
            cout << "����������� ��������: ";
            intersectionSet.print();

            MySet unionSet = set1.unionWith(set2);
            cout << "����������� ��������: ";
            unionSet.print();
        }
            break;
        case 0:
            cout << "����� �� ���������." << endl;
            break;
        default:
            cout << "������������ ����� ����. ���������� ��� ���." << endl;
            break;
        }
        cout << endl;
    } while (choice != 0);

    return 0;
}