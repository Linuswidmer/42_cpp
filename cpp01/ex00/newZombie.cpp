#include "Zombie.hpp"

Zombie    *newZombie(std::string name)
{
    Zombie *newInstance;

    newInstance = new Zombie(name);
    return (newInstance);
}