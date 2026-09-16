#include "AForm.hpp"
#include "Bureaucrat.hpp"
AForm::AForm()
    : name("unnamed"), _isSigned(false), signGrade(150), executeGrade(150)
{
}
AForm::AForm(const std::string& n, int s, int e)
    : name(n), _isSigned(false), signGrade(s), executeGrade(e)
{
    if (s < 1 || e < 1)
        throw GradeTooHighException();
    if (s > 150 || e > 150)
        throw GradeTooLowException();
}
AForm::AForm(const AForm& o)
    : name(o.name), _isSigned(o._isSigned), signGrade(o.signGrade), executeGrade(o.executeGrade)
{
}
AForm::~AForm()
{
}
AForm& AForm::operator=(const AForm& o)
{
    if (this != &o)
        _isSigned = o._isSigned;
    return *this;
}
const std::string& AForm::getName() const
{
    return name;
}
bool AForm::isSigned() const
{
    return _isSigned;
}
int AForm::getGradeToSign() const
{
    return signGrade;
}
int AForm::getGradeToExecute() const
{
    return executeGrade;
}
void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}
void AForm::execute(const Bureaucrat& b) const
{
    if (!_isSigned)
        throw FormNotSignedException();
    if (b.getGrade() > executeGrade)
        throw GradeTooLowException();
    executeAction();
}
const char* AForm::GradeTooHighException::what() const throw()
{
    return "grade too high";
}
const char* AForm::GradeTooLowException::what() const throw()
{
    return "grade too low";
}
const char* AForm::FormNotSignedException::what() const throw()
{
    return "form is not signed";
}
std::ostream& operator<<(std::ostream& o, const AForm& f)
{
    return o << f.getName() << ", signed: " << (f.isSigned() ? "yes" : "no")
             << ", sign grade: " << f.getGradeToSign()
             << ", execute grade: " << f.getGradeToExecute();
}
