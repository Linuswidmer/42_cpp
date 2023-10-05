# include "ScalarConverter.hpp"

void    ScalarConverter::convertImpl(char *s)
{
    // verify input I guess and decide what to convert it to
    char c = s[0];
    float f = static_cast<float>(c);

    std::cout   << "char: " << c << std::endl
                << "int: "  << static_cast<int>(c) << std::endl
                << "float: " << f << std::endl
                << "double: " << static_cast<double>(c) << std::endl;
}

void    ScalarConverter::convert(char *s)
{
    get().convertImpl(s); // overhead for directly assessing the functionalities without creating an instance
}

ScalarConverter&    ScalarConverter::get(void)
{
    static ScalarConverter S_Instance;
    return (S_Instance);
}

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::~ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& s)
{
    (void)s;
}