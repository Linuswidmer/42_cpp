#ifndef AUTO_POINTER_HPP
# define AUTOPOINTER_HPP

# include <string>

class Example
{
public:
    Example(void);
    // std::string* string;
    auto_ptr<std::string> string;
};


#endif

Example::Example(void)
{
}