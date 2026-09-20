#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <vector>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		~PmergeMe();

		PmergeMe &operator=(const PmergeMe &other);

		static void sortVector(std::vector<int> &values);
		static void sortDeque(std::deque<int> &values);
};

#endif