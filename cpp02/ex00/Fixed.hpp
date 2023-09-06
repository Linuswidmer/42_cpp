#ifndef FIXED_HPP
# define FIXED_HPP
#include <string>
#include <iostream>

class Fixed
{
private:
    int _fixed_point;
    static const int _fraction = 8;
public:
    Fixed(void);
    Fixed(const Fixed& copy);
    ~Fixed(void);
    int     getRawBits(void) const;
    void    setRawBits(int const raw);

    Fixed& operator=(const Fixed& other);
};
#endif