#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <iterator>
#include <vector>

class Span
{
private:
	unsigned int capacity;
	std::vector<int> values;

public:
	Span();
	Span(unsigned int n);
	Span(const Span &other);
	~Span();

	Span &operator=(const Span &other);

	void addNumber(int number);

	template <typename Iterator>
	void addNumbers(Iterator first, Iterator last)
	{
		unsigned int count =
			static_cast<unsigned int>(std::distance(first, last));

		if (values.size() + count > capacity)
			throw FullException();

		values.insert(values.end(), first, last);
	}

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	class FullException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class NoSpanException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif