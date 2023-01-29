#include "Defs.hpp"

std::string	GetField(std::string msg)
{
	std::string	field;

	while (field.empty())
	{
		std::cout << msg << std::endl;
		std::getline(std::cin, field);
	}
	return (field);
}

void	SetContactInfo(PhoneBook &Book)
{
	std::string	Input[5];

	Input[0] = GetField("Enter First Name: ");
	Input[1] = GetField("Enter Last Name: ");
	Input[2] = GetField("Enter Nick Name: ");
	Input[3] = GetField("Enter Phone Number: ");
	Input[4] = GetField("Enter Secret: ");
	Book.add(Input);
	std::cout << "Contact has been added.\n";
}

void	PrintContactInfo(PhoneBook& book, int index)
{
	try 
	{
		Contact	contact = book.GetContact(index);
		std::string	str = contact.GetFirstName();
		std::cout << "First Name: " << contact.GetFirstName() << std::endl;
		std::cout << "Last Name: " << contact.GetLastName() << std::endl;
		std::cout << "Nick Name: " << contact.GetNickName() << std::endl;
		std::cout << "Phone Number: " << contact.GetPhoneNumber() << std::endl;
		std::cout << "Secret: " << contact.GetSecret() << std::endl;
	}
	catch (...)
	{
		std::cout << "Contact not found." << std::endl;
	}
}

int	main(void)
{
	PhoneBook	book(8);
	std::string	cmd = "";

	while (true)
	{
		std::cout << std::endl << "Enter Command:" << std::endl;
		if (!std::getline(std::cin, cmd))
			return 0;
		if (cmd == "ADD")
			SetContactInfo(book);
		else if (cmd == "SEARCH")
		{
			int	index = 0;
			book.PrintContactTable();
			std::cout << std::endl << "Enter index of desired contact:\n";
			if (!std::getline(std::cin, cmd))
				return (0);
			std::stringstream	MyNumber(cmd);
			if (!(MyNumber >> index))
				std::cout << "Invalid number" << std::endl;
			else
				PrintContactInfo(book, index);
		}
		else if (cmd == "EXIT")
			return (0);
		else
			std::cout << "Unknown Command" << std::endl;
	}
	return (0);
}
