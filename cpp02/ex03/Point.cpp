#include "Point.hpp"

Fixed Point::getX(void) const
{
    return (_x);
}

Fixed Point::getY(void) const
{
    return (_y);
}

Point::Point(void)
    : _x(0), _y(0)
{
    cout << "Point: Constructor called" << endl;
}

Point::Point(const Point &copy)
    : _x(copy._x), _y(copy._y)
{
    cout << "Point: Copy constructor called" << endl;
}

Point::Point(const float x, const float y)
    : _x(x), _y(y)
{
    cout << "Point: Float constructor called" << endl;
}

Point& Point::operator=(const Point& other)
{
    cout << "Point: Copy assignment called" << endl;
    if (this != &other)
    {
        _x = other._x;
        _y = other._y;
    }
    return (*this);
}

Point::~Point(void)
{
    cout << "Point: Destructor called" << endl;
}