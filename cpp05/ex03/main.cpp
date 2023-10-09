#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    // try
    // {
    //     Bureaucrat karl =  Bureaucrat("karl", 10);
    //     Bureaucrat anna =  Bureaucrat("anna", 130);
    //     AForm *important_form = new PresidentialPardonForm("home");
    
    //     // important_form->beSigned(karl);
    //     // std::cout << *dynamic_cast<ShrubberyCreationForm*>(important_form) << std::endl;
    //     // important_form->beSigned(anna);
    //     important_form->execute(karl);
    // }
    // catch (std::exception &e)
    // {
    //     std::cout   << "Exception caught " 
    //                 << e.what() << std::endl;
    // }
    Bureaucrat karl =  Bureaucrat("karl", 10);
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("x", "Bender");
    // std::cout << * dynamic_cast<RobotomyRequestForm*>(rrf);
    // rrf->beSigned(karl);
    std::cout << rrf->getMinGradeExec();
}