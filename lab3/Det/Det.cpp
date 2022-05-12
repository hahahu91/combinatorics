// Det.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

double Det(vector<vector<double>>& a, int n)
{
	double tmp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int k = i + 1; k < n; k++)
		{
			tmp = -a[k][i] / a[i][i];
			for (int j = 0; j < n; j++)
			{
				a[k][j] += a[i][j] * tmp;
			}
		}
	}
	double d = 1;
	for (int i = 0; i < n; i++)
	{
		d *= a[i][i];
	}
	return d;
}

void PrintMatrix(vector<vector<double>>& a, int n)
{
	cout.precision(2);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(8);
			cout << fixed << a[i][j] << " ";
		}
		cout << endl;
	}
}
void AdjMatToKirgofMat(vector<vector<double>>& a, int n)
{
	
	for (int i = 0; i < n; i++)
	{
		a[i][i] = 0;
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j= 0; j < n; j++)
		{
			if (i != j && a[i][j] != 0)
			{
				a[i][j] = -1;
				a[i][i] += 1;
			}
		}
	}
	return;

}

int main()
{
	int n;

	cin >> n;

	vector<vector <double>> a(n, vector<double>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	AdjMatToKirgofMat(a, n);

	cout << fixed << "Matrix determinant: " << Det(a, n - 1) << endl;
	PrintMatrix(a, n);

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
