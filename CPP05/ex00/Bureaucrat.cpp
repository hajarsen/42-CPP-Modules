#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
    : name(""), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const& name, int grade)
    : name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const& src)
    : name(src.name), grade(src.grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs)
{
    if (this != &rhs)
        grade = rhs.grade;
    return *this;
}

std::string const& Bureaucrat::getName() const
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

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}
