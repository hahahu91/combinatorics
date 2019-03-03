
#include "pch.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <boost/timer.hpp>
#include <utility>

using namespace std;

void Print(const vector<int>& v)
{
	copy(v.begin() + 1, v.end(), ostream_iterator<int>(cout, " "));
	cout << "\n";
}

int main(const int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid count of arguments";
		return 1;
	}
	const size_t n = atoi(argv[1]);
	const size_t k = atoi(argv[2]);
	vector<int> a(k + 1);
	iota(a.begin() + 1, a.end(), 1);
	a[0] = -1;

	boost::timer time;
	time.restart();

	int m = 1;
	while (m != 0)
	{
		do {
			//Print(a);
		} while (next_permutation(a.begin() + 1, a.end()));
		m = k;
		while (a[m] == n - k + m)
			--m;
		++a[m];
		for (size_t i = m + 1; i <= k; ++i)
		{
			a[i] = a[i - 1] + 1;
		}
	}
	printf("Time: %.4f \n", time.elapsed());

	return 0;
}
// k 5 n 10 => 0.0730
// k 5 n 20 => 4.4710
// k 5 n 50 => 4,6577232405253136427225992041226e+45 s
// k 5 n 100 => 1,4292311124996585442500777953501e+139 s