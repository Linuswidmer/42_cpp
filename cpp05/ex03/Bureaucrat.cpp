# include "Bureaucrat.hpp"
# include "AForm.hpp"

/*-------------------PUBLIC MEMBER FUNCITONS------------------*/

void    Bureaucrat::executeForm(AForm const & f) const
{
    std::string reason;

    if (f.getSignedStatus() == 0)
        reason = " because Form was not yet signed";
    else if(_grade >=  f.getMinGradeExec())
        reason = " because Bureaurats grade is too low";
    if (reason.empty())
            std::cout   << _name << " executed " << f.getName() << std::endl;
    else
        std::cout   << _name << " couldn't execute " << f.getName()
                    << reason << std::endl;
}

void    Bureaucrat::signForm(AForm& f) const
{
    std::string reason;

    if (f.getSignedStatus() == 1)
        reason = " because Form was already signed";
    else if(_grade >=  f.getMinGradeSign())
        reason = " beacause Bureaurats grade is too low";
    
    if (reason.empty())
            std::cout   << _name << " signed " << f.getName() << std::endl;
    else
        std::cout   << _name << " couldn't sign " << f.getName() << reason << std::endl;
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

/*------------------- GETTERS AND SETTERS ------------------*/

std::string Bureaucrat::getName(void) const
{
    return (_name);
}

int Bureaucrat::getGrade(void) const
{
    return (_grade);
}

/*------------CONSTRUCTORS, ASSIGNMENT, DESTRUCTORS--------------*/

Bureaucrat::Bureaucrat(void)
    :_name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
    :    _name(name), _grade(grade)
{
    if (grade < 1)
        throw (Bureaucrat::GradeTooLowException());
    if (grade > 150)
        throw (Bureaucrat::GradeTooHighException());
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
    : _name(copy.getName()), _grade(copy.getGrade())
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
    {
        //_name = other._name; // name is const so we cannot assign it?
        _grade = other.getGrade();
    }
    return (*this);
}

Bureaucrat::~Bureaucrat(void) throw()
{
}

/*-------------------EXCEPTIONS------------------*/


const char* Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Error, grade too high");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("Error, grade too low");
}

/*-------------------OPERATOR OVERLOAD ------------------*/

std::ostream& operator<<(std::ostream& o, Bureaucrat const rhs)
{
    o << rhs.getName() << " , bureaucrat grade " << rhs.getGrade() << std::endl;
    return (o);
}