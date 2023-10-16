#include "Span.hpp"

/*------------------PUBLIC METHODS -----------------*/

unsigned int    Span::shortestSpan(void) const
{
    std::vector<int>::const_iterator min_it = 
        std::min_element(_vec.begin(), _vec.end());
    std::vector<int>::const_iterator max_it =
        std::max_element(_vec.begin(), _vec.end());

    
}

unsigned int    Span::longestSpan(void) const
{
    std::vector<int>::const_iterator min_it = 
        std::min_element(_vec.begin(), _vec.end());
    std::vector<int>::const_iterator max_it =
        std::max_element(_vec.begin(), _vec.end());
    return (*max_it - *min_it);
}

void    Span::addNumber(int num)
{
    if (_vec.size() < _size)
        _vec.push_back(num);
    else
        throw(std::runtime_error("Exception: Span is full\n"));
}

/*-----------CONSTRUCTOR, ASSIGNEMENT, DESTRUCTOR------ */

Span::Span(void)
    :_size(0), _vec()
{
    _vec.reserve(0);
}

Span::Span(unsigned int N)
    :_size(N), _vec()
{
    _vec.reserve(N);
}

Span::Span(const Span& copy)
{
    (void)copy;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {}
    return (*this);
}

Span::~Span(void)
{}

/* ----------------OPERATOR OVERLOAD---------------*/
