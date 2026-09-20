#include "RPN.hpp"

#include <exception>
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	try
	{
		std::cout << RPN::evaluate(av[1]) << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}