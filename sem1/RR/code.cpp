#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int numberOfGraph = 0;
	string nameOfFile = "";
	cout << "������� ����� �����, ��� �������� ����: ";
	cin >> numberOfGraph;
	switch (numberOfGraph)
	{
	case 1: 
		nameOfFile = "graph.txt";
		break;
	case 2: 
		nameOfFile = "graph2.txt";
		break;
	case 3: 
		nameOfFile = "graph3.txt";
		break;
	case 4:
		nameOfFile = "graph4.txt";
		break;
	case 5:
		nameOfFile = "graph5.txt";
		break;
	default:
		break;
	}
	ifstream fin(nameOfFile);
	char temp = 'a';
	int count = 0;
	int N = 1;
	//������� ����� � ������
	for (; !fin.eof();)
	{
		temp = fin.get();
		if (temp != ' ' && temp != '\n' && !fin.eof())count++;
		if (temp == '\n') N++;
		if (temp == '\0') break;
	}
	fin.close();
	cout << "���-�� ��������� �������: " << count << endl;
	int M = N;
	cout <<"���-�� �����: "<< N << endl;
	cout << "���-�� ��������: " << M << endl;
	//�������� �� ������������ �������
	if (count != N * N)
	{
		cout << "� ���� ����� �� �������� ������� ���������.";
		return 0;
	}
	
	//�������� ������� � ������ �� �����
	fin.open(nameOfFile);
	int **matrix = new int*[N];
	for (int i = 0; i < N; i++)
	{
		matrix[i] = new int[M];
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			fin >> matrix[i][j];
		}
	}
	cout << '\n';

	bool isGraph=true;
	//�������� �� ���-�� ������
	if (N != 18 && M != 18) isGraph = false;
	//�������� �� ���������� � ������������ ������� ���������
	for (int i = 0; i < N; i++)
	{
		int count = 0;
		for (int j = 0; j < M; j++)
		{
			if (matrix[i][j] == 1)
			{
				count++;
				if (matrix[j][i] != 1) isGraph = false;
			}
		}
		if (count != 3) isGraph = false;
	}
	int countOfConnections = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (matrix[i][j] == 1)
			{
				countOfConnections++;
			}
		}
	}
	if (countOfConnections/2 != 27) isGraph = false;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << matrix[i][j];
			cout << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
	if (isGraph) cout << "���� ���� - ���� �����";
	else cout << "���� ���� �� �������� ������ �����";
	fin.close();
}