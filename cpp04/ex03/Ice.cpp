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
    std::cout << "Ice: Default constructor called" << std::endl;
}

Ice::~Ice(void)
{
    std::cout << "Ice: Destructor called" << std::endl;
}