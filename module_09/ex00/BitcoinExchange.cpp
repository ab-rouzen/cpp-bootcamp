#include "BitcoinExchange.hpp"

bitcoinExchange::bitcoinExchange()	{}

bitcoinExchange::~bitcoinExchange()	{}

bitcoinExchange::bitcoinExchange(const bitcoinExchange& copy)
{
	operator=(copy);
}

bitcoinExchange&	bitcoinExchange::operator=(const bitcoinExchange& copy)
{
	if (this != &copy)
	{
		data = copy.data;
	}
	return (*this);
}

float	bitcoinExchange::getRate(Date& d)
{
	return ((*data.lower_bound(d)).second);
}

bitcoinExchange::bitcoinExchange(ifstream& input)
{
	string	buf;

	// Input example: '2023-03-23,3.4'
	std::getline(input, buf); // skip first line
	if (buf != "date,exchange_rate")
		std::__throw_runtime_error("Unkown database format.");
	while(std::getline(input, buf))
	{
		std::stringstream ibuf(buf);
		std::getline(ibuf, buf, ',');
		Date	tmpDate(buf);
		float rate;
		if (!(ibuf >> rate))
			std::__throw_runtime_error("Exchange rate error.");
		data[tmpDate] = rate;
	}
}
