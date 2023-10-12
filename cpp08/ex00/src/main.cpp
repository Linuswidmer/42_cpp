#include "easyfind.hpp"

int main(void)
{
    std::vector<int> vec;
    vec.push_back(10);
    int item = 3;
    // if ( std::find(vec.begin(), vec.end(), item) != vec.end() )
    //     std::cout << "found" << std::endl;
    // else
    //     std::cout << "not found" << std::endl;
    vec.push_back(3);
    // if ( std::find(vec.begin(), vec.end(), item) != vec.end() )
    //     std::cout << "found" << std::endl;
    // else
    //     std::cout << "not found" << std::endl;

    if (easyfind(vec, item) != vec.end())
        std::cout << "found" << std::endl;
    else
        std::cout << "not found" << std::endl;

    // try now with different container types
    // what are associative containers
}