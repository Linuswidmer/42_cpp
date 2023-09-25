# include "Cat.hpp"

Cat::Cat(void)
    : Animal()
{
    cout << "Cat: Constructor called" << endl; 
    _type = "Cat";
}

// why does this work???
Cat::Cat(const Cat &copy)
    :Animal(copy)
{
    cout << "Cat: Copy constructor called" << endl;
}

Cat& Cat::operator=(const Cat &other)
{
    cout << "Cat: Copy assignment called" << endl;
    if (this != &other)
    {
        _type = other._type;
    }
    return (*this);
}

Cat::~Cat(void)
{
    cout << "Cat: Destructor called" << endl;
}

void    Cat::makeSound(void) const
{
    cout << "meow" << endl;
}