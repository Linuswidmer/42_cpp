#ifndef SHRUBBERY_CREATION_FORM_HPP

# define SHRUBBERY_CREATION_FORM_HPP
# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
public:
    // Constructor, Assignment & Destructor
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm& copy);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    ~ShrubberyCreationForm(void);

    // public methods
    void    execute(const Bureaucrat& executer) const;

private:
    // Data members
    std::string _target;
};

std::ostream& operator<<(std::ostream& o, ShrubberyCreationForm const rhs);

#endif