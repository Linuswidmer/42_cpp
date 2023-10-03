#include "header.h"

void    Character::unequip(int idx)
{
    if (idx > 3)
    {
        std::cout << "ERROR: index only has 4 slots" << std::endl;

    }
    else if (_arr_materias[idx])
    {
        std::cout   << "Unequipping " << _arr_materias[idx]->getType()
                    << std::endl;
        _arr_materias[idx] = NULL; 
    }
    else
    {
        std::cout   << "Inventory slot " << idx << " not equipped"
                    << std::endl;
    }
}

void    Character::use(int idx, ICharacter& target)
{
    if (idx > 3)
    {
        std::cout << "ERROR: index only has 4 slots" << std::endl;
    }
    else if (_arr_materias[idx])
    {
        _arr_materias[idx]->use(target);
    }
    else
    {
        std::cout   << "Inventory slot " << idx << " not equipped"
                    << std::endl;
    }
}

void    Character::equip(AMateria *m)
{
    if (_index_arr_materias < 4)
    {
        std::cout   << "Equipping " << _name << " with " << m->getType()
                    << std::endl;
        _arr_materias[_index_arr_materias] = m;
        _index_arr_materias++;
    }
    else
        std::cout << "No more space in inventory left" << std::endl;
}

std::string const&  Character::getName(void) const
{
    return (_name);
}

Character::Character(void)
    :_name("default"), _index_arr_materias(0)
{
    std::cout << "Character: Default constructor called" << std::endl;
}

Character::Character(const std::string& name)
    :_name(name), _index_arr_materias(0)
{
    std::cout << "Character: String constructor called" << std::endl;
}

Character::Character(const Character& copy)
{
    std::cout << "Character: Copy constructor called" << std::endl;
    
    int i = 0;
    this->_name = copy._name;
    while (i < 4)
    {
        if (copy._arr_materias[i])
            this->_arr_materias[i] = copy._arr_materias[i]->clone();
        i++;
    }
}

Character::~Character(void)
{
    std::cout << "Character: Destructor called" << std::endl;
}