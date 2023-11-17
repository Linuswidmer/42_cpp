#include "Span.hpp"
#include <ctime>

int main(void)
{
    std::srand(static_cast<unsigned>(std::time(NULL))); // set seed for nmumber generator
    Span    span(10);

    std::cout << "------------------ EXAMPLE 1 --------------------\n";
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

    std::cout << "------------------ EXAMPLE 2 --------------------\n";
    Span span2(10);
    std::list<int> list;
    list.push_back(2);
    list.push_back(4);
    list.push_back(11);
    list.push_back(5);
    for (std::list<int>::iterator it = list.begin(); it != list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    span2.addRange(list.begin(), list.end());
    std::cout << "Longest span is: " << span2.longestSpan() << std::endl;
    std::cout << "Shortest span is: " << span2.shortestSpan() << std::endl;

    std::cout << std::endl;
    std::cout << "------------------ EXCEPTIONS --------------------\n";
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

    try
    {
        span.addRange(list.begin(), list.end());
    }
    catch(std::exception &e)
    {
        std::cout << e.what();
    }

    std::cout << std::endl;
    std::cout << "--------------- COPY / ASSIGNMENT ----------------\n";

    Span span_copy(span);
    std::cout << "Copy example 1: \n";
    std::cout << "Longest span is: " << span_copy.longestSpan() << std::endl;
    std::cout << "Shortest span is: " << span_copy.shortestSpan() << std::endl;

    std::cout << std::endl;

    Span span_new = span2;
    std::cout << "Copy example 2: \n";
    std::cout << "Longest span is: " << span_new.longestSpan() << std::endl;
    std::cout << "Shortest span is: " << span_new.shortestSpan() << std::endl;

}