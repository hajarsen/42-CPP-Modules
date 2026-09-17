#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <limits>

static bool isNan(double v)
{
     return v != v; 
}
static bool isInf(double v)
{
    double inf = std::numeric_limits<double>::infinity();
    return v == inf || v == -inf;
}
static bool canChar(double v)
{
    return !isNan(v) && !isInf(v) && v >= 0 && v <= 127;
}
static bool canInt(double v)
{
    return !isNan(v) && !isInf(v)
        && v >= std::numeric_limits<int>::min()
        && v <= std::numeric_limits<int>::max();
}
static bool isChar(const std::string &s)
{
    return s.length() == 1
        && !std::isdigit(static_cast<unsigned char>(s[0]));
}
static bool isInt(const std::string &s)
{
    char *end;
    long v = std::strtol(s.c_str(), &end, 10);
    return end != s.c_str() && *end == '\0'
        && v >= std::numeric_limits<int>::min()
        && v <= std::numeric_limits<int>::max();
}
static bool isFloat(const std::string &s)
{
    if (s == "nanf" || s == "+inff" || s == "-inff")
        return true;

    if (s.length() < 2 || s[s.length() - 1] != 'f')
        return false;

    std::string n = s.substr(0, s.length() - 1);

    if (n.find('.') == std::string::npos)
        return false;

    char *end;
    std::strtod(n.c_str(), &end);
    return end != n.c_str() && *end == '\0';
}
static bool isDouble(const std::string &s)
{
    if (s == "nan" || s == "+inf" || s == "-inf") return true;
    char *end;
    std::strtod(s.c_str(), &end);
    return end != s.c_str() && *end == '\0';
}
static float toFloat(const std::string &s)
{
    if (s == "nanf") return std::numeric_limits<float>::quiet_NaN();
    if (s == "+inff") return std::numeric_limits<float>::infinity();
    if (s == "-inff") return -std::numeric_limits<float>::infinity();
    return static_cast<float>(std::strtod(s.c_str(), NULL));
}
static double toDouble(const std::string &s)
{
    if (s == "nan") return std::numeric_limits<double>::quiet_NaN();
    if (s == "+inf") return std::numeric_limits<double>::infinity();
    if (s == "-inf") return -std::numeric_limits<double>::infinity();
    return std::strtod(s.c_str(), NULL);
}
static void printChar(char v)
{
    if (std::isprint(static_cast<unsigned char>(v)))
        std::cout << "char: '" << v << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}
static void printFloat(float v)
{
    if (isNan(v))
        std::cout << "float: nanf" << std::endl;
    else if (isInf(v))
        std::cout << "float: "
                  << (v < 0 ? "-inff" : "+inff") << std::endl;
    else if (canInt(v) && v == static_cast<int>(v))
        std::cout << "float: " << static_cast<int>(v)
                  << ".0f" << std::endl;
    else
        std::cout << "float: " << v << "f" << std::endl;
}

static void printDouble(double v)
{
    if (isNan(v))
        std::cout << "double: nan" << std::endl;
    else if (isInf(v))
        std::cout << "double: "
                  << (v < 0 ? "-inf" : "+inf") << std::endl;
    else if (canInt(v) && v == static_cast<int>(v))
        std::cout << "double: " << static_cast<int>(v)
                  << ".0" << std::endl;
    else
        std::cout << "double: " << v << std::endl;
}
static void impossible()
{
    std::cout << "char: impossible\nint: impossible\n"
              << "float: impossible\ndouble: impossible" << std::endl;
}
static void fromChar(const std::string &s)
{
    char v = s[0];
    printChar(v);
    std::cout << "int: " << static_cast<int>(v) << std::endl;
    printFloat(static_cast<float>(v));
    printDouble(static_cast<double>(v));
}
static void fromInt(const std::string &s)
{
    int v = static_cast<int>(std::strtol(s.c_str(), NULL, 10));
    if (canChar(v))
        printChar(static_cast<char>(v));
    else 
        std::cout << "char: impossible" << std::endl;
    std::cout << "int: " << v << std::endl;
    printFloat(static_cast<float>(v));
    printDouble(static_cast<double>(v));
}
static void fromFloat(const std::string &s)
{
    float v = toFloat(s);
    if (canChar(v))
        printChar(static_cast<char>(v));
    else
        std::cout << "char: impossible" << std::endl;
    if (canInt(v))
        std::cout << "int: " << static_cast<int>(v) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    printFloat(v);
    printDouble(static_cast<double>(v));
}
static void fromDouble(const std::string &s)
{
    double v = toDouble(s);
    if (canChar(v))
        printChar(static_cast<char>(v));
    else
        std::cout << "char: impossible" << std::endl;
    if (canInt(v))
        std::cout << "int: " << static_cast<int>(v) << std::endl;
    else
        std::cout << "int: impossible" << std::endl;
    if (!isNan(v) && !isInf(v)
        && (v > std::numeric_limits<float>::max()
            || v < -std::numeric_limits<float>::max()))
        std::cout << "float: impossible" << std::endl;
    else
        printFloat(static_cast<float>(v));
    printDouble(v);
}
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void)other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}
ScalarConverter::~ScalarConverter() {}
void ScalarConverter::convert(const std::string &s)
{
    if (s.empty())
        impossible();
    else if (isChar(s))
        fromChar(s);
    else if (isInt(s))
        fromInt(s);
    else if (isFloat(s))
        fromFloat(s);
    else if (isDouble(s)) 
        fromDouble(s);
    else
        impossible();
}