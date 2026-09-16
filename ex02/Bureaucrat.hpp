#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <exception>
#include <iostream>
#include <string>
class AForm;
class Bureaucrat
{
  public:
    Bureaucrat();
    Bureaucrat(const std::string&, int);
    Bureaucrat(const Bureaucrat&);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat&);
    const std::string& getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(AForm&) const;
    void executeForm(const AForm&) const;
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

  private:
    const std::string name;
    int grade;
};
std::ostream& operator<<(std::ostream&, const Bureaucrat&);
#endif
