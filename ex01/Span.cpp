#include "Span.hpp"

#include <algorithm>

Span::Span() : capacity(0)
{
}

Span::Span(unsigned int n) : capacity(n)
{
}

Span::Span(const Span &other)
	: capacity(other.capacity), values(other.values)
{
}

Span::~Span()
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		capacity = other.capacity;
		values = other.values;
	}
	return *this;
}

void Span::addNumber(int number)
{
	if (values.size() >= capacity)
		throw FullException();

	values.push_back(number);
}

unsigned int Span::shortestSpan() const
{
	if (values.size() < 2)
		throw NoSpanException();

	std::vector<int> copy(values);

	std::sort(copy.begin(), copy.end());

	unsigned int result =
		static_cast<unsigned int>(copy[1])
		- static_cast<unsigned int>(copy[0]);

	for (std::size_t i = 2; i < copy.size(); ++i)
	{
		unsigned int span =
			static_cast<unsigned int>(copy[i])
			- static_cast<unsigned int>(copy[i - 1]);

		if (span < result)
			result = span;
	}

	return result;
}

unsigned int Span::longestSpan() const
{
	if (values.size() < 2)
		throw NoSpanException();

	int minimum =
		*std::min_element(values.begin(), values.end());

	int maximum =
		*std::max_element(values.begin(), values.end());

	return static_cast<unsigned int>(maximum)
		- static_cast<unsigned int>(minimum);
}

const char *Span::FullException::what() const throw()
{
	return "Span is full";
}

const char *Span::NoSpanException::what() const throw()
{
	return "Not enough numbers";
}