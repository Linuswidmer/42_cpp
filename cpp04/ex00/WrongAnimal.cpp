#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
    : _type("WrongAnimal")
{
    std::cout << "WrongAnimal: Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
    : _type(copy._type)
{
    std::cout << "WrongAnimal: Copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "WrongAnimal: Copy assignment called" << std::endl;
    if (this != &other)
    {
        _type = other._type;
    }
    return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal: Destructor called" << std::endl;
}

std::string  WrongAnimal::getType(void)
{
    return (_type);
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "indistinguishable WrongAnimal Sounds" << std::endl;
}