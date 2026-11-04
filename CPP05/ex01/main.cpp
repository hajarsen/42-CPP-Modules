#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>
int main()
{
    try
    {
        Bureaucrat chief("Chief", 1);
        Bureaucrat intern("Intern", 150);
        Form confidential("Confidential report", 20, 10);
        std::cout << confidential << std::endl;
        intern.signForm(confidential);
        chief.signForm(confidential);
        std::cout << confidential << std::endl;
        Form invalid("Invalid", 0, 10);
        (void)invalid;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
