#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "header.h"

class MateriaSource: public IMateriaSource
{
public:
    MateriaSource(void);
    // Copy Constructor
    // Copy Assignment
    ~MateriaSource(void);

    void        learnMateria(AMateria *materia); //override
    AMateria    *createMateria(std::string const &type); // override

private:
    AMateria    *_arr_materias[4];
    int         _index_arr_materias;
};

#endif