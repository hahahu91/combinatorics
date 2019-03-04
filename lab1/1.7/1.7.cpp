
#include "pch.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <boost/timer.hpp>
#include <utility>

using namespace std;

void Print(const vector<int>& v, const size_t m)
{
	copy(v.begin() + 1, v.begin() + m + 1, ostream_iterator<int>(cout, " "));
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
		vector<int> b(n + 2);
		fill(b.begin() + 1, b.end(), 1);

		boost::timer time;
		time.restart();
		

		size_t k = n;
		unsigned int i = 0;
		int sum;

		Print(b, k);
		while (k != 1)
		{ 
			i = k - 1;
			while (!(i == 1 || b[i-1] > b[i]))
			{
				i--;
			}
			b[i] = b[i]++;
			sum = 0;
			for (int j = i + 1; j <= k; j++)
			{
				sum = sum + b[j];
			}
			for (int j = 1; j <= sum - 1; j++)
			{
				b[i + j] = 1;
			}

			k = i + sum - 1;
			Print(b, k);
		}

		printf("Time: %.4f \n", time.elapsed());

		return 0;
	}
}