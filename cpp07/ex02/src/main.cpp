#include "Array.hpp"

int main(void)
{
    std::cout << "Test1: Empty array" << std::endl;
    Array<int> empty; 
    std::cout << empty.size() << std::endl;
    try
    {
        std::cout << empty[0] << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }


    std::cout << std::endl << "Basic test:" << std::endl;
    Array<int> a(5);
    for (int i = 0; i < 5; i++)
    {
        a[i] = i;
    }
    for (int i = 0; i < 5; i++)
    {
        std::cout << a[i] << std::endl;
    }

    std::cout << std::endl << "Demonstrating exceptions" << std::endl;
    try
    {
        std::cout << a[6] << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        a[-2] = 99;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl << "Assignment and copy constructor" << std::endl;
    std::cout << a.size() << std::endl;
    Array<int> b(a);
    a[0] = 123;
    std::cout << a[0] << std::endl;
    std::cout << b[0] << std::endl;
    a = b;
    std::cout << a[0] << std::endl;
}