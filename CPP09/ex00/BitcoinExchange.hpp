#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange();
		BitcoinExchange &operator=(const BitcoinExchange &other);

		void loadDatabase(const std::string &file);
		void process(const std::string &file) const;

	private:
		std::map<std::string, double> _rates;

		static bool validDate(const std::string &date);
		static bool parseValue(const std::string &text, double &value);
};

#endif