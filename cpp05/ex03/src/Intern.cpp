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

    for (i = 0; i < 3 && list_form_names[i] != form_name; i++)
    {
        if (list_form_names[i] == form_name)
            break;
    }
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
        throw(Intern::FormDoesNotExistException());
        break;
    }
    return (form);
}

/*-----------CONSTRUCTOR, ASSIGNEMENT, DESTRUCTOR------ */

Intern::Intern(void)
{}

Intern::Intern(const Intern& copy)
{
    (void)copy;
}

Intern& Intern::operator=(const Intern& other)
{
    if (this != &other)
    {}
    return (*this);
}

Intern::~Intern(void)
{}

/*----------------------EXCEPTIONS-----------------------*/

const char* Intern::FormDoesNotExistException::what(void) const throw()
{
    return ("Error, can't create Form, does not exist");
}