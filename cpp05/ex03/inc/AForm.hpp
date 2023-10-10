#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <fstream>
class Bureaucrat;

class AForm 
{
public:
    // Constructors, Assignment & Destructor
    AForm(void);
    AForm(const std::string name, int min_grade_sign, 
            int min_grade_exec);
    AForm(const AForm& copy);
    AForm& operator=(const AForm& other);
    virtual ~AForm(void);

    // Getters and Setters
    std::string     getName(void) const;
    bool            getSignedStatus(void) const;
    int             getMinGradeSign(void) const;
    int             getMinGradeExec(void) const;

    // Public member functions
    virtual void    execute(const Bureaucrat& executer) const = 0;
    void            beSigned(Bureaucrat& b);
private:
    // Data members
    const std::string   _name;
    bool                _signed_status;
    const int           _min_grade_sign;
    const int           _min_grade_exec;

protected:
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
    class FormNotSignedException: public std::exception 
    {
    public:
        const char *what () const throw();
    };

};

std::ostream& operator<<(std::ostream& o, AForm const rhs);

#endif