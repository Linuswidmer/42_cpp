#include "Fixed.hpp"

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixed_point = raw;
}

int    Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return(this->_fixed_point);
}

Fixed::Fixed(const int i)
{
    this->setRawBits
}

Fixed::Fixed(const Fixed& copy) 
{
    std::cout << "Copy constructor called" << std::endl;
    this->_fixed_point = copy._fixed_point;
}

Fixed& Fixed::operator=(const Fixed& other) 
{
    std::cout << "Copy assignment operator caled" << std::endl;
    if (this != &other) 
    {
        this->_fixed_point = other._fixed_point;
    }
    return *this;
}

Fixed::Fixed(void) :_fixed_point(0)
{
    std::cout << "Defaut constructor called" << std::endl;
    this->_fixed_point = 0;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
