#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("presidential pardon", 25, 5), target("default target")
{
}
PresidentialPardonForm::PresidentialPardonForm(const std::string& t)
    : AForm("presidential pardon", 25, 5), target(t)
{
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& o)
    : AForm(o), target(o.target)
{
}
PresidentialPardonForm::~PresidentialPardonForm()
{
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& o)
{
    if (this != &o)
    {
        AForm::operator=(o);
        target = o.target;
    }
    return *this;
}
void PresidentialPardonForm::executeAction() const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
