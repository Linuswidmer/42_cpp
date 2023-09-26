#include "Animal.hpp"

Animal::Animal(void)
    : _type("Animal")
{
    cout << "Animal: Constructor called" << endl;
}

Animal::Animal(const Animal &copy)
    : _type(copy._type)
{
    cout << "Animal: Copy constructor called" << endl;
}

Animal& Animal::operator=(const Animal &other)
{
    cout << "Animal: Copy assignment called" << endl;
    if (this != &other)
    {
        _type = other._type;
    }
    return (*this);
}

Animal::~Animal(void)
{
    cout << "Animal: Destructor called" << endl;
}

string  Animal::getType(void)
{
    return (_type);
}

void    Animal::makeSound(void) const
{
    cout << "indistinguishable animal Sounds" << endl;
}

void    Animal::newIdea(const string idea)
{
    (void)idea;
}

void    Animal::tellIdea(void) const
{
}