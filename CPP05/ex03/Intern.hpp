#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <exception>

class AForm;

class Intern
{
  public:
    Intern();
    Intern(const Intern& other);
    ~Intern();
    Intern& operator=(const Intern& other);
    AForm* makeForm(const std::string& name, const std::string& target) const;
    AForm* createShrubbery(const std::string& target) const;
    AForm* createRobotomy(const std::string& target) const;
    AForm* createPardon(const std::string& target) const;
    class FormNotFoundException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};

#endif
