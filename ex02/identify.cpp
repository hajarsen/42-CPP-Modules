#include "identify.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void)
{
    static bool isSeeded = false;

    if (!isSeeded)
    {
        std::srand(static_cast<unsigned int>(std::time(NULL)));
        isSeeded = true;
    }
    switch (std::rand() % 3)
    {
    case 0:
        return new A;
    case 1:
        return new B;
    default:
        return new C;
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (const std::exception&)
    {
        try
        {
            (void)dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        }
        catch (const std::exception&)
        {
            (void)dynamic_cast<C&>(p);
            std::cout << "C" << std::endl;
        }
    }
}
