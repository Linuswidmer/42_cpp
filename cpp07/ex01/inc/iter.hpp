#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>
#include <stdlib.h>

template <typename T, typename F>
void    iter(T &arr, int len, F fun)
{
    if (arr && fun)
    {
        for (int i = 0; i < len; i++)
        {
            fun(arr[i]);
        }
    }
}

// for testing
template <typename T>
void    print(T i)
{
    std::cout << i << std::endl;
}

#endif