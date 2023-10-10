#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    AForm *important_form = new PresidentialPardonForm("home");
    std::cout << "Test 1: Exception Form not signed" << std::endl;
    try
    {
        Bureaucrat karl =  Bureaucrat("karl", 10);
        Bureaucrat anna =  Bureaucrat("anna", 130);
        important_form->execute(karl);
    }
    catch (std::exception &e)
    {
        std::cout   << "Exception caught " 
                    << e.what() << std::endl;
    }

    std::cout << std::endl << "Test 2: Grade too low to execute" << std::endl;
    try
    {
        Bureaucrat anna =  Bureaucrat("anna", 140);
        important_form->beSigned(anna);
        important_form->execute(anna);
    }
    catch (std::exception &e)
    {
        std::cout   << "Exception caught " 
                    << e.what() << std::endl;
    }

    std::cout << std::endl << "Test 3: Successfull execution of all 3 forms" << std::endl;
    AForm   *scf = new ShrubberyCreationForm("home");
    AForm   *rrf = new RobotomyRequestForm("Bender");
    AForm   *ppf = new PresidentialPardonForm("Fry");
    try
    {
        Bureaucrat karl =  Bureaucrat("karl", 1);
        
        scf->beSigned(karl);
        scf->execute(karl);

        rrf->beSigned(karl);
        rrf->execute(karl);

        ppf->beSigned(karl);
        ppf->execute(karl);
    }
    catch (std::exception &e)
    {
        std::cout   << "Exception caught " 
                    << e.what() << std::endl;
    }
    delete important_form;
    delete scf;
    delete rrf;
    delete ppf; 
}