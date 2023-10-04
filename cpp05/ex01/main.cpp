#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    try
    {
        Bureaucrat karl =  Bureaucrat("karl", 100);
        Bureaucrat anna =  Bureaucrat("anna", 130);
        Form important_form = Form("Important Form", 120, 120);
    
        important_form.beSigned(karl);
        std::cout << important_form << std::endl;
        important_form.beSigned(anna);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught" << std::endl;
    }
}