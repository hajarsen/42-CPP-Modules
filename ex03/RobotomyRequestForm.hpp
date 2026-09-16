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
    void executeAction() const;
    RobotomyRequestForm& operator=(const RobotomyRequestForm&);

  private:
    std::string target;

};
#endif
