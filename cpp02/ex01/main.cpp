#include "Fixed.hpp"

int main()
{
Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );
a = Fixed( 1234.4321f );
std::cout << std::endl << "Float representation" << std::endl;
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << std::endl << "Integer representation" << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
std::cout << std::endl << "Own tests" << std::endl;
a = c.toInt();
std::cout << "a is " << a << std:: endl;
a = 7.34f;
std::cout << "a is " << a.toFloat() << std:: endl;
return 0;
}