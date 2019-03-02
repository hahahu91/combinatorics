// 1.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <boost/timer.hpp>
#include <utility>

using namespace std;

void Print(const vector<size_t>& v)
{
	copy(v.begin(), v.end(), ostream_iterator<size_t>(cout, " "));
	cout << "\n";
}

void getRandomPermutation(vector<size_t>& v) {
	const int n = v.size();
	int j;
	for (int i = 0; i < n; i++) {
		j = rand() % n;
		swap(v[i], v[j]);
	}
}

int main(const int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid count of arguments";
		return 1;
	}
	const size_t sizeArray = atoi(argv[1]);
	vector<size_t> v(sizeArray);
	iota(v.begin(), v.end(), 1);

	srand(time(NULL));

	Print(v);
	getRandomPermutation(v);
	Print(v);

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
