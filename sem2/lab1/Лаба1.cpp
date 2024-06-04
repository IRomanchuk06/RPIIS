#include <iostream>
#include <vector>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
const int NUMBER = 1000;
long long mass[NUMBER], core[NUMBER];
int num, oper;

long long sum(int count)
{
    long long summa = 0;
    for (int i = count; i >= 0; i = (i & (i + 1)) - 1)
        summa += mass[i];
    return summa;
}

void update(int position, long long value)
{
    for (int j = position; j <= num; j = j | (j + 1))
    {
        mass[j] += value;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "������� ���������� ��������� �������: ";
    cin >> num; cout << endl;
    cout << "������� ���������� ��������, ������� �� ������ �������� (���� �� �������, ������� ������� �����): ";
    cin >> oper; cout << endl;
    cout << "����� �������: (A i x) - ��������� i-���� �������� ������� �������� x; (Q l r) - ����� ����� �������� ��������� �� �������� �� l �� r." << endl;
    cout << "��� ���������������� ����������� ������ ��������� ������� 'End' ������ 'A' ��� 'Q' " << endl;
    for (int i = 0; i < oper; i++)
    {
        char swch;
        int count1, count2;
        cout << "������� ���� ������ � ����� 'A i x' ��� 'Q l r': " << endl;
        cin >> swch >> count1 >> count2;
        if (swch != 'End') {
            if (swch == 'A')
            {
                update(count1, count2 - core[count1]);
                core[count1] = count2;
            }
            else if (swch == 'Q') {
                cout << "Summa ravna " << sum(count2) - sum(count1 - 1) << endl;
            }
        }
    }
}