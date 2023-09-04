#include "Zombie.hpp"

int main(void)
{
    Zombie  *horde;
    int size;

    size = 5;
    horde = zombieHorde(size, "y2k kids");

    for (int i = 0; i < size; i++)
    {
        horde[i].announce();
    }

    delete[] horde;
    return (0);
}