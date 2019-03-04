
#include "pch.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <boost/timer.hpp>
#include <utility>

using namespace std;

void PrintSet(const vector<int>& v)
{
	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (v[i] != 0)
		{
			cout << i << ' ';
		}
	}
	cout << "\n";
}

int main(const int argc, char* argv[]) {
	{
		if (argc != 2)
		{
			cout << "Invalid count of arguments";
			return 1;
		}
		const size_t n = atoi(argv[1]);
		vector<int> b(n+1);
		fill(b.begin(), b.end(), 0);

		boost::timer time;
		time.restart();
		int i;
		while (b[n] != 1)
		{
			PrintSet(b);
			i = 0;
			while (b[i] == 1)
			{
				b[i] = 0;
				i++;
			}
			b[i] = 1;
		}
		printf("Time: %.4f \n", time.elapsed());

		return 0;
	}
}
// n 10 => 0.0010
// n 10 => 0.2050 c печатью
// n 20 => 0.9790 без печати.
// n 20 => 507.0770 c печатью