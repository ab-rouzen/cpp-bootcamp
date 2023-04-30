#ifndef BITCOIN_EXCHANGE_HPP
#define	BITCOIN_EXCHANGE_HPP

#include <map>
#include "Date.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <exception>

typedef std::string string;
typedef std::ifstream ifstream;

class	bitcoinExchange
{
	public:
		bitcoinExchange();
		bitcoinExchange(const bitcoinExchange& copy);
		bitcoinExchange&	operator=(const bitcoinExchange& copy);
		~bitcoinExchange();
		bitcoinExchange(ifstream& input);
		float	getRate(Date& d);

	private:
		std::map<Date, float> data;
};

#endif	// ! BITCOIN_EXCHANGE_HPP