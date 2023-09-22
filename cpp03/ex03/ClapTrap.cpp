#include "ClapTrap.hpp"

void    ClapTrap::attack(const std::string& target)
{
    if (_energy_points <= 0)
        cout << "ClapTrap " << _name << " has no energy points left" << endl;
    else if (_hit_points <= 0)
        cout << "ClapTrap " << _name << " is dead" << endl;
    else
    {
        _energy_points--;
        cout << "ClapTrap " << _name << " attacks " << target <<
            ", causing " << _attack_damage << " points of damage" << endl; 
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (_energy_points <= 0)
        cout << "ClapTrap " << _name << " has no energy points left" << endl;
    else if (_hit_points <= 0)
        cout << "ClapTrap " << _name << " is dead" << endl;
    else
    {
        _energy_points--;
        cout << "ClapTrap " << _name << " repaired itself for " << amount <<
            " hit points "<< endl;
        _hit_points +=  amount; 
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    _hit_points = _hit_points - amount;
    cout << "ClapTrap " << _name << " takes " << amount << " hit points damage" << endl; 
}

ClapTrap::ClapTrap (const string& name)
    : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    cout << "ClapTrap " << _name << ": Constructor called" << endl;
}

ClapTrap::~ClapTrap(void)
{
    cout << "ClapTrap " << _name << ": Destructor called" << endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
    : _name(copy._name), _hit_points(copy._hit_points), _energy_points(copy._energy_points), _attack_damage(copy._attack_damage)
{
    cout << "ClapTrap Copy constructor called" << endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    cout << "ClapTrap Copy assginment constructor called" << endl;
    if (this != &other) 
    {
        _name = other._name;
        _hit_points = other._hit_points;
        _energy_points = other._energy_points;
        _attack_damage = other._attack_damage;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& o, ClapTrap const& rhs)
{
    o   << "hit points: " << rhs._hit_points << endl
        << "energy points: " << rhs._energy_points << endl
        << "attack_damage: " << rhs._attack_damage << endl;
    return (o);
}

const string&  ClapTrap::name(void) const
{
    return (_name);
}

int ClapTrap::hit_points(void) const
{
    return (_hit_points);
}

int ClapTrap::energy_points(void) const
{
    return (_energy_points);
}

int ClapTrap::attack_damage(void) const
{
    return (_attack_damage);
}

void    ClapTrap::name(string name)
{
    _name = name;
}

void    ClapTrap::hit_points(int hp)
{
    _hit_points = hp;
}

void    ClapTrap::energy_points(int ep)
{
    _energy_points = ep;
}

void    ClapTrap::attack_damage(int ad)
{
    _attack_damage = ad;
}