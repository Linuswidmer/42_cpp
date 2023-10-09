#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    // Test 1 everything works not exception
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

    // Test 2 exception whens signing Form
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

}