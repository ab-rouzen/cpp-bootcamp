#ifndef HARL_H
#define HARL_H

#include "Defs.hpp"

// typedef void (Harl::*harlMemFn) (void);

class Harl
{
	public:
	
		Harl();
		void	complain(std::string level) const;

	private:

		std::string	levels[4];
		void	(Harl::*fComplain[4]) (void) const;
		void	debug(void) const;
		void	info(void) const;
		void	warning(void) const;
		void	error(void) const;
};

#endif // !HARL_H