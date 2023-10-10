#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    std::cout << "Test 1: Can't create form, does not exist" << std::endl;
    try
    {
        Bureaucrat karl =  Bureaucrat("karl", 10);
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("bla", "Bender");
        rrf->beSigned(karl);
    }
    catch (std::exception &e)
    {
        std::cout   << "Exception caught " 
                    << e.what() << std::endl;
    }

    std::cout << std::endl << "Test 2: Successfullz creating form and exectuing" << std::endl;
    try
    {
        Bureaucrat karl =  Bureaucrat("karl", 10);
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        rrf->beSigned(karl);
        rrf->execute(karl);
    }
    catch (std::exception &e)
    {
        std::cout   << "Exception caught " 
                    << e.what() << std::endl;
    }
}