#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array
{
public:
    // public methods
    unsigned int    size(void) const;

    // Constructors, Assignment, Destructor
    Array();
    Array(unsigned int n);
    Array(const Array &copy);
    Array<T>     operator=(const Array &other);
    ~Array(void);

    // operator overloading
    T& operator[](unsigned int idx);
private:
    T*              _array;
    unsigned int    _size;

    //Exception
    class OutOfBoundException: public std::exception
    {
    public:
        const char *what () const throw();
    };
};

/*-------------------- Public methods -------------------------*/

template<typename T> 
unsigned int Array<T>::size(void) const
{
    return (_size);
}

/*-------- Constructors, Assignment & Destructors ---------------*/

template<typename T> 
Array<T>::Array(void)
    :_size(0)
{
    _array = NULL;
    std::cout << "default constructor called" << std::endl;
}

template<typename T> 
Array<T>::Array(unsigned int n)
    :_size(n)
{
    std::cout << "int constructor called " << n <<  std::endl;
    _array = new T[_size];
}

template<typename T> 
Array<T>::Array(const Array<T> &copy)
    : _size(copy._size)
{
    std::cout << "copy constructor called" << std::endl;
    _array = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
    {
        _array[i] = copy._array[i];
    }
}

template<typename T>
Array<T>  Array<T>::operator=(const Array<T> &other)
{
    std::cout << "Assignment called" << std::endl;
    if (this != &other)
    {
        delete[] _array;
        _size = other._size;
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
        {
            _array[i] = other._array[i];
        }
    }
    return (*this);
}

template<typename T>
Array<T>::~Array()
{
    delete[] _array;
}

/*------------------- Operator overload ---------------------*/
template<typename T>
T&  Array<T>::operator[](unsigned int idx)
{
    if (idx >= _size)
        throw(OutOfBoundException());
    return (_array[idx]);
}

/*----------------------- Exception ---------------------*/
template<typename T>
const char    *Array<T>::OutOfBoundException::what(void) const throw()
{
    return ("Error, Index out of bounds");
}

#endif