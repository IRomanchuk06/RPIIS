#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

/*�������� �� �������������� ��������� ���������� ������*/
bool find(vector<int> visited, int elem) {
	for (int el : visited)
		if (el == elem)
			return true;

	return false;
}

bool ThisIsTheWay(vector<vector<int>> graph,  int predok,  int potomok) {

	vector<int> visited;

	visited.reserve(100);

	vector<int> tmp;

	visited.push_back(predok);

	int size = 0;

	while (true) {

		for (int a: tmp)
			if (!find(visited, a))
				visited.push_back(a);

		if (size != visited.size()) {

			size = visited.size();

			for (int v: visited)
				
				for (int el : graph[v])

						if (!find(visited, el) && !(el == potomok && v == predok))
							tmp.push_back(el);		
		}
		else {
			if (find(visited, potomok))
				return true;
			else
				return false;
		}
	}
}

int main() {

	setlocale(LC_ALL, "russian");

	vector<vector<int>> graph;

	string file;

	cout << "������� �������� �����: "; cin >> file;

	ifstream graphfile(file);

		/*���� �������� �� �����*/
	if (graphfile.is_open()) {

		string accident;

		while (getline(graphfile, accident)) {

			int vertex;
			int tmp;
			int n(0);

			istringstream vertexes(accident);

			while (vertexes >> vertex) {
				n++;
				if (n == 1) {
					tmp = vertex;
					graph.push_back(vector<int>());
				}
				else
					graph[tmp].push_back(vertex);
			}
		}
	}

	else
		std:: cout << "������ ��� �������� �����!";

	std :: cout << "����� � �����: " << endl;

	for (int predok = 0; predok < graph.size(); predok++)

		for (int potomok : graph[predok])
			if (!ThisIsTheWay(graph, predok, potomok))
				std :: cout << predok << "->" << potomok << endl;

	return 0;
}