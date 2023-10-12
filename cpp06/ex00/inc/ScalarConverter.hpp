#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <string.h>
# include <ctype.h>
# include <cstdlib>
# include <iostream>
# include <sstream>
# include <cmath>

enum EScalarType{
    type_char,
    type_float,
    type_int,
    type_double,
    invalid
};

// Singleton style class that converts a literal into all (possible)
// scalar types
class ScalarConverter
{
public:
    // Public methods
    static void convert(const char *s);

    // Getters and setters
    static ScalarConverter& get(void);

private:
    ScalarConverter(void); // we dont want the class to be instanciable outside
    ScalarConverter(const ScalarConverter& s); // prevents copying
    ScalarConverter& operator=(const ScalarConverter &other);
    ~ScalarConverter(void);

    // Private implementation
    void        convertImpl(const char *s);
    
    void        display(char c);
    void        display(double d);
    void        display(float f);
    void        display(int i);

    EScalarType detectType(const char *s);
    bool        isChar(const char *s);
    bool        isInt(const char *s);
    bool        isFloat(const char *s);
    bool        isDouble(const char *s);

    // Exceptions
    class NotConvertibleException: public std::exception
    {
    public:
        const char *what () const throw();
    };
};

#endif