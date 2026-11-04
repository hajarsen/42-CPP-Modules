#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    : name("unnamed"), _isSigned(false), signGrade(150), executeGrade(150)
{
}
Form::Form(const std::string& name, int signGrade, int executeGrade)
    : name(name), _isSigned(false), signGrade(signGrade), executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}
Form::Form(const Form& other)
    : name(other.name), _isSigned(other._isSigned), signGrade(other.signGrade),
      executeGrade(other.executeGrade)
{
}
Form::~Form()
{
}
Form& Form::operator=(const Form& other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}
const std::string& Form::getName() const
{
    return name;
}
bool Form::isSigned() const
{
    return _isSigned;
}
int Form::getGradeToSign() const
{
    return signGrade;
}
int Form::getGradeToExecute() const
{
    return executeGrade;
}
void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}
const char* Form::GradeTooHighException::what() const throw()
{
    return "grade too high";
}
const char* Form::GradeTooLowException::what() const throw()
{
    return "grade too low";
}
std::ostream& operator<<(std::ostream& output, const Form& form)
{
    return output << form.getName() << ", signed: " << (form.isSigned() ? "yes" : "no")
                  << ", sign grade: " << form.getGradeToSign()
                  << ", execute grade: " << form.getGradeToExecute();
}
