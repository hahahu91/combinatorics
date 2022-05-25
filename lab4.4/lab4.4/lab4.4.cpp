// lab4.4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int sum(int si_a, int si_b)
{
	if (((si_b > 0) && (si_a > (numeric_limits<int>::max() - si_b))) || ((si_b < 0) && (si_a < (numeric_limits<int>::max() - si_b))))
	{
		return numeric_limits<int>::max();
	}
	else
	{
		return si_a + si_b;
	}
}

int sub(int si_a, int si_b)
{
	if ((si_b > 0 && si_a < numeric_limits<int>::min() + si_b) || (si_b < 0 && si_a > numeric_limits<int>::max() + si_b))
	{
		return si_a;
	}
	else
	{
		return si_a - si_b;
	}
}

void hungarianAlgorithm(vector<vector<int>>& a, int n)
{
	vector<int> u(n + 1), v(n + 1), p(n + 1), way(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		p[0] = i; // для удобства реализации
		int j0 = 0; // свободный столбец
		vector<int> minv(n + 1, numeric_limits<int>::max()); //заполняем массивы minv — INF ,
		vector<bool> used(n + 1, false);  //used — false
		do // ищем свободный столбец 
		{
			used[j0] = true; 
			int i0 = p[j0], delta = numeric_limits<int>::max(), j1=0; // помечаем посещенными столбец j0 и строку i0
			for (int j = 1; j <= n; ++j) //пересчитываем массив minv,находим в нем минимум deltu (изначально INF) и столбец j1, в котором он достигнут
				if (!used[j])
				{
					int cur = sub(sub(a[i0][j], u[i0]), v[j]);
					if (cur < minv[j])
						minv[j] = cur, way[j] = j0;
					if (minv[j] < delta)
						delta = minv[j], j1 = j;
				}
			
			for (int j = 1; j <= n; ++j) // производим пересчет потенциала u и v, соответствующее изменение minv
				if (used[j])
					u[p[j]] = sum(u[p[j]], delta), v[j] = sub(v[j], delta);
				else
					minv[j] = sub(minv[j], delta);
			j0 = j1;
		} while (p[j0] != 0); // если нашли свободный столбец — выходим из цикла
		do //ищем увеличивающуюся цепочку, пользуясь массивом предков way
		{
			int j1 = way[j0];
			p[j0] = p[j1];
			j0 = j1;
		} while (j0);
	}
	vector<int> ans(n + 1);
	for (int j = 1; j <= n; ++j)
		ans[p[j]] = j;

	for (int j = 1; j <= n; ++j)
	{
		int cost = a[j][ans[j]];
		cout << j << "=>" << ans[j] << " cost: " << cost << endl;
	}
}


int main()
{
	int n;
	cin >> n;

	vector<vector<int>> a(n+1, vector<int>(n+1));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int cur; 
			cin >> cur;
			cur == 1000 ? a[i][j] = numeric_limits<int>::max() : a[i][j] = cur;
		}
	}
	hungarianAlgorithm(a, n);

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
