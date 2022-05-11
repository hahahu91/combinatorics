﻿// lab3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

double det(std::vector<std::vector<double>> a, int n)
{
	const double EPS = 1E-9;
	double det = 1;
	for (int i = 0; i < n; ++i)
	{
		int k = i;
		for (int j = i + 1; j < n; ++j)
			if (abs(a[j][i]) > abs(a[k][i]))
				k = j;
		if (abs(a[k][i]) < EPS)
		{
			det = 0;
			break;
		}
		swap(a[i], a[k]);
		if (i != k)
			det = -det;
		det *= a[i][i];
		for (int j = i + 1; j < n; ++j)
			a[i][j] /= a[i][i];
		for (int j = 0; j < n; ++j)
			if (j != i && abs(a[j][i]) > EPS)
				for (int k = i + 1; k < n; ++k)
					a[j][k] -= a[i][k] * a[j][i];
	}

	return det;
}
int main()
{
	
	int n;
	std::cin >> n;
	std::vector<std::vector<double>> a(n, std::vector<double>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if(!(std::cin >> a[i][j]))
			{
				std::cout << "no correct data";
				return 1;
			}
		}
	}

	std::cout << det(a, n-1);
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
