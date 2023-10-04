#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat karl =  Bureaucrat("karl", 151);
        std::cout << karl;
        karl.decrement();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught" << std::endl;
    }
}