# include "Cat.hpp"

Cat::Cat(void)
    : Animal()
{
    cout << "Cat: Constructor called" << endl; 
    _type = "Cat";
    // try
    // {
    //     _brain = new Brain();   
    // }
    // catch(const bad_alloc& e)
    // {
    //     throw e;
    // }
}

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
        _brain = other._brain;
    }
    return (*this);
}

Cat::~Cat(void)
{
    cout << "Cat: Destructor called" << endl;
    //delete _brain;
}

void    Cat::makeSound(void) const
{
    cout << "meow" << endl;
}

// void    Cat::newIdea(string idea)
// {
//     cout << "newIdea: " << idea << endl;
//     _brain->setIdea(idea);
// }

// void    Cat::tellIdea(void) const
// {
//     cout << _brain->getIdea() << endl;
// }