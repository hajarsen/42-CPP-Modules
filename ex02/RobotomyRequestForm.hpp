#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
  public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string&);
    RobotomyRequestForm(const RobotomyRequestForm&);
    ~RobotomyRequestForm();
    RobotomyRequestForm& operator=(const RobotomyRequestForm&);
    void executeAction() const;

  private:
    std::string target;

};
#endif
