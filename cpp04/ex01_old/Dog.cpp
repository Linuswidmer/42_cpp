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
            _brain = other._brain;
    }
    return (*this);
}

void    Dog::makeSound(void) const
{
    cout << "wooof" << endl;
}

// void    Dog::newIdea(string idea)
// {
//     cout << "newIdea: " << idea << endl;
//     _brain->setIdea(idea);
// }

// void    Dog::tellIdea(void) const
// {
//     cout << _brain->getIdea() << endl;
// }