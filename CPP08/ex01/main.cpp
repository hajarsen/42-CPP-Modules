#include "Span.hpp"

#include <exception>
#include <iostream>
#include <vector>

int main()
{
	// Test from the subject:
	// shortest span = 2, longest span = 14.
	try
	{
		Span sp(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}

	// Test exception when there are fewer than two numbers.
	try
	{
		Span empty(5);

		empty.shortestSpan();
	}
	catch (const std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}

	// Test exception when adding more numbers than the capacity.
	try
	{
		Span full(2);

		full.addNumber(10);
		full.addNumber(20);
		full.addNumber(30);
	}
	catch (const std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}

	// Test addNumbers with 10,000 values, as required by the subject.
	try
	{
		std::vector<int> numbers(10000, 42);
		Span large(10000);

		large.addNumbers(numbers.begin(), numbers.end());

		std::cout << large.shortestSpan() << std::endl;
		std::cout << large.longestSpan() << std::endl;
	}
	catch (const std::exception &exception)
	{
		std::cout << exception.what() << std::endl;
	}

	return 0;
}