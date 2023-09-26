# include "Cat.hpp"

Cat::Cat(void)
    : Animal()
{
    cout << "Cat: Constructor called" << endl; 
    _type = "Cat";
    _brain = new Brain();
    // how can I check here if an allocation fails? 
    // how can I terminate the program when it fails?
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
    delete _brain;
}

void    Cat::makeSound(void) const
{
    cout << "meow" << endl;
}

void    Cat::newIdea(string idea)
{
    cout << "newIdea: " << idea << endl;
    _brain->setIdea(idea);
}

void    Cat::tellIdea(void) const
{
    cout << _brain->getIdea() << endl;
}