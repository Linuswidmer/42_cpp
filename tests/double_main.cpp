#include <iostream>
#include <string>
#include <cstdlib>

int main(void)
{
    // std::string str("0.12324566");
    char *c = ("0.00000000001");

    double d = strtod(c, &c);
    float  f = strtof(c, &c);
    std::cout << d << std::endl;
    std::cout << f << std::endl;
    
}