#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
class Bureaucrat;

class Form 
{
public:
    // Constructors, Assignment & Destructor
    Form(void);
    Form(const std::string name, int min_grade_sign, 
            int min_grade_exec);
    Form(const Form& copy);
    Form& operator=(const Form& other);
    ~Form(void);

    // Getters and Setters
    std::string     getName(void) const;
    bool            getSignedStatus(void) const;
    int             getMinGradeSign(void) const;
    int             getMinGradeExec(void) const;

    // Public member functions
    void            beSigned(Bureaucrat& b);
private:
    // Data members
    const std::string   _name;
    bool                _signed_status;
    const int                 _min_grade_sign;
    const int                 _min_grade_exec;

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

std::ostream& operator<<(std::ostream& o, Form const rhs);

#endif