#include "Point.hpp"
#include "Fixed.hpp"

bool bsp( Point const a, Point const b,
            Point const c, Point const point)
{
    Fixed a_x = a.getX();
    Fixed a_y = a.getY();
    Fixed b_x = b.getX();
    Fixed b_y = b.getY();
    Fixed c_x = c.getX();
    Fixed c_y = c.getY();
    Fixed p_x = point.getX();
    Fixed p_y = point.getY();

    Fixed w1;
    Fixed w2;

    w1 = (a_x * (c_y - a_y) + (p_y - a_y) * (c_x - a_x) - p_x * (c_y - a_y)) / 
            ((b_y - a_y) * (c_x - a_x) - (b_x - a_x) * (c_y - a_y));
    w2 = (p_y - a_y - w1 * (b_y - a_y)) /
            (c_y - a_y);
    if (w1 > 0 && w2 > 0 && w1 + w2 < 1)
        return (true);
    
    return (false); 
}