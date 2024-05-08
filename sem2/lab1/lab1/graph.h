#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

class Graph {
private:
    int n;
    int m;
    vector<vector<int>> matrix;
public:
    void InputMatrix() {
        string s;
        string namefile;
        bool b = true;
        while (b)
        {
            cout << "�������� ���� �� �������� �������" << endl;;
            cin >> namefile;

            ifstream in(namefile);

            if (in.is_open())
            {
                getline(in, s);
                n = stoi(s.substr(0, s.size() - s.find(" ") - 1));
                m = stoi(s.substr(s.find(" ") + 1, s.size() - s.find(" ") - 1));

                matrix.resize(n, vector<int>(m, 0));
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        in >> matrix[i][j];
                    }
                }
                in.close();
                b = false;
            }
            else
            {
                cout << "���� �� ������." << endl;
            }

        }
        return;
    }

    void PrintMatrix()
    {
        cout << endl << "������� �������������:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void AddVertex()
    {
        vector<int> newVertex(m, 0);
        matrix.push_back(newVertex);
        n++;
        cout << "������� ���������." << endl << endl;
    }

    void DelVertex()
    {

        int numVertex;
        cout << endl << "�������� �������, ������� ������ �������: " << endl;
        cin >> numVertex;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "������������ ����." << endl;
        }

        numVertex--;
        if (numVertex >= 0 && numVertex < n)
        {
            for (int i = matrix[0].size() - 1; i >= 0 ; i--)
            {
                if (matrix[numVertex][i] != 0)
                {
                    for (int k = 0; k < n; k++)
                    {
                        matrix[k].erase(matrix[k].begin() + i);
                    }
                    m--;
                }
            }
            matrix.erase(matrix.begin() + numVertex);
            cout << "������� " << ++numVertex << " �������." << endl;
            n--;
        }
        else
        {
            cout << "������������ ������ ��� �������� ��������." << endl;
            return;
        }
    }

    void AddArc()
    {
        int fromVertex, toVertex;
        cout << endl << "������� 2 �������, �� ������� � �� ������� ����� ��������� ����: " << endl;
        cin >> fromVertex >> toVertex;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "������������ ����." << endl;
        }

        fromVertex--;
        toVertex--;
        if (fromVertex == toVertex)
        {
            cout << "���������� ������� �����. ������� 2 ���������� �������." << endl;
            return;
        }
        if ((fromVertex >= 0 && fromVertex < matrix.size()) && (toVertex >= 0 && toVertex < matrix.size()))
        {
            for (int i = 0; i < n; i++)
            {
                if (i == fromVertex)
                {
                    matrix[i].push_back(1);
                }
                else if (i == toVertex)
                {
                    matrix[i].push_back(-1);
                }
                else
                {
                    matrix[i].push_back(0);
                }
            }
            m++;
        }
        else
        {
            cout << "������������ ������." << endl;
            return;
        }
        cout << "���� �� ������� " << fromVertex + 1 << " �� ������� " << toVertex + 1 << " ���������." << endl;
    }

    void DelArc()
    {
        int numArc;
        cout << endl << "������� ����� ����, ������� ������ �������: " << endl;
        cin >> numArc;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "������������ ����." << endl;
            return;
        }

        if (numArc >= 0 && numArc <= matrix[0].size())
        {
            for (int i = 0; i < n; i++)
            {
                matrix[i].erase(matrix[i].begin() + numArc - 1);
            }
            m--;
            cout << "���� �������." << endl;
        }
        else
        {
            cout << "������������ ������." << endl;
            return;
        }
    }




    void BFS() 
    {
        int firstVertex;
        cout << "������� ����� �������, � ������� ������ ����� � ������." << endl;
        cin >> firstVertex;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "������������ ����." << endl;
            return;
        }

        firstVertex--;
        if ((firstVertex < 0) || (firstVertex > n))
        {
            cout << "������������ ������." << endl;
            return;
        }
        queue<int> q;
        q.push(firstVertex);
        vector<int> d(n, -1); //������������ �������
        vector<int> arcs(m, -1); // ������������ ����
        vector<int> count(n, 0); // ������� ��� ���������� ��������� ������ �������
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == -1)
                {
                    count[i]++;
                }
            }
        }
        //-----------�����
        cout << "���������� ��� ������������ � ������ �������:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << count[i] << "  ";
        }
        cout << endl;
        //-----------
        cout << "������ ������ � ������:" << endl;
        d[firstVertex] = -1;
        while(!q.empty())
        {

            int v = q.front();
            q.pop();
            for (int u = 0; u < m; u++) //u �������� �������� ���� � ������ �������
            {
                if (matrix[v][u] == 1) //����� ������ ����
                { 
                    for (int k = 0; k < n; k++) //k �������� ������� � ������� ������ ����� ����
                    {
                        if (matrix[k][u] == -1) //����� ������� � ������� � ������ ������� u �������� -1
                        {
                            if (arcs[u] == -1)
                            {
                                arcs[u]++;
                                if (d[k] == -1)
                                {
                                    q.push(k);
                                    if (count[k] == 0)
                                    {

                                        d[k]++;
                                    }
                                    else
                                    {
                                        count[k]--;
                                        cout << "�� ������� " << v + 1 << " � ������� " << k + 1 << endl;
                                    }

                                }
                            }
                           
                        }
                    }
                }
            }
        }
        cout << "����� � ������ �������." << endl;
    }

};
