#include "Span.hpp"
#include <ctime>

int main(void)
{
    std::srand(static_cast<unsigned>(std::time(NULL))); // set seed for nmumber generator
    Span    span(10);

    for (int i = 0; i < 10; i++)
    {
        int random_number = std::rand() % 100;
        span.addNumber(random_number);
        std::cout << random_number << " ";
    }
    std::cout << std::endl;

    std::cout << "Longest span is: " << span.longestSpan() << std::endl;
    std::cout << "Shortest span is: " << span.shortestSpan() << std::endl;

    std::cout << std::endl;

    Span span2(10);
    std::list<int> list;
    list.push_back(2);
    list.push_back(4);
    list.push_back(11);
    list.push_back(5);
    span2.addRange(list.begin(), list.end());
    // std::cout << "Longest span is: " << span2.longestSpan() << std::endl;
    // std::cout << "Shortest span is: " << span2.shortestSpan() << std::endl;

    try
    {
        span.addNumber(5);
    }
    catch(std::exception &e)
    {
        std::cout << e.what();
    }

    try
    {
        Span span(1);
        span.addNumber(5);
        span.longestSpan();
    }
    catch(std::exception &e)
    {
        std::cout << e.what();
    }


}