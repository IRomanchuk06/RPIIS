#pragma once

#ifndef LABA2_HEADER_H
#define LABA2_HEADER_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <cstdlib> 
#include <algorithm> 
using namespace std;

constexpr auto OPENSET_SYMBOL = '{'; //�������� ������������� ������
constexpr auto CLOSESET_SYMBOL = '}'; //�������� ������������� ������
constexpr auto DELIMITER_SYMBOL = ','; //������� (�����������)

string inputpath = "input.txt";

ifstream fin;

//���������� �� �����
vector<string> getSets(string inputpath) {
    fin.open(inputpath);
    if (!fin.is_open())
        cout << "��������� ������ ��� �������� ����� (" + inputpath + ")!" << endl;
    vector<string> sets; //� ���� ����������� ������, �������������� ���������
    int line = 0; //line ��� ������������ ������ ������ � �����
    while (!fin.eof()) { //���� ��������, ���� �� ������� ������
        line++;
        string buff;
        getline(fin, buff); //��������� ������ �� ����� � ��������� �� � ���������� buff
        cout << buff << endl;
        if ((buff[2] == '{') && (buff[1] == '=') && (buff[buff.length() - 1] == '}')) {
            int opens = 0;
            int closes = 0;
            for (int i = 0; i < buff.length(); i++) { //��������������, ����� ���-�� ������ ���� ����������
                if (buff[i] == OPENSET_SYMBOL)
                    opens++;
                if (buff[i] == CLOSESET_SYMBOL)
                    closes++;
            }
            if (opens != closes) { //���������, ��������� �� ���������� ����������� � ����������� ������ � ������. ���� ���, ��������� ��������� �� ������
                cout << "��������� ������������ �����! ������: " + to_string(line) + ", ����: " + inputpath << endl; //����� ������������ ��� ���������� ����� � �����
                cout << "���������� '{' �� ����� ���������� '}'" << endl;
                exit(0);
            }
            sets.push_back(buff); //������������ ��� ���������� ������ buff � ����� ������� sets
        }
        else {
            cout << "��������� ������������ �����! ������: " + to_string(line) + ", ����: " + inputpath << endl;
            exit(0);
            break;
        }
    }
    return sets;
}

//�������� ����� ��������
vector<string> getNamePlenty(vector<string> sets) {
    int numSets = sets.size(); //����� ���������� ��������� �������� (����� � ������� sets) 
    vector<string> namePlenty(numSets); //������ ����� � ��������, ������ ���������� ��������
    for (int i = 0; i < numSets; i++) {
        namePlenty[i] = sets[i][0];
    }
    return namePlenty;
}

//���������� ����������� ������� ��������� �� ������� sets � ���������� ����� �����������
vector<string> saveFillPlenty(vector<string> sets) {
    int numSets = sets.size(); //����� ���������� ��������� �������� (����� � ������� sets)
    vector<string> fillPlenty(numSets); //������ ���������� ������� ���������
    for (int i = 0; i < numSets; i++) {
        fillPlenty[i] = sets[i].substr(2, sets[i].length() - 3); //��������� � fillPlenty ������ �� (sets[i].length() - 3) ��������, ������� �� ������� �������� �� sets
    }
    return fillPlenty;
}

//���������� �������� �� ��������� ��������
vector<vector<string>> splitSets(vector<string> sets, char delimiter) {
    int numSets = sets.size();
    vector<vector<string>> elements(numSets);

    for (auto i = 0; i < numSets; i++) {
        string buff;
        int openBrackets = 0;
        buff = sets[i].substr(3, sets[i].length() - 4);
        stringstream ss(buff);
        string token;
        string element = "";

        while (getline(ss, token, delimiter)) {
            if (token[0] == '{') {
                openBrackets++;
                element += token;
                while (openBrackets > 0 && getline(ss, token, delimiter)) {
                    element += delimiter + token;
                    if (token[0] == '{') {
                        openBrackets++;
                    }
                    else if (token[1] == '}') {
                        openBrackets--;
                    }
                }
                elements[i].push_back(element);
                element = "";
            }
            else {
                elements[i].push_back(token);
            }
        }
    }

    vector<string> list_name = getNamePlenty(sets);
    vector<string> fillPlenty = saveFillPlenty(sets);
    int numSetsName = list_name.size();

    for (int i = 0; i < numSets; i++) {
        for (int k = 0; k < elements[i].size(); k++) {
            for (int j = 0; j < numSetsName; j++) {
                if ((list_name[j] == elements[i][k]) && (j != i)) {
                    elements[i][k] = fillPlenty[j];
                }
            }
        }
    }
    return elements;
}

//���������� ��������
vector<string> setDifference(const vector<string>& set1, const vector<string>& set2) {
    vector<string> result; //�������� ��������

    //�������� ��� �������� �� ������� ���������
    result = set1;

    //������� �������� ������� ��������� �� ����������   
    for (const auto& elem : set2) {
        auto it = find(result.begin(), result.end(), elem);
        if (it != result.end()) {
            result.erase(it);
        }
    }
    return result;
}

//������ �������� ��� ���������� ������
string prettify(const vector<string>& set) {
    string result = "";
    result += OPENSET_SYMBOL;
    for (int i = 0; i < set.size(); i++) {
        result += set[i];
        if (i != set.size() - 1) {
            result += DELIMITER_SYMBOL;
        }
    }
    result += CLOSESET_SYMBOL;
    return result;
}

//������ ����� ��������
string Start(vector<string> sets) {
    getNamePlenty(sets);

    vector<vector<string>> elements;
    elements = splitSets(sets, DELIMITER_SYMBOL);
    
    //��������, ��� ���� ��� ��������� ��� ���������� ��������
    if (elements.size() < 2) {
        cout << "������: ��� ���������� �������� ����� ��� ���������!" << endl;
        return "";
    }

    //�������� ����� ������� ����� �����������
    vector<string> result = setDifference(elements[0], elements[1]);

    cout << "\n��������: ";
    cout << prettify(result) << endl;
    return prettify(result);
}

#endif //LABA2_HEADER_H