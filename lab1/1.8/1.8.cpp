
#include "pch.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <boost/timer.hpp>
#include <utility>

using namespace std;
struct SetOfThings {
	vector<int> isTaken;
	int weight = 0;
	int cost = 0;
};

void PrintSetOfThings(const vector<int>& b, const int weight, const int cost)
{
	for (size_t i = 0; i < b.size() - 1; i++)
	{
		printf("%3d", i + 1);
	}
	cout << "\n";
	for (size_t i = 0; i < b.size() - 1; i++)
	{
		if (b[i] != 0)
		{
			printf("%3d", 1);

		}
		else
		{
			printf("%3d", 0);
		}
	}
	cout << " вес:" << weight << " стоимость: " << cost << "\n";
}
void CheckSetOfThings(const vector<int>& b, const vector<int>& w, const vector<int>& c, const int maxWeight, const int minCost, SetOfThings &bestSet)
{
	int weight = 0;
	int cost = 0;

	for (size_t i = 0; i < b.size() - 1; i++)
	{
		if (b[i] != 0)
		{
			weight += w[i];
			cost += c[i];

		}
	}
	if (weight <= maxWeight && cost >= minCost)
	{
		PrintSetOfThings(b, weight, cost);
		if ((cost > bestSet.cost) || (cost == bestSet.cost && weight < bestSet.weight)) {
			bestSet.isTaken = b;
			bestSet.cost = cost;
			bestSet.weight = weight;
		}
	}
}

int main(const int argc, char* argv[]) {
	{
		setlocale(LC_ALL, "Russian");
		size_t n, T, S;
		cin >> n >> T >> S;

		boost::timer time;
		time.restart();

		vector<int> w(n);
		vector<int> c(n);
		for (size_t i = 0; i < n; i++)
		{
			cin >> w[i] >> c[i];
		}
		
		vector<int> isTaken(n + 1, 0);
		SetOfThings bestSet;
		bestSet.isTaken = isTaken;
		int i;
		while (isTaken[n] != 1)
		{
			CheckSetOfThings(isTaken, w, c, T, S, bestSet);
			i = 0;
			while (isTaken[i] == 1)
			{
				isTaken[i] = 0;
				i++;
			}
			isTaken[i] = 1;
		}
		cout << "Лучший: \n";
		PrintSetOfThings(bestSet.isTaken, bestSet.weight, bestSet.cost);

		printf("Time: %.4f \n", time.elapsed());

		return 0;
	}
}