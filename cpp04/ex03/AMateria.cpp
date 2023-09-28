# include "header.h"


// what should I ho with the default constructor without arguments?
// AMateria::AMateria()
// {
//     std::cout << "AMateria: Constructor called" << std::endl;
// }

AMateria::AMateria(std::string const & type)
    :_type(type)
{
    std::cout << "AMateria: Constructor called" << std::endl;
}