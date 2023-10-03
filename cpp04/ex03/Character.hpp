#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "header.h"

class Character: public ICharacter {
public:
    Character(void);
    Character(const std::string& name);
    Character(const Character &copy);
    Character& operator=(const Character &other);
    ~Character(void);

    std::string const&  getName(void) const; //override
    void                equip(AMateria *m); //override
    void                unequip(int idx); //override
    void                use(int idx, ICharacter &target); //override

private:
    std::string _name;
    int         _index_arr_materias;
    AMateria*   _arr_materias[4];
    AMateria*   _clone_record[100];
    AMateria*   save;
    int         _index_clone_record;
};

#endif