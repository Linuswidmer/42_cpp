# include "AForm.hpp"
# include "Bureaucrat.hpp"

void    AForm::beSigned(Bureaucrat& b)
{
    b.signForm(*this);
    if (b.getGrade() <= _min_grade_sign)
        _signed_status = 1;
    else
        throw (GradeTooLowException());
}

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

std::exception AForm::GradeTooLowException(void)
{
    std::cout << "Error, grade too low" << std::endl;
    return (std::exception());
}

std::exception AForm::GradeTooHighException(void)
{
    std::cout << "Error, grade too high" << std::endl;
    return (std::exception());
}

AForm::AForm(const std::string name, int min_grade_sign, 
            int min_grade_exec)
    : _name(name), _signed_status(0), 
    _min_grade_sign(min_grade_sign), _min_grade_exec(min_grade_exec)
{
    if (_min_grade_sign < 1 || _min_grade_exec < 1)
        throw (AForm::GradeTooLowException);
    else if (_min_grade_sign > 150 || _min_grade_exec > 150)
        throw (AForm::GradeTooHighException);
}