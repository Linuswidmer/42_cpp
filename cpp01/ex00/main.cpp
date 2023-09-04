#include "Zombie.hpp"

int main(void)
{
    Zombie *Justin;

    Justin = newZombie("Justin");
    randomChump("Britney"); 
    Justin->announce();
    delete Justin;
}