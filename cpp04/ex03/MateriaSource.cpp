# include "header.h"

void    MateriaSource::learnMateria(AMateria *materia)
{
    std::cout   << "new Materia " << materia->getType() << " learned" 
                << std::endl;
    _arr_materias[_index_arr_materias % 4] = materia;
    _index_arr_materias++;
}

AMateria*   MateriaSource::createMateria(std::string const &type)
{
    for(int i = 0; i < 4 && i < _index_arr_materias; i ++)
    {
        if (_arr_materias[i]->getType() == type)
        {
            std::cout   << "new Materia " << _arr_materias[i]->getType() 
                        << " created" << std::endl;
            return (_arr_materias[i]->clone());
        }
    }
    std::cout   << "failed to create new Materia, type not found"
                << std::endl;
    return (NULL);
}

MateriaSource::MateriaSource(void)
    : _index_arr_materias(0)
{
    std::cout << "MateriaSource: Constructor called" << std::endl;
}

MateriaSource::~MateriaSource(void)
{
    // delete[] _arr_materias;
    std::cout << "MateriaSource: Destructor called" << std::endl;
}