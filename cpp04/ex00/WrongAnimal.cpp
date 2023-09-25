#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
    : _type("WrongAnimal")
{
    cout << "WrongAnimal: Constructor called" << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
    : _type(copy._type)
{
    cout << "WrongAnimal: Copy constructor called" << endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
    cout << "WrongAnimal: Copy assignment called" << endl;
    if (this != &other)
    {
        _type = other._type;
    }
    return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
    cout << "WrongAnimal: Destructor called" << endl;
}

string  WrongAnimal::getType(void)
{
    return (_type);
}

void    WrongAnimal::makeSound(void) const
{
    cout << "indistinguishable WrongAnimal Sounds" << endl;
}