# include "header.h"

void    AMateria::use(ICharacter &target)
{
    std::cout   << "default Materia used on" << target.getName()
                << std::endl;
}

std::string const& AMateria::getType(void) const
{
    return (_type);
}

AMateria::AMateria()
{
    std::cout << "AMateria: Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type)
    :_type(type)
{
    std::cout << "AMateria: String constructor called" << std::endl;
}

AMateria::~AMateria(void)
{
    std::cout << "AMateria: Destructor called" << std::endl;
}