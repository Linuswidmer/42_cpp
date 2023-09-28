#include "Dog.hpp"

Dog::Dog(void)
    :Animal()
{
    std::cout << "Dog: Constructor called" << std::endl;
    _type = "Dog";
    try
    {
        _brain = new Brain();   
    }
    catch(const bad_alloc& e)
    {
        throw e;
    }
}

Dog::~Dog(void)
{
    std::cout << "Dog: Destructor called" << std::endl;
}

Dog::Dog(const Dog& copy)
    :Animal(copy), _brain(new Brain(*(copy._brain)))
{
    std::cout << "Dog: Copy constructor called" << std::endl;
}

Dog&    Dog::operator=(const Dog &other)
{
    std::cout << "Dog: Copy assignement called" << std::endl;
    if (this != &other)
    {
        _type = other._type;
        *_brain = *other._brain;
    }
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << "wooof" << std::endl;
}

void    Dog::newIdea(string idea)
{
    _brain->setIdea(idea);
}

void    Dog::tellIdea(void) const
{
    for (size_t i = 0; i < 100 && i < _brain->index_ideas(); i++)
        std::cout << _brain->getIdea(i) << std::endl;
}

Brain   *Dog::brain(void) const
{
    return (_brain);
}