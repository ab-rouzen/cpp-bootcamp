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
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my "
	"7XL-double-cheese-triple-pickle-special-"
	"ketchup burger. I really do!" << std::endl << std::endl;
}

void	Harl::info(void) const
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon"
	" costs more money. You didn’t put"
	"enough bacon in my burger! If you did, "
	"I wouldn’t be asking for more!" << std::endl << std::endl;
}

void	Harl::warning(void) const
{
	std::cout << "[ WARNIGN ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon"
	" for free. I’ve been coming for"
	"years whereas you started working here since last month." << std::endl << std::endl;
}

void	Harl::error(void) const
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to"
	" speak to the manager now." << std::endl << std::endl;
}

void	Harl::complain(std::string level) const
{
	int i = 0;
	for (; i < 4; ++i)
		if (level == levels[i])
			break ;
	switch (i)
	{
		case 0:
			(this->*fComplain[0])();
		case 1:
			(this->*fComplain[1])();
		case 2:
			(this->*fComplain[2])();
		case 3:
			(this->*fComplain[3])();
	}
}