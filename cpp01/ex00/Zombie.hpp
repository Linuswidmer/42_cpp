#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>
# include <string>

class Zombie {
    public:
        Zombie(std::string);
        ~Zombie();
        void announce (void);

    private:
        std::string _name;
};

Zombie *newZombie(std::string name);
void    randomChump( std::string name );

#endif