#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    Bureaucrat highRank("Alice", 1);
    Bureaucrat middleRank("Bob", 40);
    Bureaucrat lowRank("Charlie", 150);

    std::cout << "\n--- SHRUBBERY CREATION ---" << std::endl;

    ShrubberyCreationForm shrub("forest");
    std::cout << shrub << std::endl;

    lowRank.signForm(shrub);
    middleRank.signForm(shrub);
    middleRank.executeForm(shrub);

    std::cout << "\n--- ROBOTOMY REQUEST ---" << std::endl;

    RobotomyRequestForm robot("Robot");
    std::cout << robot << std::endl;

    middleRank.executeForm(robot);
    middleRank.signForm(robot);
    middleRank.executeForm(robot);

    std::cout << "\n--- PRESIDENTIAL PARDON ---" << std::endl;

    PresidentialPardonForm pardon("John");
    std::cout << pardon << std::endl;

    middleRank.signForm(pardon);
    highRank.signForm(pardon);
    middleRank.executeForm(pardon);
    highRank.executeForm(pardon);

    return 0;
}