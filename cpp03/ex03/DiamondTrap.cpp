# include "DiamondTrap.hpp"

void    DiamondTrap::whoAmI(void)
{
    cout    << "ClapTrap name: " << ClapTrap::name() << endl 
            << "DiamondTrap name: " << _name 
            << endl;
}

DiamondTrap::DiamondTrap (const string& name)
    : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    cout << "DiamondTrap " << name << ": Constructor called" << endl;
    _name = name;
    this->hit_points(FragTrap::hit_points());
    this->energy_points(ScavTrap::energy_points());
    this->attack_damage(FragTrap::attack_damage());
}

DiamondTrap::~DiamondTrap(void)
{
cout << "DiamondTrap " << _name << ": Destructor called" << endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy)
    : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
    cout << "DiamondTrap Copy constructor called" << endl;
}

// DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
// {
//     cout << "DiamondTrap Copy assginment constructor called" << endl;
//     if (this != &other) 
//     {
//         _name = other._name;
//         _hit_points = other._hit_points;
//         _energy_points = other._energy_points;
//         _attack_damage = other._attack_damage;
//     }
//     return *this;
// }

std::ostream& operator<<(std::ostream& o, DiamondTrap const& rhs)
{
    o << static_cast<const ScavTrap&>(rhs);
    return (o);
}