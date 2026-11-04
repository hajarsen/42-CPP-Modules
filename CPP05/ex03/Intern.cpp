#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>

typedef AForm* (Intern::*FormCreator)(const std::string&) const;


AForm* Intern::createShrubbery(const std::string& target) const
{
    return new ShrubberyCreationForm(target);
}
AForm* Intern::createRobotomy(const std::string& target) const
{
    return new RobotomyRequestForm(target);
}
AForm* Intern::createPardon(const std::string& target) const
{
    return new PresidentialPardonForm(target);
}


Intern::Intern()
{
}
Intern::Intern(const Intern &other)
{
    (void)other;
}
Intern::~Intern()
{
}
Intern& Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

AForm* Intern::makeForm(const std::string& name, const std::string& target) const
{
    const std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    FormCreator creators[3] = {&Intern::createShrubbery, &Intern::createRobotomy, &Intern::createPardon};
    for (int index = 0; index < 3; ++index)
    {
        if (name == names[index])
        {
            std::cout << "Intern creates " << name << std::endl;
            return (this->*creators[index])(target);
        }
    }
    throw FormNotFoundException();
}


const char* Intern::FormNotFoundException::what() const throw()
{
    return "Intern cannot create unknown form";
}