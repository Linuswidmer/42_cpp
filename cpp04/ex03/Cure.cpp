# include "header.h"

void    Cure::use(ICharacter &target)
{
    std::cout   << "heals " << target.getName() << " wounds"
                << std::endl; 
}

AMateria*   Cure::clone(void) const
{
    std::cout << "Cure Materia cloned" << std::endl;
    return (new Cure());
}

Cure::Cure(void)
    :AMateria("cure")
{
    if (DEBUG)
        std::cout << "Cure: Default constructor called" << std::endl;
}

Cure::Cure(const Cure &copy)
    :AMateria(copy)
{
    if (DEBUG)
        std::cout << "Cure: Copy constructor called" << std::endl;
}

Cure&    Cure::operator=(const Cure &other)
{
    if (DEBUG)
        std::cout << "Cure: Assignment operator called" << std::endl;
    if (this != &other)
    {
        // calling the base class assignment operator (super cool!)
        (*this).AMateria::operator=(other); 
    }
    return (*this);
}

Cure::~Cure(void)
{
    if (DEBUG)
        std::cout << "Cure: Destructor called" << std::endl;
}