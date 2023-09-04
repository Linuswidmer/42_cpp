#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA{
    public:
        void        attack(void);

    private:
        std::string _name;
        Weapon      type;
};

#endif