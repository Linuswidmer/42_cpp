#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <fstream>
class Bureaucrat;
# include "Bureaucrat.hpp"

class AForm 
{
public:
    AForm(const std::string name, int min_grade_sign, 
            int min_grade_exec);

    // do I have to make the destructor here virtual?? I think so yes

    void            beSigned(Bureaucrat& b);
    std::string     getName(void) const;
    bool            getSignedStatus(void) const;
    int             getMinGradeSign(void) const;
    int             getMinGradeExec(void) const;
    virtual void    execute(const Bureaucrat& executer) const = 0;

    static std::exception GradeTooLowException(void);
    static std::exception GradeTooHighException(void);

private:
    const std::string   _name;
    bool                _signed_status;
    int                 _min_grade_sign;
    int                 _min_grade_exec;
};

#endif