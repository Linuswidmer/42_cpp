#include "whatever.hpp"
#include <iostream>

int main(void)
{
    int a = 2;
    int b = 3;

    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
}