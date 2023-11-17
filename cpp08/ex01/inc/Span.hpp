#ifndef SPAN_HPP
# define SPAN_HPP
# include <vector>
# include <stdexcept>
# include <iostream>
# include <algorithm>
# include <stdint.h>
# include <list>

class Span
{
public:
    // public methods
    void            addNumber(int num);
    void            addRange(std::list<int>::iterator begin,
                                std::list<int>::iterator end);
    unsigned int    shortestSpan(void) const;
    unsigned int    longestSpan(void) const;

    // Constructors, Assignment, Destructors
    Span(unsigned int N);
    Span(const Span& copy);
    Span& operator=(const Span& other);
    ~Span(void);

private:
    Span(void);
    
    //data
    unsigned int        _maxSize;
    std::list<int>    _list;
};

#endif