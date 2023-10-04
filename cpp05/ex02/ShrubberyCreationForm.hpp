#ifndef SHRUBBERY_CREATION_FORM_HPP

# define SHRUBBERY_CREATION_FORM_HPP
# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
public:
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(std::string target);
    // not sure about this stuff, since "exception classes dont need to be in orthodox canonical form"
    // ShrubberyCreationForm(const ShrubberyCreationForm& copy);
    // ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    // ~ShrubberyCreationForm(void);
    void    execute(const Bureaucrat& executer) const;


private:
    std::string _target;
};

std::ostream& operator<<(std::ostream& o, ShrubberyCreationForm const rhs);


#endif