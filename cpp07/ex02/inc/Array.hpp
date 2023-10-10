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
    // Array(const Array &copy);
    // Array& operator=(const Array &other);
    ~Array(void);

    // operator overloading
    // overloading [] ???
private:
    T*              _array;
    unsigned int    _size;
};

template<typename T> 
unsigned int Array<T>::size(void) const
{
    return (_size);
}

template<typename T> 
Array<T>::Array(void)
{
    _size = 0;
    std::cout << "default constructor called" << std::endl;
}

template<typename T> 
Array<T>::Array(unsigned int n)
{
    std::cout << "int constructor called " << n <<  std::endl;
    _size = n;
    _array = new T[n];
}

template<typename T> Array<T>::~Array()
{
    delete[] _array;
}


#endif