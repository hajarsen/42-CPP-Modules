#ifndef AFORM_HPP
#define AFORM_HPP
#include <exception>
#include <ostream>
#include <string>
class Bureaucrat;
class AForm
{
  public:
    AForm();
    AForm(const std::string& name, int sign, int exec);
    AForm(const AForm& other);
    virtual ~AForm();
    AForm& operator=(const AForm& other);
    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(const Bureaucrat& b);
    void execute(const Bureaucrat& executor) const;
    virtual void executeAction() const = 0;
    class GradeTooHighException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };
    class FormNotSignedException : public std::exception
    {
      public:
        virtual const char* what() const throw();
    };

  private:
    const std::string name;
    bool _isSigned;
    const int signGrade;
    const int executeGrade;
};
std::ostream& operator<<(std::ostream& out, const AForm& form);
#endif
