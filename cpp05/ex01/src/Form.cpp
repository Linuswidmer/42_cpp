# include "Form.hpp"
# include "Bureaucrat.hpp"

/*-------------------PUBLIC MEMBER FUNCITONS------------------*/


void    Form::beSigned(Bureaucrat& b)
{
    b.signForm(*this);
    if (b.getGrade() <= _min_grade_sign)
        _signed_status = 1;
    else
        throw (Form::GradeTooLowException());
}

/*------------------- GETTERS AND SETTERS ------------------*/

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

/*------------CONSTRUCTORS, ASSIGNMENT, DESTRUCTORS--------------*/

Form::Form(void)
    : _name("default"), _signed_status(0), 
    _min_grade_sign(150), _min_grade_exec(150)
{
}

Form::Form(const std::string name, int min_grade_sign, 
            int min_grade_exec)
    : _name(name), _signed_status(0), 
    _min_grade_sign(min_grade_sign), _min_grade_exec(min_grade_exec)
{
    if (_min_grade_sign < 1 || _min_grade_exec < 1)
        throw (Form::GradeTooLowException());
    else if (_min_grade_sign > 150 || _min_grade_exec > 150)
        throw (Form::GradeTooHighException());
}

Form::Form(const Form& copy)
    : _name(copy._name), _signed_status(copy._signed_status), 
    _min_grade_sign(copy._min_grade_sign), _min_grade_exec(copy._min_grade_exec)
{
}

Form&   Form::operator=(const Form& other)
{
    if (this != &other)
    {
        _signed_status = other._signed_status;
    }
    return (*this);
}

Form::~Form(void)
{
}

/*-------------------EXCEPTIONS------------------*/


const char* Form::GradeTooHighException::what(void) const throw()
{
    return ("Error, grade too high");
}

const char* Form::GradeTooLowException::what(void) const throw()
{
    return ("Error, grade too low");
}

/*-------------------OPERATOR OVERLOAD ------------------*/

std::ostream& operator<<(std::ostream& o, Form const rhs)
{
    o   << "Form name: " << rhs.getName() << std::endl
        << "Signed status: " << rhs.getSignedStatus() << std::endl
        << "Min grade sign: " << rhs.getMinGradeSign() << std::endl
        << "Min grade exec: "  << rhs.getMinGradeExec() << std::endl;
    return (o);
}