#include "Array.hpp"
#include <iostream>
#include <string>

int main()
{
    // Default constructor
    Array<int> empty;
    std::cout << "Empty size: " << empty.size() << std::endl;

    // Parameterized constructor
    Array<int> a(3);
    for (unsigned int i = 0; i < a.size(); ++i)
        a[i] = static_cast<int>(i * 10);

    // Copy constructor + deep copy
    Array<int> b(a);
    b[0] = 99;
    std::cout << "Original: " << a[0]
              << " Copy: " << b[0] << std::endl;

    // Assignment operator + deep copy
    Array<int> c;
    c = a;
    c[1] = 77;
    std::cout << "Original: " << a[1]
              << " Assigned: " << c[1] << std::endl;

    // Const access
    const Array<int> constArray(a);
    std::cout << "Const access: " << constArray[0] << std::endl;

    // Out of bounds
    try
    {
        std::cout << a[3] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Different/complex type
    Array<std::string> words(2);
    words[0] = "hello";
    words[1] = "templates";

    std::cout << words[0] << " " << words[1] << std::endl;

    return 0;
}