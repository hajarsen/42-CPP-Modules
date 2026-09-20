#include "RPN.hpp"

#include <sstream>
#include <stack>
#include <stdexcept>

RPN::RPN()
{
}

RPN::RPN(const RPN &other)
{
	(void)other;
}

RPN::~RPN()
{
}

RPN &RPN::operator=(const RPN &other)
{
	(void)other;
	return *this;
}

int RPN::evaluate(const std::string &expression)
{
	std::istringstream input(expression);
	std::stack<int> values;
	std::string token;

	while (input >> token)
	{
		if (token.size() == 1
			&& token[0] >= '0'
			&& token[0] <= '9')
		{
			values.push(token[0] - '0');
		}
		else if (token.size() == 1
			&& (token[0] == '+'
				|| token[0] == '-'
				|| token[0] == '*'
				|| token[0] == '/'))
		{
			if (values.size() < 2)
				throw std::runtime_error("Error");

			int right = values.top();
			values.pop();

			int left = values.top();
			values.pop();

			if (token[0] == '+')
				values.push(left + right);
			else if (token[0] == '-')
				values.push(left - right);
			else if (token[0] == '*')
				values.push(left * right);
			else
			{
				if (right == 0)
					throw std::runtime_error("Error");

				values.push(left / right);
			}
		}
		else
		{
			throw std::runtime_error("Error");
		}
	}

	if (values.size() != 1)
		throw std::runtime_error("Error");

	return values.top();
}