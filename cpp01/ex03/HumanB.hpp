#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
    public:
        HumanB(void);
        void        attack(void);

    private:
        std::string _name;
        Weapon      type;
};

#endif