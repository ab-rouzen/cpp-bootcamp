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

// input example: 8 8 + 9 9 * -
class	RPN
{
	public:
		RPN(const string& exp);
		~RPN();
		void	setExp(const string& exp);
		int		getResult();

	private:
		bool				isValidOp(char c);
		int					calc(char op, int arg1, int arg2);
		std::stack<int>		s;
		RPN(const RPN& copy);
		RPN&	operator=(const RPN& copy);
};

#endif // ! RPN_HPP