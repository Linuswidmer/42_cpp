#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/*------------------PUBLIC METHODS -----------------*/
AForm    *Intern::makeForm(std::string form_name, std::string target)
{
    std::string list_form_names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int         i;
    AForm       *form;

    for (i = 0; i < 3; i++)
    {
        if (list_form_names[i] == form_name);
            break;
    }
    std::cout << "form name is " << form_name << std::endl;
    std::cout << "Intern creates" << list_form_names[i] << std::endl;
    switch (i)
    {
    case 0:
        form = new ShrubberyCreationForm(target);
        break;
    case 1:
        form = new RobotomyRequestForm(target);
        break;
     case 2:
        form = new PresidentialPardonForm(target);
        break;
    default:
        form = NULL; 
        break;
    }
    std::cout << "i is " << i << std::endl;
    // I think throwing an exception here additionally would be nice!
    return (form);
}

/*-----------CONSTRUCTOR, ASSIGNEMENT, DESTRUCTOR------ */

Intern::Intern(void)
{}

Intern::Intern(const Intern& copy)
{}

Intern& Intern::operator=(const Intern& other)
{
    if (this != &other)
    {}
    return (*this);
}

Intern::~Intern(void)
{}