#include "identify.hpp"

#include <iostream>

int main()
{
    Base* object = generate();

    std::cout << "identify(Base*): ";
    identify(object);
    std::cout << "identify(Base&): ";
    identify(*object);
    delete object;
    return 0;
}