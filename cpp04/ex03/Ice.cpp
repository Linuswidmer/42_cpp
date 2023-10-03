# include "header.h"

void    Ice::use(ICharacter &target)
{
    std::cout   << "shoots an ice bolt at " << target.getName()
                << std::endl; 
}

AMateria*   Ice::clone(void) const
{
    std::cout << "Ice Materia cloned" << std::endl;
    return (new Ice());
}

Ice::Ice(void)
    :AMateria("ice")
{
    if (DEBUG)
        std::cout << "Ice: Default constructor called" << std::endl;
}

Ice::Ice(const Ice &copy)
    :AMateria(copy)
{
    if (DEBUG)
        std::cout << "Ice: Copy constructor called" << std::endl;
}

Ice&    Ice::operator=(const Ice &other)
{
    if (DEBUG)
        std::cout << "Ice: Assignment operator called" << std::endl;
    if (this != &other)
    {
        // calling the base class assignment operator (super cool!)
        (*this).AMateria::operator=(other); 
    }
    return (*this);
}

Ice::~Ice(void)
{
    if (DEBUG)
        std::cout << "Ice: Destructor called" << std::endl;
}