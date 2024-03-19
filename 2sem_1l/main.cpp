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
        cout << "1. �������� ������ ���������" << endl;
        cout << "2. ���������� �������� �� ���������" << endl;
        cout << "3. �������� �������� �� ���������" << endl;
        cout << "4. ����� �������� �� ���������" << endl;
        cout << "5. �������� ���������" << endl;
        cout << "6. ����������� � ����������� ��������" << endl;
        cout << "�������� ����� ����: ";
        cin >> choice;

        switch (choice) {
        case 1:
            int size;
            cout << "������� ������ ���������: ";
            cin >> size;

            for (int i = 0; i < size; i++) {
                int element;
                cout << "������� ������� " << i + 1 << " ���������: ";
                cin >> element;
                set.insert(element);
            }
            set.print();

            break;
        case 2:
            int element;
            cout << "������� ������� : ";
            cin >> element;
            set.insert(element);
            set.print();
            
            break;
        case 3:
            cout << "������� ������� ��� ������: ";
            cin >> element;
            if (set.contains(element)) {
                set.remove(element);
                cout << "������� �����";
                set.print();
            }
            else {
                cout << "������� " << element << " �� ������ � ���������." << endl;
            }

            break;
        case 4:
            cout << "������� ������� ��� ������: ";
            cin >> element;

            if (set.contains(element)) {
                cout << "������� " << element << " ������ � ���������." << endl;
            }
            else {
                cout << "������� " << element << " �� ������ � ���������." << endl;
            }
          
            break;
        case 5:
            set.print();
            break;
        case 6: {
            MySet set1;
            MySet set2;

            int size1;
            cout << "������� ������ ��������� 1: ";
            cin >> size1;

            for (int i = 0; i < size1; i++) {
                int element;
                cout << "������� ������� " << i + 1 << " ������� ���������: ";
                cin >> element;
                set1.insert(element);
            }

            int size2;
            cout << "������� ������ ��������� 2: ";
            cin >> size2;

            for (int i = 0; i < size2; i++) {
                int element;
                cout << "������� ������� " << i + 1 << " ������� ���������: ";
                cin >> element;
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