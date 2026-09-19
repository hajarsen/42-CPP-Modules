#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

int main()
{
	// Test easyfind with a vector of integers.
	std::vector<int> values;
	values.push_back(4);
	values.push_back(8);
	values.push_back(15);

	// Test an existing value.
	try
	{
		std::vector<int>::iterator it = easyfind(values, 8);
		std::cout << "Vector found: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	// Test a value that does not exist.
	try
	{
		std::cout << "Searching for 42: ";
		std::cout << *easyfind(values, 42) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	// Test easyfind with a different type of STL container.
	std::list<int> numbers;
	numbers.push_back(10);
	numbers.push_back(20);
	numbers.push_back(30);

	try
	{
		std::list<int>::iterator it = easyfind(numbers, 20);
		std::cout << "List found: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	// Test the const overload, which returns a const_iterator.
	const std::vector<int> constValues(values);

	try
	{
		std::vector<int>::const_iterator it = easyfind(constValues, 15);
		std::cout << "Const vector found: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}