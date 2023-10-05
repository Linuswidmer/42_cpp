# include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        std::cout << "Please provide one argument" << std::endl;
    else
    {
        ScalarConverter::convert(argv[1]);
    }
}