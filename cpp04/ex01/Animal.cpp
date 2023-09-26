#include "Animal.hpp"

Animal::Animal(void)
    : _type("Animal")
{
    cout << "Animal: Constructor called" << endl;
    _brain = new Brain();
}

Animal::Animal(const Animal &copy)
    : _type(copy._type)
{
    cout << "Animal: Copy constructor called" << endl;
    _brain = copy._brain;
}

Animal& Animal::operator=(const Animal &other)
{
    cout << "Animal: Copy assignment called" << endl;
    if (this != &other)
    {
        _type = other._type;
        *_brain =  * (other._brain);
    }
    return (*this);
}

Animal::~Animal(void)
{
    delete _brain;
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
    cout << "newIdea: " << idea << endl;
    _brain->setIdea(idea);
}

void    Animal::tellIdea(void) const
{
    cout << _brain->getIdea() << endl;
}