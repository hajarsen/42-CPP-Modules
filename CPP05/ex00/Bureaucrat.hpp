#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat
{
  public:
    Bureaucrat();
    Bureaucrat(std::string const& name, int grade);
    Bureaucrat(Bureaucrat const& src);
    ~Bureaucrat();

    Bureaucrat& operator=(Bureaucrat const& rhs);

    std::string const& getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

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
    std::string const name;
    int grade;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& b);

#endif
