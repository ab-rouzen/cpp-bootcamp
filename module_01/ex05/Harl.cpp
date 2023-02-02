#include "Defs.hpp"

Harl::Harl()
{
	fComplain[0] = &Harl::debug;
	fComplain[1] = &Harl::info;
	fComplain[2] = &Harl::warning;
	fComplain[3] = &Harl::error;
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";

}

void	Harl::debug(void) const
{
	std::cout << "I love having extra bacon for my "
	"7XL-double-cheese-triple-pickle-special-"
	"ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void) const
{
	std::cout << "I cannot believe adding extra bacon"
	" costs more money. You didn’t put"
	"enough bacon in my burger! If you did, "
	"I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void) const
{
	std::cout << "I think I deserve to have some extra bacon"
	" for free. I’ve been coming for"
	"years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void) const
{
	std::cout << "This is unacceptable! I want to"
	" speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level) const
{
	for (int i = 0; i < 4; ++i)
		if (level == levels[i])
			(this->*fComplain[i])();
}