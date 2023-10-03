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
        _clone_record[_index_clone_record] = _arr_materias[idx];
        save = _arr_materias[idx];
        std::cout << _arr_materias[idx] << std::endl;
        std::cout << _clone_record[_index_clone_record] << std::endl;
        _index_clone_record++; 
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
    if (m)
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
    else
        std::cout   << "ERROR: invalid pointer to Materia" << std::endl;
}

std::string const&  Character::getName(void) const
{
    return (_name);
}

Character::Character(void)
    :_name("default"), _index_arr_materias(0), _index_clone_record(0)
{
    memset(_arr_materias, 0, 4 * sizeof(AMateria*));
    memset(_clone_record, 0, 100 * sizeof(AMateria*));
    if (DEBUG)
        std::cout << "Character: Default constructor called" << std::endl;
}

Character::Character(const std::string& name)
    :_name(name), _index_arr_materias(0), _index_clone_record(0)
{
    memset(_arr_materias, 0, 4 * sizeof(AMateria*));
    memset(_clone_record, 0, 100 * sizeof(AMateria*));
    if (DEBUG)
        std::cout << "Character: String constructor called" << std::endl;
}

Character::Character(const Character& copy)
{
    if (DEBUG)
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

Character& Character::operator=(const Character &other)
{
    if (DEBUG)
        std::cout << "Character: Assignment operator called" << std::endl;

    this->_name = other._name;
    // delete existing materias
    for (int i = 0; i < 4; i++)
    {
        if (_arr_materias[i])
            delete _arr_materias[i];
    }
    //copy new materias
    for (int i = 0; i < 4; i++)
    {
        if (other._arr_materias[i])
            this->_arr_materias[i] = other._arr_materias[i]->clone();
    }
    return (*this);
}

Character::~Character(void)
{
    std::cout << "index clone records: " << _index_clone_record << std::endl;
    if (DEBUG)
        std::cout << "Character: Destructor called" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (_arr_materias[i])
            delete _arr_materias[i];
    }
    delete save;
    // for (int i = 0; i < _index_clone_record && i < 100; i++)
    // {
    //     std::cout << _clone_record[_index_clone_record] << std::endl;
    //     std::cout << "Clone record destruction" << std::endl;
    //     delete _clone_record[_index_clone_record];
    // }
}