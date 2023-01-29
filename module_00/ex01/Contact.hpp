#ifndef _CONTACT_
# define _CONTACT_

#include "Defs.hpp"

class Contact
{
private:

	std::string	FirstName;
	std::string	LastName;
	std::string	NickName;
	std::string	PhoneNumber;
	std::string	Secret;

public:

	void				AddFirstName(const std::string& str);
	void				AddLastName(const std::string& str);
	void				AddPhoneNumber(const std::string& str);
	void				AddNickName(const std::string& str);
	void				AddSecret(const std::string& str);
	std::string			GetFirstName();
	std::string			GetLastName();
	std::string			GetNickName();
	std::string			GetPhoneNumber();
	std::string			GetSecret();
};

#endif // !_CONTACT_