# include "ShrubberyCreationForm.hpp"
# include "Bureaucrat.hpp"

/*-------------------PUBLIC MEMBER FUNCITONS------------------*/

void    ShrubberyCreationForm::execute(const Bureaucrat& executer) const
{
    if (getSignedStatus() == 0)
        throw(AForm::FormNotSignedException());
    else if (executer.getGrade() > getMinGradeExec())
        throw(AForm::GradeTooLowException());
    else
    {
        std::ofstream   output_file(_target.c_str());
        output_file << "ASCII TREES IN HERE" << std::endl;
    }
}

/*------------CONSTRUCTORS, ASSIGNMENT, DESTRUCTORS--------------*/

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
    : AForm(copy), _target(copy._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
    {
        _target = other._target;
        // _signed_status = other._signed_status;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

/*-------------------OPERATOR OVERLOAD ------------------*/

std::ostream& operator<<(std::ostream& o, ShrubberyCreationForm const rhs)
{
    o   << "Form name: " << rhs.getName() << std::endl
        << "Signed status: " << rhs.getSignedStatus() << std::endl
        << "Min grade sign: " << rhs.getMinGradeSign() << std::endl
        << "Min grade exec: "  << rhs.getMinGradeExec() << std::endl;
    return (o);
}