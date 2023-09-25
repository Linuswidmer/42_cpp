#include "Fixed.hpp"
#include "Point.hpp"

// useful resource: https://planetcalc.com/8108/

bool bsp( Point const a, Point const b,
            Point const c, Point const point);

int main(void)
{
    Point a(7, 7);
    Point b(11, 1);
    Point c(2, 2);

    if (bsp(a, b, c, Point(7,3)) == true)
        cout << endl << "Point is inside of triangle" << endl << endl;
    else
        cout << endl << "Point is outside of triangle" << endl << endl;

    if (bsp(a, b, c, Point(2.0f , 3.0f )) == true)
        cout << endl << "Point is inside of triangle" << endl << endl;
    else
        cout << endl << "Point is outside of triangle" << endl << endl;

    if (bsp(a, b, c, Point(7,7)) == true)
        cout << endl << "Point is inside of triangle" << endl << endl;
    else
        cout << endl << "Point is outside of triangle" << endl << endl;
}