#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat()
    : name("unnamed"), grade(150)
{
}
Bureaucrat::Bureaucrat(const std::string& n, int g)
    : name(n), grade(g)
{
    if (g < 1)
        throw GradeTooHighException();
    if (g > 150)
        throw GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat& o)
    : name(o.name), grade(o.grade)
{
}
Bureaucrat::~Bureaucrat()
{
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& o)
{
    if (this != &o)
        grade = o.grade;
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
void Bureaucrat::signForm(AForm& f) const
{
    try
    {
        f.beSigned(*this);
        std::cout << name << " signed " << f.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << name << " couldn't sign " << f.getName() << " because " << e.what()
                  << std::endl;
    }
}
void Bureaucrat::executeForm(const AForm& f) const
{
    try
    {
        f.execute(*this);
        std::cout << name << " executed " << f.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << name << " couldn't execute " << f.getName() << " because " << e.what()
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
std::ostream& operator<<(std::ostream& o, const Bureaucrat& b)
{
    return o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
}
