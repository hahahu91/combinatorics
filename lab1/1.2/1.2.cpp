// 1.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
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
	copy(v.begin()+1, v.end()-1, ostream_iterator<size_t>(cout));
	cout << "\n";
}

int main(const int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Invalid count of arguments";
		return 1;
	}
	const size_t sizeArray = atoi(argv[1]);
	vector<size_t> pi(sizeArray + 2);
	vector<size_t> p(sizeArray + 2);
	iota(pi.begin(), pi.end(), 0);
	p = pi;

	vector<int> d(sizeArray + 2);
	fill(d.begin()+1, d.end()-1, -1);

	boost::timer time;
	time.restart();

	const int borderNumber = sizeArray + 1;
	d[1] = 0;
	pi[0] = borderNumber;
	pi[sizeArray + 1] = borderNumber;
	int m = borderNumber;
	int n = sizeArray;

	while (m != 1) 
	{
		//Print(pi);
		m = n;
		while ((pi[p[m] + d[m]]) > m)
		{
			d[m] = -d[m];
			m--;
		}
		swap(pi[p[m]], pi[p[m] + d[m]]);
		swap(p[pi[p[m]]], p[m]);
	}
	printf("Time: %.2f \n", time.elapsed());

	return 0;

}

// 10 -> 9.19s
// 9-> 0.92s
// ~15 -> 3311708,4 s => 38,32 days
// ~20 -> 71312120,88 days => 195375,67 years
// ~50 2,442422229740591742999461075501e+51 years
//
//
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
