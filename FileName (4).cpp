#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

bool readInputFile(const string& filename, vector<multiset<int>>& sets) {
    ifstream infile(filename);
    if (!infile.is_open()) 
    
    {
        cerr << "������: �� ������� ������� ���� " << filename << endl;
        return false;
    }

    string line;
    int n;

    if (!getline(infile, line) || !(istringstream(line) >> n) || n <= 0) {
        cerr << "������: ������������ ���������� ��������." << endl;
        return false;
    }

    sets.resize(n);

    for (int i = 0; i < n; ++i) {
        int m;
        if (!getline(infile, line) || !(istringstream(line) >> m) || m < 0) {
            cerr << "������: ������������ ���������� ��������� � ��������� " << i + 1 << "." << endl;
            return false;
        }

        if (!getline(infile, line)) {
            cerr << "������: ������������ ����� ��� ��������� " << i + 1 << "." << endl;
            return false;
        }

        istringstream elemStream(line);
        for (int j = 0; j < m; ++j) {
            int elem;
            if (!(elemStream >> elem)) {
                cerr << "������: ������������ �������� � ��������� " << i + 1 << "." << endl;
                return false;
            }
            sets[i].insert(elem);
        }
    }

    return true;
}

multiset<int> unionMultisets(const vector<multiset<int>>& sets) {
    multiset<int> result;
    for (const auto& s : sets) {
        result.insert(s.begin(), s.end());
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "RU");
    vector<string> filenames = { "test1.txt", "test2.txt", "test3.txt", "test4.txt", "test5.txt" };
    int choice;

    cout << "�������� ���� ��� ������ ������:" << endl;
    for (size_t i = 0; i < filenames.size(); ++i) {
        cout << i + 1 << ": " << filenames[i] << endl;
    }

    cout << "������� ����� ����� (1-5): ";
    cin >> choice;

    if (choice < 1 || choice > 5) {
        cerr << "������: ������������ �����." << endl;
        return 1;
    }

    const string filename = filenames[choice - 1];
    vector<multiset<int>> sets;

    if (!readInputFile(filename, sets)) {
        return 1;
    }

    multiset<int> result = unionMultisets(sets);

    cout << "������������ ���������: ";
    for (const auto& elem : result) {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}