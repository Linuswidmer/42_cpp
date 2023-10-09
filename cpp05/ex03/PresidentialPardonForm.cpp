#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

/*------------------PUBLIC METHODS -----------------*/
void    PresidentialPardonForm::execute(const Bureaucrat& executer) const
{
    executer.executeForm(*this);
    if (getSignedStatus() == 0)
        throw(AForm::FormNotSignedException());
    else if (executer.getGrade() > getMinGradeExec())
        throw(AForm::GradeTooLowException());
    else
        std::cout << _target << " has been pardoned by Zaphold Beeblebrox" << std::endl;
}

/*----------------GETTERS AND SETTERS --------------*/

/*-----------CONSTRUCTOR, ASSIGNEMENT, DESTRUCTOR------ */

PresidentialPardonForm::PresidentialPardonForm(void)
    : AForm("PresidentialPardonForm", 25, 5), _target("default")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target)
{}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
    :AForm(copy), _target(copy._target)
{}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
    {
        _target = other._target;
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{}

/* ----------------OPERATOR OVERLOAD---------------*/
std::ostream& operator<<(std::ostream& o, PresidentialPardonForm const rhs)
{
    o   << "Form name: " << rhs.getName() << std::endl
        << "Signed status: " << rhs.getSignedStatus() << std::endl
        << "Min grade sign: " << rhs.getMinGradeSign() << std::endl
        << "Min grade exec: "  << rhs.getMinGradeExec() << std::endl;
    return (o);
}