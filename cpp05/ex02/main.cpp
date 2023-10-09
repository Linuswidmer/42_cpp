#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    try
    {
        Bureaucrat karl =  Bureaucrat("karl", 10);
        Bureaucrat anna =  Bureaucrat("anna", 130);
        AForm *important_form = new PresidentialPardonForm("home");
    
        // important_form->beSigned(karl);
        // std::cout << *dynamic_cast<ShrubberyCreationForm*>(important_form) << std::endl;
        // important_form->beSigned(anna);
        important_form->execute(karl);
    }
    catch (std::exception &e)
    {
        std::cout   << "Exception caught " 
                    << e.what() << std::endl;
    }
}