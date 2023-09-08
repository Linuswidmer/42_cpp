#include "Fixed.hpp"
#include <stdio.h>

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

float   Fixed::toFloat(void) const
{
    return (float)_fixed_point / (1 << _fractional_bits);
}

int     Fixed::toInt(void) const
{
    return (_fixed_point >> _fractional_bits);
}

std::ostream& operator<<(std::ostream& o, Fixed const& rhs)
{
    o << rhs.toFloat();
    return (o);
}

Fixed::Fixed(const int i) : _fixed_point(i << _fractional_bits)
{
    std::cout << "Int constructor caled" << std::endl;
}

Fixed::Fixed(const float f) : _fixed_point(roundf(f * (1 << _fractional_bits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) 
{
    std::cout << "Copy constructor called" << std::endl;
    this->_fixed_point = copy._fixed_point;
}

Fixed::Fixed(void) :_fixed_point(0)
{
    std::cout << "Defaut constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other) 
{
    std::cout << "Copy assignment operator caled" << std::endl;
    if (this != &other) 
        this->_fixed_point = other._fixed_point;
    return *this;
}

bool Fixed::operator>(const Fixed &other) const
{
    return (this->toFloat() > (other.toFloat()));
}

bool Fixed::operator<(const Fixed &other) const
{
    return (this->toFloat() < (other.toFloat()));
}

bool Fixed::operator>=(const Fixed &other) const
{
    return (this->toFloat() >= (other.toFloat()));
}

bool Fixed::operator<=(const Fixed &other) const
{
    return (this->toFloat() <= (other.toFloat()));
}

bool Fixed::operator==(const Fixed &other) const
{
    return (this->toFloat() == (other.toFloat()));
}

bool Fixed::operator!=(const Fixed &other) const
{
    return (this->toFloat() != (other.toFloat()));
}

// important! here we pass the new Fixed instance by value and not by reference
// this is important because otherwise the instance would immideately go out of scope
Fixed Fixed::operator+(const Fixed &other)
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other)
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other)
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other)
{
    return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed Fixed::operator++(void)
{
    _fixed_point++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    ++(*this);
    return (tmp);
}

Fixed Fixed::operator--(void)
{
    _fixed_point--;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    --(*this);
    return (tmp);
}

//static does not have to be defined here
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return (a);
    else
        return (b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

const Fixed& Fixed::max(const Fixed& a,const Fixed& b)
{
    std::cout << "const max called" << std::endl;
    if (a > b)
        return (a);
    else
        return (b);
}