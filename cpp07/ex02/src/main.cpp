#include "Array.hpp"

int main(void)
{
    // std::cout << "Test1: Empty array" << std::endl;
    Array<int> empty;

    // std::cout << "Test2: Int array" << std::endl;
    Array<int> a(5);
    for (int i = 0; i < 5; i++)
    {
        a[i] = i;
    }
    for (int i = 0; i < 5; i++)
    {
        std::cout << a[i] << std::endl;
    }

    // std::cout << a[2] << std::endl;
    // a[0] = 2;
    // std::cout << a[0] << std::endl;
    // Array<int> b(a);
    // std::cout << a.size() << std::endl;
    // a[0] = 3;
    // std::cout << a[0] << std::endl;
    // std::cout << b[0] << std::endl;
    // a = b;
    // std::cout << a[0] << std::endl;

    try
    {
        std::cout << a[6] << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}