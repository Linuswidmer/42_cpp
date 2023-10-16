#include "Span.hpp"

int main(void)
{
    Span    span(5);

    for (int i = 10; i < 20; i = i + 2)
    {
        span.addNumber(i);
    }

    std::cout << "Longest span is: " << span.longestSpan() << std::endl;

    try
    {
        span.addNumber(5);
    }
    catch(std::exception &e)
    {
        std::cout << e.what();
    }
}