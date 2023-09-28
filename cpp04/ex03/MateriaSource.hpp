#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "header.h"

class MateriaSource: public IMateriaSource
{
private:
    AMateria    *_arr_materias[4];
    int         _index_arr_materias;

public:
    MateriaSource(void);
    // Copy Constructor?
    // Copy Assignment?
    ~MateriaSource(void);

    void learnMateria(AMateria *materia);
};

#endif