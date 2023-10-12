#include "iter.hpp"

int main(void)
{
    std::cout << std::endl << "Test 1" << std::endl;
    char char_arr[4] = {'a','b','c','d'};
    void (*print_char)(char) = &print;
    iter(char_arr, 4, print_char);

    std::cout << "Test 2:" << std::endl;
    int int_arr[4] = {1,2,3,4};
    void (*print_int)(int) = &print;
    // to be explicit we can also name the templates parameters
    iter<int[], int, void(*)(int)>(int_arr, 4, print_int);

    std::cout << std::endl << "Test 3" << std::endl;
    std::string string_arr[4] = {"hello","world","this","is"};
    void (*print_string)(std::string) = &print;
    iter(string_arr, 4, print_string);

    // test also with differnt types for arr and printing function!
    // test whether it works when using a variable instead of 4
}