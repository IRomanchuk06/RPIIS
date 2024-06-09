#include "biblioteka.h"
#include <iostream>

// �������� ����� ��� ����������

int main() {
    setlocale(LC_ALL,"Ru");
    // �������� ����� � 5 ���������
    Graph* graph = createGraph(5);

    // ���������� ���
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    cout << "����� � ������ (��������� ������� 2): ";
    BFS(graph, 2);

    // �������� ����
    removeEdge(graph, 2, 0);
    cout << "\n����� � ������ ����� �������� ���� (2, 0): ";
    BFS(graph, 2);

    return 0;
}
