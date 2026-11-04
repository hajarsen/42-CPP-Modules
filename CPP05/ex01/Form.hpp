#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
  private:
    const std::string name;
    bool _isSigned;
    const int signGrade;
    const int executeGrade;

  public:
    Form();
    Form(const std::string& name, int signGrade, int executeGrade);
    Form(const Form& other);
    ~Form();
    Form& operator=(const Form& other);
    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(const Bureaucrat& bureaucrat);
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
};

std::ostream& operator<<(std::ostream& output, const Form& form);

#endif
