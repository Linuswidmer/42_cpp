#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
    public:
        HumanB(const char *name);
        void    attack(void);
        void    setWeapon(Weapon &newWeapon);    

    private:
        std::string _name;
        Weapon      *_type;
};

#endif