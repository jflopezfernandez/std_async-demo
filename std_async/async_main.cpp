
#include <iostream>
#include <future>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <numeric>
#include <algorithm>
#include <random>
#include <iterator>
#include <functional>


int increment(int n)
{
	return (n + 1);
}


std::set<int> MakeSortedRandomSet(const size_t n);


int main()
{
	// Experimenting with async/parallelism
	auto p1 = std::async(std::launch::async, MakeSortedRandomSet, 100'000);
	p1.get();


	return EXIT_SUCCESS;
}


std::set<int> MakeSortedRandomSet(const size_t n)
{
	std::set<int> returnSet;
	std::random_device rd;
	std::mt19937 gen(rd());		//Mersenne Twister Random Number Generator
	std::uniform_int_distribution<> distribution(0, n - 1);

	std::generate_n(std::inserter(returnSet, returnSet.end()), n, [&]() { return distribution(gen); } );


	return returnSet;
}


