#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename T, typename N, typename F>
void    iter(T& arr, N len, F fun)
{
    for (int i = 0; i < len; i++)
    {
        fun(arr[i]);
    }
}

// for testing
template <typename T>
void    print(T i)
{
    std::cout << i << std::endl;
}

#endif