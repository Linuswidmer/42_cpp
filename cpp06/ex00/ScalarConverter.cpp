# include "ScalarConverter.hpp"

void    ScalarConverter::display(char c)
{
    int     i = static_cast<int>(c);
    float   f = static_cast<float>(c);
    double  d = static_cast<double>(c);

    std::cout   << "char: " << c << std::endl
                << "int: "  << i << std::endl
                << "float: " << f << "f" << std::endl
                << "double: " << d << std::endl;
}

void    ScalarConverter::display(double d)
{
    char    c = static_cast<char>(d);
    int     i = static_cast<int>(d);
    float   f = static_cast<float>(d);

    if (std::isnan(d) || std::isinf(d))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else if (d < 32 || d > 126 || d != i)
    {
        std::cout << "char: not displayable" << std::endl; 
        std::cout << "int: " << i << std::endl;
    }
    else
    {
        std::cout << "char:" << c << std::endl;
        std::cout << "int: " << i << std::endl;
    }
    std::cout   << "float: " << f << "f" << std::endl
                << "double: " << d << std::endl;
}

void    ScalarConverter::display(int i)
{
    char    c = static_cast<char>(i);
    float   f = static_cast<float>(i);
    double  d = static_cast<double>(i);

    if (d < 32 || d > 126 || d != i)
        std::cout << "char: not displayable" << std::endl; 
    else
        std::cout << "char:" << c << std::endl;
    std::cout   << "int: "  << i << std::endl
                << "float: " << f << "f" << std::endl
                << "double: " << d << std::endl;
}

void    ScalarConverter::display(void)
{
    std::cout   << "ERROR" << std::endl;
}

EScalarType    ScalarConverter::detectType(const char *s)
{
    // check if string is char literal
    if (strlen(s) == 1)
    {
        if ((s[0] > 'A' && s[0] < 'Z') || (s[0] > 'a' && s[0] < 'z'))
            return (type_char);
    }
    // check if string is integer
    for (size_t i = 0; i <= strlen(s); i++)
    {
        if (i == strlen(s))
            return (type_int);
        if (isdigit(s[i]) == 0)
        {
            if (i == 0 && s[i] == '-')
                continue;
            else
                break;
        }
    }
    // check if string is float or double 
    // technically I also need to handle scientific formats with E ...
    bool    fraction = 0;
    for (size_t i = 0; i <= strlen(s); i++)
    {

        if (i == strlen(s))
            return (type_double);
        if (isdigit(s[i]) == 0)
        {
            if (i == 0 && s[i] == '-')
                continue;
            else if (s[i] == '.' && i != 0 && fraction == 0 && i != (strlen(s) - 1)) // check if character is . and not last character
            {
                fraction = 1;
                continue;
            }
            else if (s[i] == 'f' && i > 0 && s[i - 1] != '.' && i == (strlen(s) - 1)) // check if las character is f and previous was not .
                return (type_float);
            else
                break;
        }
    }
    // check special values: nan, nanf, -inff, +inff, -inf, +inf
    std::string str(s);
    if (str == "nan" || str == "-inf" || str == "+inf")
        return (type_double);
    if (str == "nanf" || str == "-inff" || str == "+inff")
        return (type_float);
    return (invalid);

}

void    ScalarConverter::convertImpl(const char *s)
{
    EScalarType scalar_type;

    scalar_type = detectType(s);
    if (scalar_type == type_char)
        display(s[0]);
    else if (scalar_type == type_double || scalar_type == type_float)
    {
        char *c = const_cast<char *>(s); 
        display(strtod(c, &c));
    }
    else if (scalar_type == type_int)
        display(atof(s));
    else
        display();
}

void    ScalarConverter::convert(const char *s)
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