#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat()
    : name("unnamed"), grade(150)
{
}
Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name(other.name), grade(other.grade)
{
}
Bureaucrat::~Bureaucrat()
{
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        grade = other.grade;
    return *this;
}
const std::string& Bureaucrat::getName() const
{
    return name;
}
int Bureaucrat::getGrade() const
{
    return grade;
}
void Bureaucrat::incrementGrade()
{
    if (grade == 1)
        throw GradeTooHighException();
    --grade;
}
void Bureaucrat::decrementGrade()
{
    if (grade == 150)
        throw GradeTooLowException();
    ++grade;
}
void Bureaucrat::signForm(Form& form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << name << " couldn't sign " << form.getName() << " because " << e.what()
                  << std::endl;
    }
}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "grade too high";
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "grade too low";
}
std::ostream& operator<<(std::ostream& output, const Bureaucrat& bureaucrat)
{
    return output << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
}
