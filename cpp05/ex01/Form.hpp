#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
class Bureaucrat;

class Form 
{
public:
    Form(const std::string name, int min_grade_sign, 
            int min_grade_exec);

    void            beSigned(Bureaucrat& b);
    std::string     getName(void) const;
    bool            getSignedStatus(void) const;
    int             getMinGradeSign(void) const;
    int             getMinGradeExec(void) const;
    
    static std::exception GradeTooLowException(void);
    static std::exception GradeTooHighException(void);

private:
    const std::string   _name;
    bool                _signed_status;
    int                 _min_grade_sign;
    int                 _min_grade_exec;
};

std::ostream& operator<<(std::ostream& o, Form const rhs);

#endif