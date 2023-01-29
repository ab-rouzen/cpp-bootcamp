#include "Defs.hpp"

Contact	PhoneBook::GetContact(int index)
{
	if (index - 1 >= top || index - 1 < 0)
	{	
		throw std::out_of_range("Error");
	}
	return (Book[index - 1]);
}

void	PhoneBook::add(const std::string *str)
{
	int	i = count % size;
	Book[i].AddFirstName(str[0]);
	Book[i].AddLastName(str[1]);
	Book[i].AddNickName(str[2]);
	Book[i].AddPhoneNumber(str[3]);
	Book[i].AddSecret(str[4]);
	top++;
	count++;
	if (top > size)
		top = size;
}

void	SetFormat()
{
	std::cout << std::setw(10) << std::setfill(' ');
	std::cout << std::setiosflags(std::ios::left);
}

void	Truncate(std::string& str)
{
	if (str.size() >= 10)
		str[9] = '.';
}

void	PhoneBook::PrintContactTable()
{
	for (int i = 0; i < top; i++)
	{
		SetFormat();
		std::cout << i + 1 << "|";
		SetFormat();
		std::string str = Book[i].GetFirstName().substr(0, 10);
		Truncate(str);
		std::cout << str << "|";
		SetFormat();
		str = Book[i].GetLastName().substr(0, 10);
		Truncate(str);
		std::cout << str << "|";
		SetFormat();
		str = Book[i].GetNickName().substr(0, 10);
		Truncate(str);
		std::cout << str << std::endl;
	}
}

PhoneBook::PhoneBook(int BookSize)
{
	top = 0;
	count = 0;
	size = BookSize;
}
