#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base    *generate(void)
{
    std::srand(static_cast<unsigned>(std::time(0)));
    int rand = std::rand();

    if (rand % 3 == 0)
    {
        std::cout << "Generate A" << std::endl;
        return (new A());
    }
    else if (rand % 3 == 1)
    {
        std::cout << "Generate B" << std::endl;
        return (new B());
    }
    else
    {
        std::cout << "Generate C" << std::endl;
        return (new C());
    }
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Pointer is of type A" << std::endl;
    if (dynamic_cast<B*>(p))
        std::cout << "Pointer is of type B" << std::endl;
    if (dynamic_cast<C*>(p))
        std::cout << "Pointer is of type C" << std::endl;
}

void    identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "Reference is of type A" << std::endl;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "Reference is of type B" << std::endl;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "Reference is of type C" << std::endl;
    }
    catch(const std::exception& e)
    {
    }
}

// generally we should never have to identify a subclass as this violates 
// https://en.wikipedia.org/wiki/Liskov_substitution_principle
int main(void)
{
    Base *base_ptr = generate();
    identify(base_ptr);
    identify(*base_ptr);
    delete base_ptr;
}