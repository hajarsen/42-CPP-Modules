#include "BitcoinExchange.hpp"

#include <iostream>
#include <exception>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: usage: ./btc input.txt" << std::endl;
		return 1;
	}

	try
	{
		BitcoinExchange bitcoinExchange;

		bitcoinExchange.loadDatabase("data.csv");
		bitcoinExchange.process(av[1]);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}