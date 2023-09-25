#include "Fixed.hpp"

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _fixed_point = raw;
}

int    Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(_fixed_point);
}

Fixed::Fixed(const Fixed& copy)
    : _fixed_point(copy._fixed_point)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) 
{
    std::cout << "Copy assignment operator caled" << std::endl;
    if (this != &other) 
    {
        _fixed_point = other._fixed_point;
    }
    return *this;
}

Fixed::Fixed(void) 
    :_fixed_point(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
