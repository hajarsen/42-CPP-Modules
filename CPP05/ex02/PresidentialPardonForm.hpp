#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"
class PresidentialPardonForm : public AForm
{
  public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string&);
    PresidentialPardonForm(const PresidentialPardonForm&);
    ~PresidentialPardonForm();
    PresidentialPardonForm& operator=(const PresidentialPardonForm&);
    void executeAction() const;

  private:
    std::string target;

};
#endif
