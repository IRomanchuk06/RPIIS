#include <iostream>
#include <string.h>
#include <string>
#include <fstream>
#include <vector>
#include "Header.h"
using namespace std;

Array::Array(string type, int numberOfItems, string str) // �����������
{
    if (type == "�������")
    {
        Type = type;
        ElementsNum = numberOfItems;
        Str = str;
    }
    if (type == "���������" || type == "������")
    {
        Type = type;
        ElementsNum = numberOfItems;
        SubsetItems.resize(numberOfItems);
    }
}

Array* ArrayCreation(string str) // ������ ��������� �� ������
{

    Array* result;
    string type;
    // startPos - ��������� ������� �������� ������������ � ������
    // endPos - �������� ������� �������� ������������ � ������
    // count - ���������� ��������� � ����������� �������
    // openArr - ���������� �������� ������ ��������
    // openCourt - ���������� �������� ������ ��������
    int startPos = 0, endPos = 0, count = 0, openArr = 0, openCourt = 0;
    //��������� ���������� ��������� � �������, ������ ������ ������
    // ��������� ������� ���������: ���� ������ ������� ������ �� "{}"
    if (str == "{}") {
        result = new Array("���������", 0, str);
        return result;
    }
    for (int i = 1; i < str.length() - 1; i++)
    {
        if (str[i] == '{') {
            openArr++;
        }
        if (str[i] == '}') {
            openArr--;
        }
        if (str[i] == '<') {
            openCourt++;
        }
        if (str[i] == '>') {
            openCourt--;
        }
        //���� ������� �������, � �������� ������ ����� ����, �� ����������� ����� �������
        if (str[i] == ',' && openArr == 0 && openCourt == 0) {
            count++;
        }
    }
    //����������, ��� �������� ������ �� ������� �������
    if (str[0] == '{') {
        type = "���������";
    }
    else if (str[0] == '<') {
        type = "������";
    }
    else
    {
        Array* arr = new Array("�������", 1, str);
        return arr;
    }
    count++; //����������� ������� ��� �� 1, ������ ��� ����� ���������� �������� ��� �������
    result = new Array(type, count, str);
    int i = 0;
    while (i < count)
    {
        // ���� startPos ����� 0 ��� ��������� �� �������, ������ ��� ������ ������ ��������
        if (startPos == 0 || str[startPos] == ',')
        {
            startPos++;// �������� startPos �� ��������� ������
        }
        // ���� endPos ��������� �� ����� ������ ��� �������, ������ ��� ����� �������� ��������
        if (endPos == str.length() - 1 || str[endPos] == ',')
        {
            endPos--;//�������� endPos �� ���������� ������
            // �������� �������� �������� ������
            openArr = 0;
            openCourt = 0;
            // �������� �� ������ �� ������ �������� �������� �� ��� �����
            for (int j = 1; j <= endPos; j++)
            {
                if (str[j] == '{') {
                    openArr++;
                }
                else if (str[j] == '<') {
                    openCourt++;
                }
                else if (str[j] == '}') {
                    openArr--;
                }
                else if (str[j] == '>') {
                    openCourt--;
                }
            }
            // ���� �������� �������� ������ ����� ����, ������ ��������� �������� ���������� �������������
            if (openArr == 0 && openCourt == 0)
            {
                // ���������� ������� ������������ �� ��������� � ���������� � SubsetItems[i]
                result->SubsetItems[i] = ArrayCreation(str.substr(startPos, endPos - startPos + 1));
                startPos = endPos + 1;// ����������� startPos �� ������ ���������� �������� ����� �������
                endPos = startPos;
                i++;//��������� � ���������� ��������
            }
            // ���� �������� �������� ������ �� ����� ����, ������ ��������� �� �������� ���������� �������������
            else
            {
                endPos++; // �������� endPos �� ��������� ������
            }
        }

        endPos++;
    }
    return result;//���������� ���������� ���������
}

