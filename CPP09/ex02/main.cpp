#include "PmergeMe.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
static bool parse(const char *s, int &v) {
	char *e;
	long n = strtol(s, &e, 10);
	if (e == s || *e || n <= 0 || n > 2147483647)
		return false;
	v = static_cast<int>(n);
	return true;
}
template <class C> static void display(const C &c) {
	for (typename C::const_iterator i = c.begin(); i != c.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
}
int main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	std::vector<int> v;
	for (int i = 1; i < ac; ++i) {
		int n;
		if (!parse(av[i], n)) {
			std::cerr << "Error" << std::endl;
			return 1;
		}
		v.push_back(n);
	}
	std::deque<int> d(v.begin(), v.end());
	std::cout << "Before: ";
	display(v);
	clock_t s = clock();
	PmergeMe::sortVector(v);
	clock_t e = clock();
	clock_t ds = clock();
	PmergeMe::sortDeque(d);
	clock_t de = clock();
	std::cout << "After: ";
	display(v);
	std::cout << "Time to process a range of " << v.size() << " elements with std::vector : "
			  << static_cast<double>(e - s) * 1000000 / CLOCKS_PER_SEC << " us" << std::endl;
	std::cout << "Time to process a range of " << d.size() << " elements with std::deque : "
			  << static_cast<double>(de - ds) * 1000000 / CLOCKS_PER_SEC << " us" << std::endl;
}
