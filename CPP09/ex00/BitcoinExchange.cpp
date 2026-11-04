#include "BitcoinExchange.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
	: _rates(other._rates)
{
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_rates = other._rates;

	return *this;
}

bool BitcoinExchange::validDate(const std::string &date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	for (size_t i = 0; i < date.size(); ++i)
	{
		if (i != 4 && i != 7 && (date[i] < '0' || date[i] > '9'))
			return false;
	}

	int year = (date[0] - '0') * 1000
		+ (date[1] - '0') * 100
		+ (date[2] - '0') * 10
		+ (date[3] - '0');

	int month = (date[5] - '0') * 10 + (date[6] - '0');
	int day = (date[8] - '0') * 10 + (date[9] - '0');

	if (year < 1 || month < 1 || month > 12 || day < 1)
		return false;

	int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		days[1] = 29;

	return day <= days[month - 1];
}

bool BitcoinExchange::parseValue(
	const std::string &text,
	double &value)
{
	std::istringstream input(text);

	input >> value;

	return !input.fail() && input.eof();
}

void BitcoinExchange::loadDatabase(const std::string &file)
{
	std::ifstream input(file.c_str());

	if (!input)
		throw std::runtime_error("could not open database");

	std::string line;

	getline(input, line);

	while (getline(input, line))
	{
		size_t separator = line.find(',');
		double value;

		if (separator != std::string::npos
			&& validDate(line.substr(0, separator))
			&& parseValue(line.substr(separator + 1), value))
		{
			_rates[line.substr(0, separator)] = value;
		}
		if (_rates.empty())
			throw std::runtime_error("database is empty");
	}
}

void BitcoinExchange::process(const std::string &file) const
{
	std::ifstream input(file.c_str());

	if (!input)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;

	getline(input, line);

	while (getline(input, line))
	{
		size_t separator = line.find(" | ");

		if (separator == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, separator);
		std::string text = line.substr(separator + 3);
		double value;

		if (!validDate(date))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (!parseValue(text, value))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}

		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		std::map<std::string, double>::const_iterator it;

		it = _rates.upper_bound(date);

		if (it == _rates.begin())
		{
			std::cerr << "Error: no rate available for "
					  << date << std::endl;

			continue;
		}

		--it;

		std::cout << date << " => " << value
				  << " = " << value * it->second
				  << std::endl;
	}
}