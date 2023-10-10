# include "AForm.hpp"
# include "Bureaucrat.hpp"

/*-------------------PUBLIC MEMBER FUNCITONS------------------*/


void    AForm::beSigned(Bureaucrat& b)
{
    b.signForm(*this);
    if (b.getGrade() <= _min_grade_sign)
        _signed_status = 1;
    else
        throw (AForm::GradeTooLowException());
}

/*------------------- GETTERS AND SETTERS ------------------*/

std::string AForm::getName(void) const
{
    return (_name);
}

bool    AForm::getSignedStatus(void) const
{
    return (_signed_status);
}

int AForm::getMinGradeSign(void) const
{
    return (_min_grade_sign);
}

int AForm::getMinGradeExec(void) const
{
    return (_min_grade_exec);
}

/*------------CONSTRUCTORS, ASSIGNMENT, DESTRUCTORS--------------*/

AForm::AForm(void)
    : _name("default"), _signed_status(0), 
    _min_grade_sign(150), _min_grade_exec(150)
{
}

AForm::AForm(const std::string name, int min_grade_sign, 
            int min_grade_exec)
    : _name(name), _signed_status(0), 
    _min_grade_sign(min_grade_sign), _min_grade_exec(min_grade_exec)
{
    if (_min_grade_sign < 1 || _min_grade_exec < 1)
        throw (AForm::GradeTooLowException());
    else if (_min_grade_sign > 150 || _min_grade_exec > 150)
        throw (AForm::GradeTooHighException());
}

AForm::AForm(const AForm& copy)
    : _name(copy._name), _signed_status(copy._signed_status), 
    _min_grade_sign(copy._min_grade_sign), _min_grade_exec(copy._min_grade_exec)
{
}

AForm&   AForm::operator=(const AForm& other)
{
    if (this != &other)
    {
        _signed_status = other._signed_status;
    }
    return (*this);
}

AForm::~AForm(void)
{
}

/*-------------------EXCEPTIONS------------------*/


const char* AForm::GradeTooHighException::what(void) const throw()
{
    return ("Error, grade too high");
}

const char* AForm::GradeTooLowException::what(void) const throw()
{
    return ("Error, grade too low");
}

const char* AForm::FormNotSignedException::what(void) const throw()
{
    return ("Error, Form has not been signed");
}

/*-------------------OPERATOR OVERLOAD ------------------*/
