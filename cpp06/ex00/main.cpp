# include "ScalarConverter.hpp"

// dont use argc, argv, make a loop from stdin instead

int main(void)
{
    while(std::cin) 
    {
        std::string input_line;

        getline(std::cin, input_line);
        std::cout << "Converting: " << input_line << std::endl;
        ScalarConverter::convert(input_line.c_str());
        std::cout << std::endl;
    };
}