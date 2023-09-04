#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>
# include <string>

class Zombie {
    public:
        Zombie();
        ~Zombie();
        void announce (void);
        void set_name(const std::string name);

    private:
        std::string _name;
};

Zombie  *zombieHorde(int n, std::string name);

#endif