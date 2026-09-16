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
    void executeAction() const;
    PresidentialPardonForm& operator=(const PresidentialPardonForm&);

  private:
    std::string target;

};
#endif
