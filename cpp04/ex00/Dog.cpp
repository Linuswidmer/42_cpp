#include "Dog.hpp"

Dog::Dog(void)
    :Animal()
{
    std::cout << "Dog: Constructor called" << std::endl;
    _type = "Dog";
}


Dog::~Dog(void)
{
    std::cout << "Dog: Destructor called" << std::endl;
}

Dog::Dog(const Dog& copy)
    : Animal(copy)
{
    std::cout << "Dog: Copy constructor called" << std::endl;
}


Dog&    Dog::operator=(const Dog &other)
{
    if (this != &other)
    {
            _type = other._type;
    }
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << "wooof" << std::endl;
}