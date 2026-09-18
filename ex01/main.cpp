#include "iter.hpp"
#include <iostream>

template <typename T>
void print(const T &value) 
{ 
	std::cout << value << std::endl;
}

void increment(int &value)
{
	++value;
}


int main() {
	int values[] = {1, 2, 3};
	iter(values, 3, increment);
	iter(values, 3, print<int>);
	const char *words[] = {"template", "iter"};
	iter(words, 2, print<const char *>);
}
