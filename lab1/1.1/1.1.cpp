

#include "pch.h"
#include <iostream>

#include "stdlib.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include <boost/timer.hpp>

int main()
{
	std::vector<size_t> v = { 7, 1, 12, 5, 9, 20, 15 ,13, 17, 2, 3, 7, 10 };
	boost::timer t;
	t.restart();
	std::sort(v.begin(), v.end());
	do
	{
		//copy(v.begin(), v.end(), std::ostream_iterator<size_t>(std::cout, " "));
		//std::cout << std::endl;
	} while (std::next_permutation(v.begin(), v.end()));
	double duration = t.elapsed();
	std::cout << duration << std::endl;
	return 0;
}
/*
	С выводом: 7-> 3.441 с
	Без вывода:
	10-> 0.019
	11-> 0.209
	12-> 1.247
	13-> 14.986

	15-> ~ 3147,06
	20-> ~ 5855042188,8 : 188,2408111111111 лет
	50-> 2,3209921810529654877596964673176e+40 млрд лет

*/
