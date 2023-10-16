#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <stdexcept>
# include <iostream>
# include <algorithm>

// vector cs list:
// https://stackoverflow.com/questions/2209224/vector-vs-list-in-stl

class Span
{
public:
    // public methods
    void            addNumber(int num);
    unsigned int    shortestSpan(void) const;
    unsigned int    longestSpan(void) const;

    // Constructors, Assignment, Destructors
    Span(void);
    Span(unsigned int N);
    Span(const Span& copy);
    Span& operator=(const Span& other);
    ~Span(void);

private:
    // Data
    unsigned int    _size;
    std::vector<int>     _vec;
};

#endif