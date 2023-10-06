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

class ScalarConverter
{
public:
    static ScalarConverter& get(void);

    static void convert(const char *s);
private:
    ScalarConverter(void); // we dont want the class to be instanciable outside
    ScalarConverter(const ScalarConverter& s); // prevents copying
    // also make assignment operator inaccessible
    ~ScalarConverter(void);

    void        convertImpl(const char *s);
    EScalarType detectType(const char *s);
    void        display(void);
    void        display(char c);
    void        display(double d);
    void        display(int i);
};

#endif