#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <vector>

using namespace std;

struct Array // ���������, ����������� ���������
{
    string Type,Str;
    int ElementsNum;
    vector<Array*> SubsetItems; 

    Array(string type, int numberOfItems, string str); // ����������� � �����������
};

Array* ArrayCreation(string str); // ������ ��������� �� ������
bool InSubset(Array* arr1, Array* arr2); // ���������� �������� �� arr1 ������������� arr2 (��������� ��� ��������)
bool IsCorrect(string str); // �������� �� ������������ �������� ������
void GetResult(Array* arr1, Array* arr2); // ��������� ����������
void Remove(Array* arr); // ������� ���������