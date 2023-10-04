# include "Bureaucrat.hpp"
# include "Form.hpp"

void    Bureaucrat::signForm(Form& f) const
{
    if (_grade <=  f.getMinGradeSign())
        std::cout   << _name << " signed " << f.getName() << std::endl;
    else
        std::cout   << _name << " couldn't sign "
                    << f.getName() << "because grade too low"
                    << std::endl;
}

void Bureaucrat::increment(void)
{
    if (_grade > 1)
        _grade = _grade - 1;
    else
        throw(Bureaucrat::GradeTooLowException());
}

void Bureaucrat::decrement(void)
{
    if (_grade < 150)
        _grade = _grade + 1;
    else
        throw(Bureaucrat::GradeTooHighException());
}

std::string Bureaucrat::getName(void) const
{
    return (_name);
}

int Bureaucrat::getGrade(void) const
{
    return (_grade);
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
    :    _name(name), _grade(grade)
{
    if (grade < 1)
        throw (Bureaucrat::GradeTooLowException());
    if (grade > 150)
        throw (Bureaucrat::GradeTooHighException());
}

Bureaucrat::~Bureaucrat(void) throw()
{
}

std::ostream& operator<<(std::ostream& o, Bureaucrat const rhs)
{
    o << rhs.getName() << " , bureaucrat grade " << rhs.getGrade() << std::endl;
    return (o);
}

std::exception Bureaucrat::GradeTooLowException(void)
{
    std::cout << "Error, grade too low" << std::endl;
    return (std::exception());
}

std::exception Bureaucrat::GradeTooHighException(void)
{
    std::cout << "Error, grade too high" << std::endl;
    return (std::exception());
}