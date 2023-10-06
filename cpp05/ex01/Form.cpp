# include "Form.hpp"
# include "Bureaucrat.hpp"

// sdjs sdjsd
//

void    Form::beSigned(Bureaucrat& b)
{
    b.signForm(*this);
    if (b.getGrade() <= _min_grade_sign)
        _signed_status = 1;
    else
        throw (Bureaucrat::GradeTooLowException());
}

std::string Form::getName(void) const
{
    return (_name);
}

bool    Form::getSignedStatus(void) const
{
    return (_signed_status);
}

int Form::getMinGradeSign(void) const
{
    return (_min_grade_sign);
}

int Form::getMinGradeExec(void) const
{
    return (_min_grade_exec);
}

Form::Form(const std::string name, int min_grade_sign, 
            int min_grade_exec)
    : _name(name), _signed_status(0), 
    _min_grade_sign(min_grade_sign), _min_grade_exec(min_grade_exec)
{
    if (_min_grade_sign < 1 || _min_grade_exec < 1)
        throw (Bureaucrat::GradeTooLowException());
    else if (_min_grade_sign > 150 || _min_grade_exec > 150)
        throw (Bureaucrat::GradeTooHighException());
}

std::ostream& operator<<(std::ostream& o, Form const rhs)
{
    o   << "Form name: " << rhs.getName() << std::endl
        << "Signed status: " << rhs.getSignedStatus() << std::endl
        << "Min grade sign: " << rhs.getMinGradeSign() << std::endl
        << "Min grade exec: "  << rhs.getMinGradeExec() << std::endl;
    return (o);
}