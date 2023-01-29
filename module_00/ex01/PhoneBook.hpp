#ifndef _PHONE_BOOK_
# define _PHONE_BOOK_

#include "Defs.hpp"

class PhoneBook
{
private:
	int			size;
	Contact		Book[8];
	int			top;
	int			count;
public:
	PhoneBook(int BookSize);;
	void		add(const std::string*);
	Contact		GetContact(int index);
	void		PrintContactTable();
};

#endif // !_PHONE_BOOK_