bool InSubset(Array* arr1, Array* arr2) {
    bool isInSecond = false;
    if (arr1->Type != "�������" && arr2->Type != "�������") {
        vector<bool> used(arr2->ElementsNum, false);
        for (int i = 0; i < arr1->ElementsNum; i++) {
            isInSecond = false;
            for (int j = 0; j < arr2->ElementsNum; j++) {
                // ���������, �� ��� �� ���� ������� arr2 ��� ����������� 
                // � ��������� �� ��� � ���������� ��������� � ������� ��������� arr1 � arr2
                if (!used[j] && arr1->SubsetItems[i]->ElementsNum == arr2->SubsetItems[j]->ElementsNum && arr1->SubsetItems[i]->Type == arr2->SubsetItems[j]->Type) {
                    // ���� arr1 - ������ � j > i, �� ������� ��������� �������, ���������� false 
                    if (arr1->Type == "������" && j > i) {
                        return false;
                    }
                    //���������� ��������� �������� ��������
                    isInSecond = InSubset(arr1->SubsetItems[i], arr2->SubsetItems[j]);
                    // ���� �������� �������, �������� ������� arr2 ��� �������������� � ������� �� ����������� �����
                    if (isInSecond) {
                        used[j] = true;
                        break;
                    }
                }
                // ��������, �������� �� arr1 ��������, � arr2 ����������,
                // � ��������� �� arr1 � ��������� arr2
                if (!used[j] && arr1->Type == "������" && arr2->Type == "���������" && InSubset(arr1, arr2->SubsetItems[j])) {
                    return true;
                }
                // ��������, �������� �� arr2 ���������, � arr1 - ��������,
                // � ��������� �� arr2 � ��������� arr1
                if (!used[j] && arr2->Type == "�������" && arr1->Type == "������" && InSubset(arr2, arr1->SubsetItems[j])) {
                    return true;
                }
            }
            if (!isInSecond) {
                return false;
            }
        }
    }

    else if (arr1->Type == "�������" && arr2->Type == "�������" && arr1->Str == arr2->Str)
    {
        return true;
    }
    else {
        return false;
    }
    return true;
}


bool IsCorrect(string str) // �������� �� ������������ �������� ������
{
    if (str.find("><") != -1 || str.find("}{") != -1) {
        cout << "�������� ������ ����������� �������\n";
        return false;
    }
    int openArr = 0;
    int openCourt = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{')
            openArr++;
        if (str[i] == '<')
            openCourt++;
        if (str[i] == '}')
            openArr--;
        if (str[i] == '>')
            openCourt--;
    }
    if (openArr != 0 || openCourt != 0) {
        cout << "� ������ �������� ������\n";
        return false;
    }
    return true;
}



void GetResult(Array* arr1, Array* arr2) // ��������� ����������
{

    if (InSubset(arr1, arr2) && InSubset(arr2, arr1))
        cout << "�����" << endl;
    else
    {
        cout << "�� �����" << endl;
        if (InSubset(arr1, arr2))
            cout << "A - ������������ B" << endl;
        else if (InSubset(arr2, arr1))
            cout << "B - ������������ A" << endl;
        else if (arr1->Type != "�������" && arr2->Type != "�������")
        {
            for (int i = 0; i < arr1->ElementsNum; i++)
            {
                if (InSubset(arr1->SubsetItems[i], arr2) && InSubset(arr2, arr1->SubsetItems[i]))
                {
                    cout << "B - ������� A" << endl;
                    break;
                }
            }
            for (int i = 0; i < arr2->ElementsNum; i++)
            {
                if (InSubset(arr2->SubsetItems[i], arr1) && InSubset(arr1, arr2->SubsetItems[i]))
                {
                    cout << "A - ������� B" << endl;
                    break;
                }
            }
        }
        else if (arr1->Type == "�������" && arr2->Type == "���������") {
            for (int i = 0; i < arr2->ElementsNum; i++) {
                if (InSubset(arr1, arr2->SubsetItems[i]) && InSubset(arr2->SubsetItems[i], arr1)) {
                    cout << "� - ������� �\n";
                    break;
                }
            }
        }
        else if (arr2->Type == "�������" && arr1->Type == "���������") {
            for (int i = 0; i < arr1->ElementsNum; i++) {
                if (InSubset(arr2, arr1->SubsetItems[i]) && InSubset(arr1->SubsetItems[i], arr2)) {
                    cout << "� - ������� �\n";
                    break;
                }
            }
        }
        else if (arr2->Type == "�������" && arr1->Type == "������") {
            for (int i = 0; i < arr1->ElementsNum; i++) {
                if (InSubset(arr2, arr1->SubsetItems[i]) && InSubset(arr1->SubsetItems[i], arr2)) {
                    cout << "� - ������� �\n";
                    break;
                }
            }
        }
        else if (arr2->Type == "������" && arr1->Type == "�������") {
            for (int i = 0; i < arr2->ElementsNum; i++) {
                if (InSubset(arr1, arr2->SubsetItems[i]) && InSubset(arr2->SubsetItems[i], arr1)) {
                    cout << "� - ������� �\n";
                    break;
                }
            }
        }
    }
}
void Remove(Array* arr) // ������� ���������
{
    if (arr->Type == "�������")
    {
        delete arr;
        return;
    }
    for (int i = 0; i < arr->ElementsNum; i++)
    {
        Remove(arr->SubsetItems[i]);
    }
    delete arr;
    return;
}