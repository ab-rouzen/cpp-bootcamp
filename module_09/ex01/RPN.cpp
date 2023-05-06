#include "RPN.hpp"

RPN::RPN(const string& exp)
{
	sstream	isExp(exp);
	char	token;
	while (isExp >> token)
	{
		if (std::isdigit(token))
			s.push(token - 48);
		else if (isValidOp(token))
		{
			if (s.empty() || s.size() == 1)
				std::__throw_logic_error("Logic error");
			int	operand_2 = s.top();
			s.pop();
			int	operand_1 = s.top();
			s.pop();
			s.push(calc(token, operand_1, operand_2));
		}
		else
			std::__throw_invalid_argument("Invalid token found.");
	}
	if (s.size() != 1)
		std::__throw_logic_error("Logic error");
}

bool	RPN::isValidOp(char c)
{
	return ( c == '+' || c == '-' | c == '*' | c == '/');
}

int		RPN::calc(char op, int arg1, int arg2)
{
	if (op == '+')
		return (arg1 + arg2);
	else if (op == '-')
		return (arg1 - arg2);
	else if (op == '*')
		return (arg1 * arg2);
	else if (op == '/')
	{
		if (arg2 == 0)
			std::__throw_runtime_error("Division by zero.");
		return (arg1 / arg2);
	}
	return (0);
}

int	RPN::getResult()
{
	return (s.top());
}