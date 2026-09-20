#include "PmergeMe.hpp"

#include <algorithm>
#include <cstddef>
#include <utility>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return *this;
}

static std::vector<int> fordJohnsonVector(const std::vector<int> &values)
{
	if (values.size() < 2)
		return values;

	typedef std::pair<int, int> Pair;

	std::vector<Pair> pairs;
	std::vector<int> larger;

	bool hasOdd = values.size() % 2 != 0;
	int odd = 0;

	if (hasOdd)
		odd = values[values.size() - 1];

	for (std::size_t i = 0; i + 1 < values.size(); i += 2)
	{
		int first = values[i];
		int second = values[i + 1];

		if (first < second)
			pairs.push_back(Pair(first, second));
		else
			pairs.push_back(Pair(second, first));

		larger.push_back(pairs.back().second);
	}

	larger = fordJohnsonVector(larger);

	std::vector<Pair> orderedPairs;
	std::vector<bool> used(pairs.size(), false);

	for (std::size_t i = 0; i < larger.size(); ++i)
	{
		for (std::size_t j = 0; j < pairs.size(); ++j)
		{
			if (!used[j] && pairs[j].second == larger[i])
			{
				orderedPairs.push_back(pairs[j]);
				used[j] = true;
				break;
			}
		}
	}

	std::vector<int> chain;

	chain.push_back(orderedPairs[0].first);

	for (std::size_t i = 0; i < orderedPairs.size(); ++i)
		chain.push_back(orderedPairs[i].second);

	std::size_t pendingCount = orderedPairs.size();

	if (hasOdd)
		++pendingCount;

	std::size_t previousJacobsthal = 1;
	std::size_t jacobsthal = 3;

	while (previousJacobsthal < pendingCount)
	{
		std::size_t groupEnd;

		if (jacobsthal < pendingCount)
			groupEnd = jacobsthal;
		else
			groupEnd = pendingCount;

		for (std::size_t position = groupEnd;
			position > previousJacobsthal;
			--position)
		{
			std::size_t index = position - 1;

			if (index < orderedPairs.size())
			{
				std::vector<int>::iterator partner = std::find(chain.begin(), chain.end(), orderedPairs[index].second);
				std::vector<int>::iterator insertionPosition = std::lower_bound(chain.begin(), partner, orderedPairs[index].first);

				chain.insert(insertionPosition, orderedPairs[index].first);
			}
			else
			{
				std::vector<int>::iterator insertionPosition = std::lower_bound(chain.begin(), chain.end(), odd);

				chain.insert(insertionPosition, odd);
			}
		}

		if (groupEnd == pendingCount)
			break;

		std::size_t nextJacobsthal = jacobsthal + 2 * previousJacobsthal;

		previousJacobsthal = jacobsthal;
		jacobsthal = nextJacobsthal;
	}

	return chain;
}

void PmergeMe::sortVector(std::vector<int> &values)
{
	values = fordJohnsonVector(values);
}

static std::deque<int> fordJohnsonDeque(const std::deque<int> &values)
{
	if (values.size() < 2)
		return values;

	typedef std::pair<int, int> Pair;

	std::deque<Pair> pairs;
	std::deque<int> larger;

	bool hasOdd = values.size() % 2 != 0;
	int odd = 0;

	if (hasOdd)
		odd = values[values.size() - 1];

	for (std::size_t i = 0; i + 1 < values.size(); i += 2)
	{
		int first = values[i];
		int second = values[i + 1];

		if (first < second)
			pairs.push_back(Pair(first, second));
		else
			pairs.push_back(Pair(second, first));

		larger.push_back(pairs.back().second);
	}

	larger = fordJohnsonDeque(larger);

	std::deque<Pair> orderedPairs;
	std::deque<bool> used(pairs.size(), false);

	for (std::size_t i = 0; i < larger.size(); ++i)
	{
		for (std::size_t j = 0; j < pairs.size(); ++j)
		{
			if (!used[j] && pairs[j].second == larger[i])
			{
				orderedPairs.push_back(pairs[j]);
				used[j] = true;
				break;
			}
		}
	}

	std::deque<int> chain;

	chain.push_back(orderedPairs[0].first);

	for (std::size_t i = 0; i < orderedPairs.size(); ++i)
		chain.push_back(orderedPairs[i].second);

	std::size_t pendingCount = orderedPairs.size();

	if (hasOdd)
		++pendingCount;

	std::size_t previousJacobsthal = 1;
	std::size_t jacobsthal = 3;

	while (previousJacobsthal < pendingCount)
	{
		std::size_t groupEnd;

		if (jacobsthal < pendingCount)
			groupEnd = jacobsthal;
		else
			groupEnd = pendingCount;

		for (std::size_t position = groupEnd;
			position > previousJacobsthal;
			--position)
		{
			std::size_t index = position - 1;

			if (index < orderedPairs.size())
			{
				std::deque<int>::iterator partner = std::find(chain.begin(), chain.end(), orderedPairs[index].second);
				std::deque<int>::iterator insertionPosition = std::lower_bound(chain.begin(), partner, orderedPairs[index].first);

				chain.insert(insertionPosition, orderedPairs[index].first);
			}
			else
			{
				std::deque<int>::iterator insertionPosition = std::lower_bound(chain.begin(), chain.end(), odd);

				chain.insert(insertionPosition, odd);
			}
		}

		if (groupEnd == pendingCount)
			break;

		std::size_t nextJacobsthal = jacobsthal + 2 * previousJacobsthal;

		previousJacobsthal = jacobsthal;
		jacobsthal = nextJacobsthal;
	}

	return chain;
}

void PmergeMe::sortDeque(std::deque<int> &values)
{
	values = fordJohnsonDeque(values);
}