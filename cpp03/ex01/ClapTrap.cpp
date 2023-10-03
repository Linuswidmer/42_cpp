#include "ClapTrap.hpp"

void    ClapTrap::attack(const std::string& target)
{
    if (_energy_points <= 0)
        std::cout << "ClapTrap " << _name << " has no energy points left" << std::endl;
    else if (_hit_points <= 0)
        std::cout << "ClapTrap " << _name << " is dead" << std::endl;
    else
    {
        _energy_points--;
        std::cout << "ClapTrap " << _name << " attacks " << target <<
            ", causing " << _attack_damage << " points of damage" << std::endl; 
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (_energy_points <= 0)
        std::cout << "ClapTrap " << _name << " has no energy points left" << std::endl;
    else if (_hit_points <= 0)
        std::cout << "ClapTrap " << _name << " is dead" << std::endl;
    else
    {
        _energy_points--;
        std::cout << "ClapTrap " << _name << " repaired itself for " << amount <<
            " hit points "<< std::endl;
        _hit_points +=  amount; 
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    _hit_points = _hit_points - amount;
    std::cout << "ClapTrap " << _name << " takes " << amount << " hit points damage" << std::endl; 
}

ClapTrap::ClapTrap (const std::string& name)
    : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "ClapTrap " << _name << ": Constructor called" << std::endl;
}

ClapTrap::ClapTrap (void)
    : _name("default"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "ClapTrap " << "default" << ": Constructor called" << std::endl;
}


ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap " << this->_name << ": Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
    : _name(copy._name), _hit_points(copy._hit_points), _energy_points(copy._energy_points), _attack_damage(copy._attack_damage)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "ClapTrap Copy assginment constructor called" << std::endl;
    if (this != &other) 
    {
        _name = other._name;
        _hit_points = other._hit_points;
        _energy_points = other._energy_points;
        _attack_damage = other._attack_damage;
    }
    return *this;
}

void    ClapTrap::stats(void) const
{
    std::cout << "hit points: " << _hit_points << std::endl
        << "energy points: " << _energy_points << std::endl
        << "attack_damage: " << _attack_damage << std::endl;
}

// const std::string&  ClapTrap::name(void) const
// {
//     return (_name);
// }

// int ClapTrap::hit_points(void) const
// {
//     return (_hit_points);
// }

// int ClapTrap::energy_points(void) const
// {
//     return (_energy_points);
// }

// int ClapTrap::attack_damage(void) const
// {
//     return (_attack_damage);
// }

// void    ClapTrap::name(std::string name)
// {
//     _name = name;
// }

// void    ClapTrap::hit_points(int hp)
// {
//     _hit_points = hp;
// }

// void    ClapTrap::energy_points(int ep)
// {
//     _energy_points = ep;
// }

// void    ClapTrap::attack_damage(int ad)
// {
//     _attack_damage = ad;
// }