#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    Intern intern;
    Bureaucrat boss("Boss", 1);

    std::cout << "=== FORM CREATION ===" << std::endl;

    AForm* shrub = intern.makeForm("shrubbery creation", "garden");
    AForm* robot = intern.makeForm("robotomy request", "Bender");
    AForm* pardon = intern.makeForm("presidential pardon", "Arthur");

    std::cout << *shrub << std::endl;
    std::cout << *robot << std::endl;
    std::cout << *pardon << std::endl;

    std::cout << "\n=== SIGN AND EXECUTE ===" << std::endl;

    boss.signForm(*shrub);
    boss.executeForm(*shrub);

    boss.signForm(*robot);
    boss.executeForm(*robot);

    boss.signForm(*pardon);
    boss.executeForm(*pardon);

    std::cout << "\n=== UNKNOWN FORM ===" << std::endl;

    try
    {
        AForm* unknown = intern.makeForm("unknown form", "target");
        delete unknown;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    delete shrub;
    delete robot;
    delete pardon;

    return 0;
}