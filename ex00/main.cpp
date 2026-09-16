#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << "--- Valid bureaucrats ---" << std::endl;
    Bureaucrat top("top", 1);
    Bureaucrat bottom("bottom", 150);
    Bureaucrat middle("middle", 75);

    std::cout << top << std::endl;
    std::cout << bottom << std::endl;
    std::cout << middle << std::endl;

    std::cout << "--- Invalid grades (throw + catch) ---" << std::endl;
    try
    {
        Bureaucrat high("tooHigh", 0);
        std::cout << high << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat low("tooLow", 151);
        std::cout << low << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "--- incrementGrade / decrementGrade ---" << std::endl;
    middle.incrementGrade();
    std::cout << "middle after increment: " << middle << std::endl;
    middle.decrementGrade();
    std::cout << "middle after decrement: " << middle << std::endl;
    top.decrementGrade();
    std::cout << "top after decrement: " << top << std::endl;
    bottom.incrementGrade();
    std::cout << "bottom after increment: " << bottom << std::endl;

    std::cout << "--- Boundary exceptions ---" << std::endl;
    Bureaucrat atTop("atTop", 1);
    try
    {
        atTop.incrementGrade();
        std::cout << "atTop after increment: " << atTop << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    Bureaucrat atBottom("atBottom", 150);
    try
    {
        atBottom.decrementGrade();
        std::cout << "atBottom after decrement: " << atBottom << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    std::cout << "--- Copy constructor / copy assignment ---" << std::endl;
    Bureaucrat copy(middle);
    std::cout << "copy (from middle): " << copy << std::endl;

    Bureaucrat assigned("assigned", 100);
    assigned = copy;
    std::cout << "assigned after copy assignment: " << assigned << std::endl;

    return 0;
}
