# ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T> inline T min(const T& a, const T& b) {return( (a < b) ? a : b );};
template <typename T> inline T max(const T& a, const T& b) {return( (a > b) ? a : b );};

template <typename T>
void    swap(T& a, T& b)
{
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
}

#endif