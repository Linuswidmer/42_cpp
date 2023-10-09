#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class Form;

class Bureaucrat
{
public:
    // Constructors, Assignment Operator, Destructors
    Bureaucrat(void);
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat& copy);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat(void) throw();

    // Getters and Setters
    std::string getName(void) const;
    int         getGrade(void) const;
    void        signForm(Form& f) const;

    // Public Member functions
    void    increment(void);
    void    decrement(void);
private:
    // Data Members
    const std::string   _name;
    int                 _grade;
    // Exceptions    
    class GradeTooHighException: public std::exception 
    {
    public:
        const char *what () const throw();
    };
    class GradeTooLowException: public std::exception 
    {
    public:
        const char *what () const throw();
    };
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const rhs);

#endif