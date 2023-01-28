#include <string>
#include <iostream>

class Contact
{
private:

	std::string	FirstName;
	std::string	LastName;
	std::string	NickName;
	std::string	PhoneNumber;
	std::string	Secret;

public:

	inline void				AddFirstName(const std::string& str) {FirstName = str; };
	inline void				AddLastName(const std::string& str) {LastName = str; };
	inline void				AddPhoneNumber(const std::string& str) {PhoneNumber = str; };
	inline void				AddNickName(const std::string& str) {NickName = str; };
	inline void				AddSecret(const std::string& str) {Secret =  str; };
	inline std::string		GetFirstName() {return FirstName; };
	inline std::string		GetLastName() {return LastName; };
	inline std::string		GetNickName() {return NickName; };
};

class PhoneBook
{
private:
	int	size;
	Contact		Book[10];
	int			top;
public:
	PhoneBook(int BookSize);
	~PhoneBook();
	Contact 	find(int index);
	void		add(const std::string*);
	Contact		GetContact(int index);
};

Contact	PhoneBook::GetContact(int index)
{
	if (index > top)
		throw std::out_of_range("Error");
	return (Book[index]);
}
// Contact PhoneBook::find(int	index)
// {
// 	if (index > 0 && index - 1 < top)
// 		return (GetContact(index - 1));
// 	return (0) ;
// }

void	PhoneBook::add(const std::string *str)
{
	if (top < size)
	{
		int	i = top;
		if (top == size - 1)
			i = 0;
		else
			top++;
		Book[i].AddFirstName(str[0]);
		Book[i].AddLastName(str[1]);
		Book[i].AddNickName(str[2]);
		Book[i].AddPhoneNumber(str[3]);
		Book[i].AddSecret(str[4]);
	}
}

PhoneBook::PhoneBook(int BookSize)
{
	top = 0;
	size = BookSize;
}

PhoneBook::~PhoneBook()
{
}

void	SetContactInfo(PhoneBook &Book)
{
	std::string	Input[5];

	std::cout << "Enter First Name:\n";
	std::cin >> Input[0];
	std::cout << "Enter Last Name:\n";
	std::cin >> Input[1];
	std::cout << "Enter Nick Name:\n";
	std::cin >> Input[2];
	std::cout << "Enter Phone Number:\n";
	std::cin >> Input[3];
	std::cout << "Enter Secret:\n";
	std::cin >> Input[4];
	Book.add(Input);

}

int	main(void)
{
	PhoneBook	Book(10);
	std::string	Command;

	while (true)
	{
		std::cout << "Enter Command:" << std::endl;
		std::cin >> Command;
		if (Command == "ADD")
			SetContactInfo(Book);
		else if (Command == "SEARCH")
		{
			int Index;
			std::cout << "Enter index of desired contact:\n";
			std::cin >> Index;
			try {
					Contact	MyContact = Book.GetContact(Index);
					std::cout << "First Name : " << MyContact.GetFirstName() << std::endl;
					std::cout << "Last Name : " << MyContact.GetLastName() << std::endl;
					std::cout << "Nick Name : " << MyContact.GetNickName() << std::endl;
				}
			catch (...)
			{
				std::cout << "Out of RANGE\n";
			}
			
		}
		else if (Command == "EXIT")
			return (0);
		else
			std::cout << "Unknown command" << std::endl;
	}
	return (0);
}
