# include "WrongCat.hpp"

WrongCat::WrongCat(void)
    : WrongAnimal()
{
    cout << "WrongCat: Constructor called" << endl; 
    _type = "WrongCat";
}

// why does this work???
WrongCat::WrongCat(const WrongCat &copy)
    :WrongAnimal(copy)
{
    cout << "WrongCat: Copy constructor called" << endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
    cout << "WrongCat: Copy assignment called" << endl;
    if (this != &other)
    {
        _type = other._type;
    }
    return (*this);
}

WrongCat::~WrongCat(void)
{
    cout << "WrongCat: Destructor called" << endl;
}

void    WrongCat::makeSound(void) const
{
    cout << "meow" << endl;
}