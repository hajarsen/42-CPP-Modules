#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "AForm.hpp"
class ShrubberyCreationForm : public AForm
{
  public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string&);
    ShrubberyCreationForm(const ShrubberyCreationForm&);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
    void executeAction() const;
    class FileCreationException : public std::exception {
    public:
      virtual const char *what() const throw();
    };

  private:
    std::string target;

};
#endif
