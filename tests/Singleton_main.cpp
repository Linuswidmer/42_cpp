# include "Singleton.hpp"

int main(void)
{
    std::cout << Singleton::Float() << std::endl;

    // Singleton s = Singleton(); // we cannot instanciate it!
}