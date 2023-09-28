# include "WrongCat.hpp"

WrongCat::WrongCat(void)
    : WrongAnimal()
{
    std::cout << "WrongCat: Constructor called" << std::endl; 
    _type = "WrongCat";
}

// why does this work???
WrongCat::WrongCat(const WrongCat &copy)
    :WrongAnimal(copy)
{
    std::cout << "WrongCat: Copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
    std::cout << "WrongCat: Copy assignment called" << std::endl;
    if (this != &other)
    {
        _type = other._type;
    }
    return (*this);
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat: Destructor called" << std::endl;
}

void    WrongCat::makeSound(void) const
{
    std::cout << "meow" << std::endl;
}