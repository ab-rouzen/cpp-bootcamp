#include <iostream>
#include <fstream>
#include <string>
#include "BitcoinExchange.hpp"

void	printBtxValues(bitcoinExchange& btx, std::ifstream &request);

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "1 parameter is required." << std::endl;
		return(1);
	}
	std::ifstream	inputData("data.csv");
	std::ifstream	request(argv[1]);
	if (!inputData.is_open() || !request.is_open())
	{
		std::cout << "Error opening file" << std::endl;
		return(1);
	}
	try
	{
		bitcoinExchange	btx(inputData);
		printBtxValues(btx, request);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << "Exiting..." << std::endl;
		exit(1);
	}
	return (0);
}

void	printBtxValues(bitcoinExchange& btx, std::ifstream &request)
{
	std::string	buf;
	std::getline(request, buf); // skip first line
	while (std::getline(request, buf))
	{
		std::istringstream	ibuf(buf);
		double				balance;
		std::string			strDate;
		Date				tmpDate;
		if (buf.find('|') == std::string::npos)
		{
			std::cout << "Error: bad input => " << buf << std::endl;
			continue;
		}
		std::getline(ibuf, strDate, '|');
		tmpDate = Date(strDate);
		ibuf >> balance;
		if (balance < 0 || balance > 1000)
		{
			std::cout << "Error: Balance is out of bounds. " << std::endl;
			continue;
		}
		std::cout << tmpDate << " => " << balance << " = " << btx.getRate(tmpDate) * balance << std::endl;
	}
}