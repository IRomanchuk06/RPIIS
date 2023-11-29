﻿// Graph components.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale>
#include <Windows.h>
#include <fstream>
#include <locale>
#include <stdio.h>
using namespace std;
int comp[100];


int set(int k)
{
	while (k != comp[k]) 
		k = comp[k];
	return k;
}
void join(int i, int j)

{
	i = set(i);
	j = set(j);
	if (i != j) comp[i] = j;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "RUSSIAN");
	
	int n,k,i,j,count;
	
	
	ifstream fin("a.txt");

	fin >> n;
	for (i = 1; i <= n; i++) comp[i] = i;

     cout << "Введите матрицу смежности графа\n";

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			{
			fin >> k;
				if ((i < j)&&(k)) join(i, j);
			}
	fin.close();

	count = 0;
	for (i = 1; i <= n; i++)
		if (comp[i] == i) count++;

	cout << "Количество компонент связанности\n";
	cout<<  count;
return 0;
}


//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
