#include "iter.hpp"

int main(void)
{
    int len = 4;

    std::cout << std::endl << "Test 1" << std::endl;
    const char char_arr[4] = {'a','b','c','d'};
    void (*print_char)(char) = &print;
    iter(char_arr, len, print_char);

    std::cout << "Test 2:" << std::endl;
    int int_arr[4] = {1,2,3,4};
    void (*print_int)(int) = &print;
    iter(int_arr, len, print_int);

    std::cout << std::endl << "Test 3" << std::endl;
    std::string string_arr[4] = {"hello","world","this","is"};
    void (*print_string)(std::string) = &print;
    iter(string_arr, 4, print_string);

    // test also with differnt types for arr and printing function!
}