#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "BASIC TEST EXCEPTIONS:" << std::endl;
    Bureaucrat karl =  Bureaucrat("karl", 150);
    try
    {
        std::cout << karl;
        karl.decrement();
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << std::endl << "COPY CONSTRUCTOR AND ASSIGNMENT" << std::endl;
    try
    {
        Bureaucrat karl2 =  Bureaucrat(karl);
        std::cout << karl2;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}