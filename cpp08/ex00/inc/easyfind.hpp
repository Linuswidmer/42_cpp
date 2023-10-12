#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

// // template <typename T>
// std::vector<int>::iterator    easyfind(std::vector<int> &container, int &find)
// {
//     for(std::vector<int>::iterator container_begin = container.begin();
//         container_begin != container.end(); ++container_begin)
//     {
//         if (*container_begin == find)
//             return (container_begin);
//     }
//     return (container.end());
// }


// i dont understand why I have to say typename before C every time... in cpp07 i didnt need to
template <typename C>
typename C::iterator easyfind(C &container, const int &find)
{
    for (typename C::iterator container_begin = container.begin();
        container_begin != container.end(); ++container_begin)
    {
        if (*container_begin == find)
            return container_begin;
    }
    return container.end();
}


#endif