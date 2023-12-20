#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <set>

using namespace std;

// ����� � �������
void dfs1(int node, const vector<vector<int>>& graph, vector<bool>& visited, stack<int>& st)
{
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs1(neighbor, graph, visited, st);
        }
    }

    st.push(node);
}


void dfs2(int node, const vector<vector<int>>& graphT, vector<bool>& visited, set<int>& component)
{
    visited[node] = true;
    component.insert(node);

    for (int neighbor : graphT[node]) {
        if (!visited[neighbor]) {
            dfs2(neighbor, graphT, visited, component);
        }
    }
}

// �������� ������� ��������, ������ �� ������� ������ ������� ������������ "�����"
vector<vector<int>> createVectorsWithColors(const vector<vector<int>>& graph, const vector<vector<int>>& graphT)
{
    int n = int(graph.size());
    vector<bool> visited(n, false);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs1(i, graph, visited, st);
        }
    }

    visited.assign(n, false);

    vector<vector<int>> colorGraph;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (!visited[node])
        {
            set<int> component;
            dfs2(node, graphT, visited, component);
            vector<int> componentNodes(component.begin(), component.end());
            colorGraph.push_back(componentNodes);
        }
    }

    return colorGraph;
}



int main()
{
    setlocale(LC_ALL, "Russian");

    string fileChoice;
    cout << "�������� ����, �� �������� ����� ������������� ���� ������ (input_____.txt): ";
    cin >> fileChoice;
    string inFileName = "input" + fileChoice + ".txt";
    string outFileName = "output" + fileChoice + ".txt";

    ifstream fin(inFileName);
    if (!fin.is_open())
    {
        cerr << "\n������ �������� �����!\n";
        return 1;
    }

    ofstream fout(outFileName);
    
    int n; // ���������� ������
    int m; // ���������� ����
    int i, j;

    fin >> n >> m;

    // ������������� ������ ���������
    vector<vector<int>> graph(n);
    vector<vector<int>> graphT(n);

    // ���� m ���� ����� � ������� "u v", ��� u � v - ��������� � �������� ������� i-���� ����� ��������������
    for (i = 0; i < m; i++)
    {
        int u, v;
        fin >> u >> v;
        graph[u-1].push_back(v-1);
        graphT[v-1].push_back(u-1);
    }

    // �������� ������� ��������, ������ �� ������� ������ ������� ������������ "�����"
    vector<vector<int>> colorGraph = createVectorsWithColors(graph, graphT);

    // ���� "����" ����� ����, �� ��������� "1" ��� ������������ �������
    // ������������� ����� �����������
    if (colorGraph.size() == 1)
    {
        fout << "���� �����������:\n1";
    }
    else
    {
        // �������� �������, ��������� "����" ������ ��������� ������� �����
        // (i-��� ������� ������� ������ "����" i-��� ������� ������������ �����)
        int* color = new int[n];
        for (i = 0; i < colorGraph.size(); i++)
        {
            for (int g : colorGraph[i])
            {
                color[g] = i;
            }
        }

        // �������� ����� �����������
        set<string> gk;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < graph[i].size(); j++)
            {
                string coli = to_string(color[i]+1);
                string colj = to_string(color[graph[i][j]]+1);

                // ���� ������ ������� ������� ������� "�����",
                // �������� ����� � ���� �����������
                if (coli != colj)
                {
                    string pp = coli + " " + colj;
                    gk.insert(pp);
                }
            }
        }

        // ����� ����������
        fout << "���� �����������:";
        set<string>::iterator it;
        for (it = gk.begin(); it != gk.end(); it++)
        {
            fout << "\n" << *it;
        }
    }
    cout << "\n��������� ��������� � ����� \"" << outFileName << "\".\n";
}