
#include "pch.h"
#include <algorithm>
#include <boost/timer.hpp>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <set>
#include <utility>
#include <vector>
#define MAX_N 400
using namespace std;

struct times
{
	int vertex;
	int in;
	int out;
};

int g[MAX_N][MAX_N], gr[MAX_N][MAX_N];
bool used[MAX_N];
//int time_in[MAX_N], time_out[MAX_N];
int dfs_timer = 0; // "таймер" для определения времён
times t[MAX_N];
vector<vector<int>> component;


void dfs(int v, int maxV)
{
	used[v] = true;
	t[v].vertex = v;
	t[v].in = ++dfs_timer;
	for (int i = 1; i <= maxV; ++i)
	{
		if (g[v][i] == 1)
		{
			if (!used[i])
			{
				dfs(i, maxV);
			}
		}
	}
	t[v].out = ++dfs_timer;
}
void dfs2(int v, int maxV)
{
	used[v] = true;
	for (int i = 1; i <= maxV; ++i)
	{
		if (gr[v][i] == 1)
		{
			if (!used[i])
			{
				dfs2(i, maxV);
			}
		}
	}
}

bool InitAdjacencyMatrix(std::istream& input, const int v)
{
	int e;
	if (v <= 400 && v >= 1)
	{
		for (int i = 1; i <= v; i++)
		{
			for (int j = 1; j <= v; j++)
			{
				if (!(input >> e))
				{ 
					cout << "Неверно заданы входные данные \n";
					return false;
				}
				g[i][j] = e;
				gr[j][i] = e;
			}
		}
	}
	return true;
}

bool SortOnTimeOut(const times t1, const times t2)
{
	return t1.out > t2.out;
}

void PrintTimeOut(const int v)
{
	for (int i = 1; i <= v; i++)
	{
		cout << t[i].out << "[" << t[i].vertex << "]"
			 << " ";
	}
	cout << endl;
}

void CheckStrongConnectivity(const int maxV)
{
	dfs_timer = 0;
	for (int i = 1; i <= maxV; ++i)
		used[i] = false;
	for (int i = 1; i <= maxV; ++i)
		if (!used[i])
			dfs(i, maxV);
	
	PrintTimeOut(maxV);
	sort(&t[1], &t[maxV] + 1, SortOnTimeOut);
	PrintTimeOut(maxV);

	for (int i = 1; i <= maxV; ++i)
		used[i] = false;
	int countComponent = 0;
	for (int i = 1; i <= maxV; ++i)
	{
		int v = t[i].vertex;
		if (!used[v])
		{
			dfs2(v, maxV);
			countComponent++;
		}
	}
	if (countComponent == 1)
	{
		std::cout << "yes\n";
	}
	else
	{
		std::cout << "no\n";
	}

}

int main(const int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int maxV;
	cin >> maxV;

	if (!InitAdjacencyMatrix(cin, maxV))
	{
		return 1;
	}
	else
	{
		CheckStrongConnectivity(maxV);

		return 0;
	}
}
