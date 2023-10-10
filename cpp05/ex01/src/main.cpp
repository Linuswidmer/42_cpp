#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    std::cout << "Test 1: everything works, no exception" << std::endl;
    try
    {
        Form important_form = Form("Important Form", 120, 120);
        std::cout << important_form << std::endl;
        
        Bureaucrat karl =  Bureaucrat("karl", 100);
    
        important_form.beSigned(karl);

        important_form.beSigned(karl);
    }
    catch (std::exception &e)
    {
        std::cout   << "Exception caught: "
                    << e.what() << std::endl;
    }

    std::cout << std::endl << "Test 2: GradeTooLowException" << std::endl;
    try
    {
        Form important_form = Form("Important Form", 120, 120);
        Bureaucrat anna =  Bureaucrat("anna", 130);
        
        important_form.beSigned(anna);
    }
    catch(std::exception &e)
    {
        std::cout   << "Exception caught: "
                    << e.what() << std::endl;
    }
    std::cout   << std::endl << "Test 3: Copy constructor and assignment of Form" 
                << std::endl;
    Bureaucrat karl =  Bureaucrat("karl", 100);
    Form important_form = Form("Important Form", 120, 120);
    important_form.beSigned(karl);
    Form important_form_new = Form(important_form);
    std::cout << important_form_new;
    Form important_form2;
    important_form2 = important_form;
    std::cout << important_form2;

}