#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void    Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" 
        << std::endl;
}

void    Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
        << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
        << std::endl;
}

void    Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now."
        << std::endl;
}


void    Harl::complain(std::string level)
{
    void (Harl::*function_pointer[4])(void);
    function_pointer[0] = &Harl::debug;
    function_pointer[1] = &Harl::info;
    function_pointer[2] = &Harl::warning;
    function_pointer[3] = &Harl::error;

	std::string	msg[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (level == msg[i])
            (this->*function_pointer[i])();        
    }
}

