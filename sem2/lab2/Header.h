#ifndef LAB2_H //��� �������������� ������������� ��������� ������ � ���� �� ������������� ����� � ���������
#define LAB2_H

// ������.�.1 (SetRecord)-������ �� �����;
//������1 (sets) - ������ ������� �� �����;
//������.�.2 (CopyingNames) - �������� �������� ��-�; 
//������2 (Names_of_sets) - �������� ��-�;
//������.�.3 (FullRecord) - ������ �������;
//������3 (FULLset) - {1, 2, 3, 4, 5};
//������.�.4 (MakeElements) - ��������� �������� ��������;
//������4 (elements) - �������� ��-��, ��� ������;
//������.�.5 (Intersection) - ����������;
//������5 (result) -  �������� �����������;
//������.�.6 (Improove) - ������� ������� ��������, + �����������;
//������6 (result) - �������� ��-�� �����������;


//
// Created by ��������� ����� on 26.02.24.
//


#include "Header.h"  // ����������� ����������������� ������������� ����� Header.h

#include <iostream>   // ����/����� ����������� ������� ������
#include <fstream>    // ������ � �������
#include <string>     // ������ �� ��������
#include <vector>     // ������ � ������������� ���������
#include <sstream>    // ������ � �������� �����/������
#include <algorithm>  // ��������� ��� ������ � ������������ � �����������

using namespace std;

constexpr auto OPENSET_SYMBOL = '{';
constexpr auto CLOSESET_SYMBOL = '}';
constexpr auto DELIMITER_SYMBOL = ',';

string path;
ifstream f;

//-----------------------------------------������_������---------------------------------------------------

vector<string> SetRecord(string path) {
    f.open(path);
    if (!f.is_open())
        cout << "Error while opening file!" << endl;
    vector<string> sets;
    int line = 0;
    while (!f.eof()) {
        line++;
        string buff;
        getline(f, buff);
        cout << buff << endl;
        if ((buff[2] == '{') && (buff[1] == '=') && (buff[buff.length() - 1] == '}')) {
            int open = 0;
            int close = 0;
            for (int i = 0; i < buff.length(); i++) {
                if (buff[i] == OPENSET_SYMBOL)
                    open++;
                if (buff[i] == CLOSESET_SYMBOL)
                    close++;
            }
            if (open != close) {
                cout << "Check input for correctness!" << endl;
                cout << "Number of '{' is not equal to number of '}'" << endl;
                exit(0);
            }
            sets.push_back(buff);
        }
        else {
            cout << "Check input for correctness!" << endl;
            exit(0);
            break;
        }
    }
    return sets;
}

//-----------------------------------------��������_�����---------------------------------------------------

vector<string> CopyingNames(vector<string> sets) {
    int numberSets = sets.size();
    vector<string> Names_of_sets(numberSets);
    for (int i = 0; i < numberSets; i++) {
        Names_of_sets[i] = sets[i][0];
    }
    return Names_of_sets;
}

//--------------------------------------------������_�������------------------------------------------------

vector<string> FullRecord(vector<string> sets) {
    int numberSets = sets.size();
    vector<string> FULLset(numberSets);
    for (int i = 0; i < numberSets; i++) {
        FULLset[i] = sets[i].substr(2, sets[i].length() - 3);
    }
    return FULLset;
}

//--------------------------------------------��������_��������------------------------------------------------

vector<vector<string>> MakeElements(vector<string> sets, char delimiter) {
    int numberSets = sets.size();
    vector<vector<string>> elements(numberSets);
    for (auto i = 0; i < numberSets; i++) {
        string buff;

        buff = sets[i].substr(3, sets[i].length() - 4); // ������� ������
        stringstream potok(buff); //��� ��������� ������ �� ��������� ������ � �������������� �����������
        string token;
        string element = "";
        int setOpened = 0;
        while (getline(potok, token, delimiter)) { //�� ��� ���, ���� �� ������ potok ����� ������� ��������� �����
            element += token + DELIMITER_SYMBOL;
        }
        element.pop_back(); //������
        stringstream element_potok(element);
        while (getline(element_potok, token, DELIMITER_SYMBOL)) {
            elements[i].push_back(token); //������
        }
    }

    vector<string> Names = CopyingNames(sets);
    vector<string> FULLMN = FullRecord(sets);
    int numSetsName = Names.size();
    for (int i = 0; i < numberSets; i++) {                          //�������� ������� ���������� ����� ���������� ������� ������������ 
        for (int k = 0; k < elements[i].size(); k++) {              //� ������� ������� Nsmes. ���� ������� ���������� 
            for (int j = 0; j < numSetsName; j++) {                 //� ��� �� ������� ������, �� ������� ���������� 
                if ((Names[j] == elements[i][k]) && (j != i)) {     //�� ��������������� ������� �� ������� FULLMN.
                    elements[i][k] = FULLMN[j];
                }
            }
        }
    }
    return elements;
}

//--------------------------------------------������_�����������------------------------------------------------

vector<string> Intersection(const vector<string>& set1, const vector<string>& set2) {
    vector<string> result;

    for (const auto& elem : set1) {
        if (find(set2.begin(), set2.end(), elem) != set2.end()) {
            result.push_back(elem);
        }
    }

    return result;
}



string Improove(const vector<string>& set) {
    string result(1, OPENSET_SYMBOL);

    for (int i = 0; i < set.size(); i++) {
        result += set[i];
        if (i != set.size() - 1) {
            result += DELIMITER_SYMBOL;
        }
    }
    result += CLOSESET_SYMBOL;
    return result;
}

string Start(vector<string> sets) {
    CopyingNames(sets);

    vector<vector<string>> elements;
    elements = MakeElements(sets, DELIMITER_SYMBOL);

    if (elements.size() < 2) {
        cout << "Error: Need at least two sets to compute intersection!" << endl;
        return "";
    }

    vector<string> result = Intersection(elements[0], elements[1]);

    cout << "\nIntersection: ";
    cout << Improove(result) << endl;
    return Improove(result);
    f.close();
}

#endif