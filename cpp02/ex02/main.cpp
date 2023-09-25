#include "Fixed.hpp"

int main(void)
{

    {
        Fixed a;
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max( a, b ) << std::endl;
    }

    Fixed   a(7.2f);
    Fixed   b(6.5f);
    Fixed   c(0);

    std::cout << std::endl << "Own tests:" << std::endl;
    // test operator >
    if (a > b)
        std::cout << "[a > b]" << std::endl;
    if (b > a)
        std::cout << "[b > a]" << std::endl;

    // test operator <
    if (a < b)
        std::cout << "[a < b]" << std::endl;
    if (b < a)
        std::cout << "[b < a]" << std::endl;

    // test operator >=
    if (a >= b)
        std::cout << "[a >= b]" << std::endl;
    if (b >= a)
        std::cout << "[b >= a]" << std::endl;

    // test operator <=
    if (a <= b)
        std::cout << "[a <= b]" << std::endl;
    if (b <= a)
        std::cout << "[b <= a]" << std::endl;

    // test operator ==
    if (a == b)
        std::cout << "[a == b]" << std::endl;

    // test operator !=
    if (a != b)
        std::cout << "[a != b]" << std::endl;

    // test operator +
    std::cout << "[a + b] = " << a + b << std::endl;
    //test operator -
    std::cout << "[a - b] = " << a - b << std::endl;
    // test operator *
    std::cout << "[a * b] = " << a * b << std::endl;
    // test operator /
    std::cout << "[a / b] = " << a / c << std::endl;

    //test operator postfix ++
    std::cout << "[a++]" << a++ << std::endl;
    //test operator prefix ++
    std::cout << "[++a]" << ++a << std::endl;
    std::cout << "[++a]" << a << std::endl; 

    //test operator postfix --
    std::cout << "[a++]" << a-- << std::endl;
    //test operator prefix --
    std::cout << "[++a]" << --a << std::endl;
    std::cout << "[++a]" << a << std::endl;

    //test min
    std::cout << "min is" << Fixed::min(a, b) << std::endl;
    //test max
    std::cout << "max is" << Fixed::max(a, b) << std::endl;

    //test min max const
    const Fixed& a_const(33.33f);
    std::cout << "max is" << Fixed::max(a_const, b) << std::endl;
}