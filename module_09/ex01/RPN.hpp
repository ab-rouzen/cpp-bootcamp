#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

typedef std::string			string;
typedef	std::stringstream	sstream;

// input example: 1 3 + 4 * 7 - 3
class	RPN
{
	public:
		RPN(const string& exp);
		// RPN(const RPN& copy);
		// RPN&	operator=(const RPN& copy);
		// ~RPN();
		//void	setExp(const string& exp);
		int		getResult();

	private:
		std::vector<string>&		reverseOps(sstream& iss);
		std::stack<string>	s;
		int					res;
		bool				isChanged;
};

#endif // ! RPN_HPP