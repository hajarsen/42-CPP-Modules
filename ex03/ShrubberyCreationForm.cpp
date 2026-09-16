#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("shrubbery creation", 145, 137), target("default target")
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& t)
    : AForm("shrubbery creation", 145, 137), target(t)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& o)
    : AForm(o), target(o.target)
{
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& o)
{
    if (this != &o)
    {
        AForm::operator=(o);
        target = o.target;
    }
    return *this;
}
void ShrubberyCreationForm::executeAction() const
{
    std::ofstream f((target + "_shrubbery").c_str());
    if(!f)
        throw FileCreationException();
    f << "           *" << std::endl;
    f << "          /\\\\" << std::endl;
    f << "         /  \\\\" << std::endl;
    f << "        /++++\\\\" << std::endl;
    f << "       /      \\\\" << std::endl;
    f << "      /~~~~~~~~\\\\" << std::endl;
    f << "     /          \\\\" << std::endl;
    f << "    /____________\\\\" << std::endl;
    f << "          ||" << std::endl;
    f << "          ||" << std::endl;
    f << "          ||" << std::endl;
    f << "        __||__" << std::endl;
    
}

const char* ShrubberyCreationForm::FileCreationException::what() const throw()
{
    return "Error: Could not create the shrubbery file.";
}