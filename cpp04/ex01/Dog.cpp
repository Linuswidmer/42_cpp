#include "Dog.hpp"

Dog::Dog(void)
    :Animal()
{
    cout << "Dog: Constructor called" << endl;
    _type = "Dog";
}


Dog::~Dog(void)
{
    cout << "Dog: Destructor called" << endl;
}

Dog::Dog(const Dog& copy)
    : Animal(copy)
{
    cout << "Dog: Copy constructor called" << endl;
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
    cout << "wooof" << endl;
}