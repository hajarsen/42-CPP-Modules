#include "Fixed.hpp"

Fixed::Fixed() 
    : value(0) 
{

}

Fixed::Fixed(const int value)
{
    this->value = value << fractionalBits;
}

Fixed::Fixed(const float value)
{
    this->value = roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        value = other.getRawBits();

    return *this;
}

Fixed::~Fixed()
{

}

int Fixed::getRawBits(void) const
{
    return value;
}

void Fixed::setRawBits(int const raw)
{
    value = raw;
}

float Fixed::toFloat(void) const
{
    return (float)value / (float)(1 << fractionalBits);
}

int Fixed::toInt(void) const
{
    return value >> fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}

bool Fixed::operator>(const Fixed& other) const
{
    return value > other.value;
}

bool Fixed::operator<(const Fixed& other) const
{
    return value < other.value;
}

bool Fixed::operator>=(const Fixed& other) const
{
    return value >= other.value;
}

bool Fixed::operator<=(const Fixed& other) const
{
    return value <= other.value;
}

bool Fixed::operator==(const Fixed& other) const
{
    return value == other.value;
}

bool Fixed::operator!=(const Fixed& other) const
{
    return value != other.value;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++(void)
{
    value += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    value += 1;
    return temp;
}

Fixed& Fixed::operator--(void)
{
    value -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    value -= 1;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return a;
    return b;
}