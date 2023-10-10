# include "Bureaucrat.hpp"

/*-------------------PUBLIC MEMBER FUNCITONS------------------*/

void Bureaucrat::increment(void)
{
    if (_grade > 1)
        _grade = _grade - 1;
    else
        throw(GradeTooLowException());
}

void Bureaucrat::decrement(void)
{
    if (_grade < 150)
        _grade = _grade + 1;
    else
        throw(GradeTooHighException());
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

/*------------CONSTTRUCTORS, ASSIGNMENT, DESTRUCTORS--------------*/

Bureaucrat::Bureaucrat(void)
    :_name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
    :    _name(name), _grade(grade)
{
    if (grade < 1)
        throw (GradeTooLowException());
    if (grade > 150)
        throw (GradeTooHighException());
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