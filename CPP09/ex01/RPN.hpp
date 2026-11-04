#ifndef RPN_HPP
#define RPN_HPP

#include <string>

class RPN
{
	public:
		RPN();
		RPN(const RPN &other);
		~RPN();

		RPN &operator=(const RPN &other);

		static int evaluate(const std::string &expression);
};

#endif