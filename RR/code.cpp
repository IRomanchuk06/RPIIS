﻿#include <iostream>
#include <vector>

using namespace std;

bool isGraphRegular(const vector<vector<int>>& graph) {
    int col = graph.size();
    int degree = graph[0].size();

    // Проверка на пустой граф
    if (col == 0) {
        return true;
    }

    // Проверка степени остальных вершин
    for (int i = 1; i < col; ++i) {
        if (graph[i].size() != degree) {
            return false;
        }
    }

    return true;
}

bool isGraphEdgeRegular(const vector<vector<int>>& graph) {
    if (!isGraphRegular(graph))
    {
        return false;
    }

    int col = graph.size();
    int degree = graph[0].size();
    int lambda = 0;

    for (int i = 0; i < col; i++)
    {
        int countNeigh = 0;
        for (int j = 0; j < col; j++)
        {
            for (int k = 0;  k < degree;  k++)
            {
                if (i == graph[j][k])
                {
                    countNeigh++;
                }
            }
        }
        if (i==0)
        {
            lambda = countNeigh;
        }
        if (countNeigh == lambda)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
}

int main() {
    vector<vector<int>> graph_1{
        {2, 4},
        {1, 3},
        {2, 4},
        {1, 3}
    };

    vector<vector<int>> graph_2{
        {2, 4, 5},
        {1, 3, 6},
        {2, 4, 7},
        {1, 3, 8},
        {1, 6, 8},
        {2, 5, 7},
        {3, 6, 8},
        {4, 5, 7}
    };

    // Проверка первого графа на его вид
    if (isGraphRegular(graph_1)) {
        cout << "Graph_1 is not regular." << endl;
    }
    else if (isGraphEdgeRegular(graph_1)) {
        cout << "Graph_2 is Edge Regular Graph." << endl;
    }
    else {
        cout << "Graph_2 is Regular Graph." << endl;
    }

    // Проверка второго графа на его вид
    if (isGraphRegular(graph_2)) {
        cout << "Graph_2 is not regular." << endl;
    }
    else if (isGraphEdgeRegular(graph_2)) {
        cout << "Graph_2 is Edge Regular Graph." << endl;
    }
    else {
        cout << "Graph_2 is Regular Graph." << endl;
    }
}