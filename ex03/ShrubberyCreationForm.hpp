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
    virtual void executeAction() const;
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
    class FileCreationException : public std::exception {
    public:
      const char *what() const throw();
    };

  private:
    std::string target;
};
#endif
