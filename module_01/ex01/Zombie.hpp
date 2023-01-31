#ifndef _ZOMBIE_H_
#define _ZOMBIE_H_

#include "Defs.hpp"

class Zombie
{
	public:
	
	void	initZombie(std::string zombieName);
	~Zombie();
	void	announce(void);
	
	private:
	
	std::string	name;
};

#endif //! _ZOMBIE_H_