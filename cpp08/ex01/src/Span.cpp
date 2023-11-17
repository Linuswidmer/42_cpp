#include "Span.hpp"

/*------------------------------ PUBLIC METHODS -----------------------------*/

unsigned int    Span::shortestSpan(void) const
{
    if (_list.size() < 2)
        throw(std::runtime_error("Span::logestSpan: too few numbers in span\n"));

    unsigned int shortestSpan = UINT32_MAX;
    for (std::list<int>::const_iterator it = _list.begin(); it != _list.end(); it++)
    {
        for (std::list<int>::const_iterator it2 = _list.begin(); it2 != _list.end(); it2++)
        {
            if ( it == it2 )
                continue;
            else
            {
                if ( *it >= *it2 && static_cast<unsigned int>( *it - *it2 ) < shortestSpan )
                    shortestSpan = std::labs(*it - *it2 );
                else if ( *it2 >= *it && static_cast<unsigned int>( *it2 - *it ) < shortestSpan )
                    shortestSpan = std::labs( *it2 - *it );
                else
                    continue;
            }
        }
    }
    return ( shortestSpan );    
}

unsigned int    Span::longestSpan(void) const
{
    if (_list.size() < 2)
        throw(std::runtime_error("Span::shortestSpan: too few numbers in span\n"));

    std::list<int>::const_iterator min_it = 
        std::min_element(_list.begin(), _list.end());
    std::list<int>::const_iterator max_it =
        std::max_element(_list.begin(), _list.end());
    return (*max_it - *min_it);
}

void    Span::addRange(std::list<int>::iterator begin, std::list<int>::iterator end)
{
    if (_list.size() + std::distance(begin, end) > _maxSize)
        throw std::out_of_range("Span::addRange: Too many elements to Span\n");
    else
        _list.insert(_list.end(), begin, end);
}

void    Span::addNumber(int num)
{
    if (_list.size() < _maxSize)
        _list.push_back(num);
    else
        throw(std::out_of_range("Span::addNumber: Span is full\n"));
}

/*------------------- CONSTRUCTOR, ASSIGNEMENT, DESTRUCTOR ------------------*/

Span::Span(void)
{
}

Span::Span(unsigned int N)
    :_maxSize(N), _list()
{
}

Span::Span(const Span& copy)
{
    *this = copy;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _list = other._list;
    }
    return (*this);
}

Span::~Span(void)
{}
