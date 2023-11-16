#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <iostream>

int main(void)
{
    {
        std::cout << "Trying with vector\n";
        std::vector<int> vec;
        vec.push_back(10);
        vec.push_back(3);
        if (easyfind(vec, 3) != vec.end())
            std::cout << "found" << std::endl;
        else
            std::cout << "not found" << std::endl;
    }

    {
        std::cout << std::endl;
        std::cout << "Trying with deque\n";
        std::deque<int> vec;
        vec.push_back(10);
        vec.push_back(3);
        if (easyfind(vec, 111) != vec.end())
            std::cout << "found" << std::endl;
        else
            std::cout << "not found" << std::endl;
    }
}