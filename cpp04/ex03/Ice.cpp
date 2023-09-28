# include "header.h"

Ice::Ice(std::string const &type)
    : AMateria(type)
{
    std::cout << "Ice: Constructor called" << std::endl;
}