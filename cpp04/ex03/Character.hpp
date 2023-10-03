#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "header.h"

class Character: public ICharacter {
public:
    Character(void);
    Character(const std::string& name);
    Character(const Character &copy);
    // assignment operator
    ~Character(void);

    std::string const&  getName(void) const; //override
    void                equip(AMateria *m); //override
    void                unequip(int idx); //override
    void                use(int idx, ICharacter &target); //override

private:
    std::string _name;
    int         _index_arr_materias;
    AMateria*   _arr_materias[4];
};

#endif