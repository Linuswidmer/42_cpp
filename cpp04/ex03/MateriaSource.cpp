# include "header.h"

MateriaSource::MateriaSource(void)
    : _index_arr_materias(0)
{
    std::cout << "MateriaSource: Constructor called" << std::endl;
    // should I create here 4 instances of the base class AMateria?
}

MateriaSource::~MateriaSource(void)
{
    //delete[] _arr_materias;
    std::cout << "MateriaSource: Destructor called" << std::endl;
}