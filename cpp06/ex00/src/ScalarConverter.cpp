# include "ScalarConverter.hpp"

/*-------------------PUBLIC MEMBER FUNCITONS------------------*/

void    ScalarConverter::display(char c)
{
    int     i = static_cast<int>(c);
    float   f = static_cast<float>(c);
    double  d = static_cast<double>(c);

    std::cout   << "char: " << c << std::endl
                << "int: "  << i << std::endl
                << "float: " << f << ".0f" << std::endl
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
    std::cout   << "float: " << f;
    if (d == i)
        std::cout << ".0f" << std::endl;
    else
        std::cout << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void    ScalarConverter::display(float f)
{
    char    c = static_cast<char>(f);
    int     i = static_cast<int>(f);
    double  d = static_cast<float>(f);

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
    std::cout   << "float: " << f;
    if (d == i)
        std::cout << ".0f" << std::endl;
    else
        std::cout << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
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
                << "float: " << f << ".0f" << std::endl
                << "double: " << d << std::endl;
}

bool    ScalarConverter::isChar(const char *s)
{
    if (strlen(s) == 1)
    {
        if (s[0] >= 32 && s[0] <= 126)
            return (true);
    }
    return (false);
}

bool    ScalarConverter::isInt(const char *s)
{
    for (size_t i = 0; i <= strlen(s); i++)
    {
        if (i == strlen(s))
            return (true);
        if (isdigit(s[i]) == 0)
        {
            if (i == 0 && s[i] == '-')
                continue;
            else
                break;
        }
    }
    return (false);
}

bool    ScalarConverter::isDouble(const char *s)
{
    bool    fraction = 0;

    for (size_t i = 0; i <= strlen(s); i++)
    {

        if (i == strlen(s))
            return (true);
        if (isdigit(s[i]) == 0)
        {
            if (i == 0 && s[i] == '-')
                continue;
            else if (s[i] == '.' && i != 0 && fraction == 0 && i != (strlen(s) - 1)) // check if character is . and not last character
            {
                fraction = 1;
                continue;
            }
            else
                break;
        }
    }
    std::string str(s);
    if (str == "nan" || str == "-inf" || str == "+inf")
        return (true);
    return (false);
}

bool    ScalarConverter::isFloat(const char *s)
{
    bool    fraction = 0;
    for (size_t i = 0; i <= strlen(s); i++)
    {
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
    std::string str(s);
    if (str == "nanf" || str == "-inff" || str == "+inff")
        return (true);
    return (false);
}


EScalarType    ScalarConverter::detectType(const char *s)
{
    if (isChar(s) == true)
    {
        std::cout << "is char" << std::endl;
        return (type_char);
    }
    else if (isInt(s) == true)
    {
        std::cout << "is int" << std::endl;
        return (type_int);
    }
    else if (isDouble(s) == true)
    {
        std::cout << "is double" << std::endl;
        return (type_double);
    }
    else if (isFloat(s) == true)
    {
        std::cout <<  "is float" << std::endl;
        return (type_float);
    }
    else
        return (invalid);
}

void    ScalarConverter::convertImpl(const char *s)
{
    EScalarType scalar_type;

    scalar_type = detectType(s);
    if (scalar_type == type_char)
        display(s[0]);
    else if (scalar_type == type_double)
    {
        char *c = const_cast<char *>(s); 
        display(strtod(c, &c));
    }
    else if (scalar_type == type_float)
    {
        char *c = const_cast<char *>(s); 
        display(strtof(c, &c));
    }
    else if (scalar_type == type_int)
        display(atof(s));
    else
        throw(NotConvertibleException());
}


void    ScalarConverter::convert(const char *s)
{
    get().convertImpl(s); // overhead for directly assessing the functionalities without creating an instance
}

/*------------------- GETTERS AND SETTERS ------------------*/

ScalarConverter&    ScalarConverter::get(void)
{
    static ScalarConverter S_Instance;
    return (S_Instance);
}
/*------------CONSTRUCTORS, ASSIGNMENT, DESTRUCTORS--------------*/

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::~ScalarConverter(void)
{
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return (*this);
}

ScalarConverter::ScalarConverter(const ScalarConverter& s)
{
    (void)s;
}

/*-------------------EXCEPTIONS------------------*/

const char *ScalarConverter::NotConvertibleException::what() const throw()
{
    return ("Exception: Not convertible");
}
