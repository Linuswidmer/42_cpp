#include "Animal.hpp"

Animal::Animal(void)
    : _type("Animal")
{
    std::cout << "Animal: Constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
    : _type(copy._type)
{
    std::cout << "Animal: Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
    std::cout << "Animal: Copy assignment called" << std::endl;
    if (this != &other)
    {
        _type = other._type;
    }
    return (*this);
}

Animal::~Animal(void)
{
    std::cout << "Animal: Destructor called" << std::endl;
}

std::string  Animal::getType(void)
{
    return (_type);
}

void    Animal::makeSound(void) const
{
    std::cout << "indistinguishable animal Sounds" << std::endl;
}