#ifndef CHARACTER_H
#define CHARACTER_H

#include "ICharacter.hpp"

class	Character : public ICharacter
{
private:
	std::string	name;
	AMateria	*slot[4];
	int			isEmpty[4];

public:
	Character(const std::string myName);
	~Character();
	Character(const Character &copy);
	Character& operator=(const Character &copy);
	std::string const & getName() const;
	void	equip(AMateria *m);
	void	unequip(int idx);
	void	use(int idx, ICharacter& target);
};

#endif // ! CHARACTER_H