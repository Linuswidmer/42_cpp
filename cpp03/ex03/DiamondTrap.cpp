# include "DiamondTrap.hpp"

void    DiamondTrap::whoAmI(void)
{
    std::cout  << "Who Am I:" << std::endl   
            << "ClapTrap name: " << ClapTrap::_name << std::endl 
            << "DiamondTrap name: " << _name 
            << std::endl;
}

DiamondTrap::DiamondTrap (void): ClapTrap("_clap_name"), ScavTrap(), FragTrap()
{
    _name = "default";
    std::cout << "DiamondTrap " << _name << ": Constructor called" << std::endl;
    _hit_points = FragTrap::_hit_points;
    _energy_points =  ScavTrap::_energy_points;
    _attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap (const std::string& name): ClapTrap(), ScavTrap(), FragTrap()
{
    _name = name;
    std::cout << "DiamondTrap " << _name << ": Constructor called" << std::endl;
    ClapTrap::_name = name + "_clap_name";
    _hit_points = FragTrap::_hit_points;
    _energy_points =  ScavTrap::_energy_points;
    _attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap " << _name << ": Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy)
    : ClapTrap(copy.ClapTrap::_name), ScavTrap(copy.ScavTrap::_name), FragTrap(copy.FragTrap::_name)
{
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
    _name = copy._name;
    _hit_points = copy._hit_points;
    _energy_points =  copy._energy_points;
    _attack_damage = copy._attack_damage;
}

void    DiamondTrap::stats(void) const
{
    std::cout << "Diamond Trap stats called" << std::endl;
    std::cout << "hit points: " << _hit_points << std::endl
        << "energy points: " << _energy_points << std::endl
        << "attack_damage: " << _attack_damage << std::endl;
}

void    DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << "DiamondTrap Copy assginment constructor called" << std::endl;
    if (this != &other) 
    {
        _name = other._name;
        _hit_points = other._hit_points;
        _energy_points = other._energy_points;
        _attack_damage = other._attack_damage;
    }
    return *this;
}