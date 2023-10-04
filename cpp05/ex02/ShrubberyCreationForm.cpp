# include "ShrubberyCreationForm.hpp"

void    ShrubberyCreationForm::execute(const Bureaucrat& executer) const
{
    if (getSignedStatus() == 1 && executer.getGrade() <= getMinGradeExec())
    {
        std::ofstream   output_file(_target.c_str());
    }

    // should I make distinct exceptions for ecery error?
    // i.e. not signed ...

}

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

//do I have to make the AForm orthodox canonical now as well???
// ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
//     :
// {

// }

std::ostream& operator<<(std::ostream& o, ShrubberyCreationForm const rhs)
{
    o   << "Form name: " << rhs.getName() << std::endl
        << "Signed status: " << rhs.getSignedStatus() << std::endl
        << "Min grade sign: " << rhs.getMinGradeSign() << std::endl
        << "Min grade exec: "  << rhs.getMinGradeExec() << std::endl;
    return (o);
}