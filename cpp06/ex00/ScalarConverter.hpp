#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>

class ScalarConverter
{
public:
    static ScalarConverter& get(void);

    static void convert(char *s);
private:
    ScalarConverter(void); // we dont want the class to be instanciable outside
    ScalarConverter(const ScalarConverter& s); // prevents copying
    // also make assignment operator inaccessible
    ~ScalarConverter(void);

    void    convertImpl(char *s);
};

#endif