
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

int g[MAX_N][MAX_N];
bool used[MAX_N];
int timer, tin[MAX_N], fup[MAX_N];
struct bridge
{
	int vertex1;
	int vertex2;
};
vector<bridge> bridges;
set<int> cutPoints;

void dfs(int v, int maxV, int parent = -1)
{
	used[v] = true;
	tin[v] = fup[v] = timer++;
	int children = 0;
	for (int i = 1; i <= maxV; ++i)
	{
		if (g[v][i] == 1)
		{
			int to = i;
			if (to == parent)
				continue;
			if (used[to])
				fup[v] = min(fup[v], tin[to]);
			else
			{
				dfs(to, maxV, v);
				if (fup[to] == tin[to])
				{
					bridges.push_back({ v, to });
				}
				fup[v] = min(fup[v], fup[to]);
				if (fup[to] >= tin[v] && parent != -1)
					cutPoints.insert(v);
				++children;
			}
		}
	}
	if (parent == -1 && children > 1)
		cutPoints.insert(v);
}

void find_bridges(const int maxV)
{
	timer = 0;
	for (int i = 1; i <= maxV; ++i)
		used[i] = false;
	for (int i = 1; i <= maxV; ++i)
		if (!used[i])
			dfs(i, maxV);
}

bool InitAdjacencyMatrix(std::istream& input, const int v, const int e)
{

	if (v <= 400 && v >= 1 && e >= 0 && e <= (v * (v - 1)) / 2)
	{
		int vi, vj;
		for (int i = 0; i < e; i++)
		{
			input >> vi >> vj;
			if (vi > v || vj > v)
			{
				cout << "Неверные данные \n";
				return false;
			}
			g[vi][vj] = 1;
			g[vj][vi] = 1;
		}
	}
	return true;
}

int main(const int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int maxV, e; // v количество вершин e -> количество ребер
	cin >> maxV >> e;

	if (!InitAdjacencyMatrix(cin, maxV, e))
	{
		return 1;
	}
	else
	{
		find_bridges(maxV);

		for (int p : cutPoints)
		{
			cout << p << " ";
		}
		cout << endl;
		for (bridge x : bridges)
		{
			cout << x.vertex2 << " ";
		}
		cout << endl;

		return 0;
	}
}
