#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("robotomy request", 72, 45), target("default target")
{
}
RobotomyRequestForm::RobotomyRequestForm(const std::string& t)
    : AForm("robotomy request", 72, 45), target(t)
{
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& o)
    : AForm(o), target(o.target)
{
}
RobotomyRequestForm::~RobotomyRequestForm()
{
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& o)
{
    if (this != &o)
    {
        AForm::operator=(o);
        target = o.target;
    }
    return *this;
}
void RobotomyRequestForm::executeAction() const
{
    std::cout << "Bzzzzzz... Brrrrr... drilling noises..." << std::endl;
    if (std::rand() % 2)
        std::cout << target << " was successfully robotomized." << std::endl;
    else
        std::cout << "Failed to robotomize " << target << "." << std::endl;
}
