# include "ScalarConverter.hpp"

// dont use argc, argv, make a loop from stdin instead

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        try
        {
            ScalarConverter::convert(argv[1]);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    else
        std::cout << "Error, correct usage ./scalarconverter <arg>" << std::endl;
}