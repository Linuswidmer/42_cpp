#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    try
    {
        Bureaucrat karl =  Bureaucrat("karl", 100);
        Bureaucrat anna =  Bureaucrat("anna", 130);
        AForm *important_form = new ShrubberyCreationForm("home");
    
        important_form->beSigned(karl);
        std::cout << *dynamic_cast<ShrubberyCreationForm*>(important_form) << std::endl;
        important_form->beSigned(anna);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught" << std::endl;
    }
}