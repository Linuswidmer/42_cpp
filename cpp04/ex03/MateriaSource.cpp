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
    memset(_arr_materias, 0, 4 * sizeof(AMateria*));
    if (DEBUG)
        std::cout << "MateriaSource: Constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
    memset(_arr_materias, 0, 4 * sizeof(AMateria*));
    if (DEBUG)
        std::cout << "MateriaSource: Copy constructor called" << std::endl;
    _index_arr_materias = copy._index_arr_materias;
    int i = 0;
    while (i < 4)
    {
        if (copy._arr_materias[i])
            this->_arr_materias[i] = copy._arr_materias[i]->clone();
        i++;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (DEBUG)
        std::cout << "MateriaSource: Assignment operator called" << std::endl;
    _index_arr_materias = other._index_arr_materias;
    int i = 0;
    while (i < 4)
    {
        if (other._arr_materias[i])
            this->_arr_materias[i] = other._arr_materias[i]->clone();
        i++;
    }
    return (*this);
}

MateriaSource::~MateriaSource(void)
{
    if (DEBUG)
        std::cout << "MateriaSource: Destructor called" << std::endl;
    int i = 0;
    while (i < 4)
    {
        if (_arr_materias[i])
        {
            std::cout << "enters here -- MateriaSource destruction" << std::endl;
            delete this->_arr_materias[i];
        }
        i++;
    }
}