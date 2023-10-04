#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class Form;

class Bureaucrat: public std::exception 
{
public:
    Bureaucrat(const std::string name, int grade);
    ~Bureaucrat(void) throw();

    std::string getName(void) const;
    int         getGrade(void) const;
    void        signForm(Form& f) const;

    static std::exception   GradeTooLowException(void);
    static std::exception   GradeTooHighException(void);
    void                    increment(void);
    void                    decrement(void);
    // static std::exception   GradeTooLowException;
    // static std::exception   GradeTooHighException;

private:
    const std::string   _name;
    int                 _grade;
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const rhs);

#endif