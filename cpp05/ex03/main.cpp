#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    try
    {
        Bureaucrat karl =  Bureaucrat("karl", 10);
        Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("shrubery creation", "Bender");
        rrf->beSigned(karl);
    }
    catch (std::exception &e)
    {
        std::cout   << "Exception caught " 
                    << e.what() << std::endl;
    }
}