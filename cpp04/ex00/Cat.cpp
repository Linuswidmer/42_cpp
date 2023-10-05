# include "Cat.hpp"

Cat::Cat(void)
    : Animal()
{
    std::cout << "Cat: Constructor called" << std::endl; 
    _type = "Cat";
}

Cat::Cat(const Cat &copy)
    :Animal(copy)
{
    std::cout << "Cat: Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
    std::cout << "Cat: Copy assignment called" << std::endl;
    if (this != &other)
    {
        _type = other._type;
    }
    return (*this);
}

Cat::~Cat(void)
{
    std::cout << "Cat: Destructor called" << std::endl;
}

void    Cat::makeSound(void) const
{
    std::cout << "meow" << std::endl;
}