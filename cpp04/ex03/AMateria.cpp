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
    if (DEBUG)
        std::cout << "AMateria: Default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type)
    :_type(type)
{
    if (DEBUG)
        std::cout << "AMateria: String constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
    if (DEBUG)
        std::cout << "AMateria: Copy constructor called" << std::endl;
    this->_type = copy.getType();
}

AMateria&    AMateria::operator=(const AMateria &other)
{
    if (DEBUG)
        std::cout << "AMateria: Assignment operator called" << std::endl;
    if (this != &other)
    {
        // _type = other.getType(); // copying the type does not make sense
    }
    return (*this);
}

AMateria::~AMateria(void)
{
    if (DEBUG)
        std::cout << "AMateria: Destructor called" << std::endl;
}