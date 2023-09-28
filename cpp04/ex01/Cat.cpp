# include "Cat.hpp"

Cat::Cat(void)
    : Animal()
{
    std::cout << "Cat: Constructor called" << std::endl; 
    _type = "Cat";
    try
    {
        _brain = new Brain();   
    }
    catch(const bad_alloc& e)
    {
        throw e;
    }
}

Cat::Cat(const Cat &copy)
    :Animal(copy), _brain(new Brain(*(copy._brain)))
{
    std::cout << "Cat: Copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
    std::cout << "Cat: Copy assignment called" << std::endl;
    if (this != &other)
    {
        _type = other._type;
        *_brain = *other._brain;
    }
    return (*this);
}

Cat::~Cat(void)
{
    std::cout << "Cat: Destructor called" << std::endl;
    delete _brain;
}

void    Cat::makeSound(void) const
{
    std::cout << "meow" << std::endl;
}

void    Cat::newIdea(const string idea)
{
    _brain->setIdea(idea);
}

void    Cat::tellIdea(void) const
{
    for (size_t i = 0; i < 100 && i < _brain->index_ideas(); i++)
        std::cout << _brain->getIdea(i) << std::endl;
}

Brain   *Cat::brain(void) const
{
    return (_brain);
}