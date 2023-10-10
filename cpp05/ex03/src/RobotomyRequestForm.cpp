#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

/*------------------PUBLIC METHODS -----------------*/

void    RobotomyRequestForm::execute(const Bureaucrat& executer) const
{
    executer.executeForm(*this);
    if (getSignedStatus() == 0)
        throw(AForm::FormNotSignedException());
    else if (executer.getGrade() > getMinGradeExec())
        throw(AForm::GradeTooLowException());
    else
    {
        std::cout   << "Brrrrrrrrrrrrrrrr" << std::endl
                    << _target << "'s Robotomy";
        std::srand(static_cast<unsigned>(std::time(0)));
        int rand = std::rand();
        if (rand % 2 == 0)
            std::cout << "was Successfull" << std::endl;
        else
            std::cout << " failed" << std::endl;
    }
}

/*-----------CONSTRUCTOR, ASSIGNEMENT, DESTRUCTOR------ */

RobotomyRequestForm::RobotomyRequestForm(void)
    : AForm("RobotomyRequestForm", 72, 45), _target("default")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
    : AForm(copy), _target(copy._target)
{}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
    {
        _target = other._target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{}

/* ----------------OPERATOR OVERLOAD---------------*/
std::ostream& operator<<(std::ostream& o, RobotomyRequestForm const rhs)
{
    o   << "Form name: " << rhs.getName() << std::endl
        << "Signed status: " << rhs.getSignedStatus() << std::endl
        << "Min grade sign: " << rhs.getMinGradeSign() << std::endl
        << "Min grade exec: "  << rhs.getMinGradeExec() << std::endl;
    return (o);
}