#ifndef FIXED_HPP
# define FIXED_HPP
# include <string>
# include <iostream>
# include <cmath>

class Fixed
{
private:
    int                 _fixed_point;
    static const int    _fractional_bits = 8;

public:
    Fixed(void);
    Fixed(const int i);
    Fixed(const float f);
    Fixed(const Fixed& copy);
    ~Fixed(void);
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;

    Fixed& operator=(const Fixed& other);
};

std::ostream& operator<<(std::ostream& o, Fixed const& rhs);
#endif