#include "RPN.hpp"

RPN::RPN(const string& exp)
{
	sstream				isExp(exp);
	string				op;
	std::vector<string>	vecOp;
	vecOp = reverseOps(isExp);
	std::vector<string>::iterator	it = vecOp.begin();
	std::vector<string>::iterator	ite = vecOp.end();
	while(it != ite)
	{
		s.push(*it);
		it++;
	}
	isChanged = true;
}

std::vector<string>&	RPN::reverseOps(sstream& iss)
{
	std::vector<string>	*ops = new std::vector<string>;
	string				tmp;
	while(iss >> tmp)
	{
		ops->push_back(tmp);
	}
	std::reverse(ops->begin(), ops->end());
	return *ops;
}

int	RPN::getResult()
{
	if (isChanged == true)
	{
		string	op1;
		string	op2;
		int		tmpRes;
		string	optr;
		while(!s.empty())
		{
			op1 = s.top();
			s.pop();
			op2 = s.top();
			s.pop();
			if (s.top() == "+")
				tmpRes = std::atoi(op1.c_str()) + std::atoi(op2.c_str());
			else if (s.top() == "-")
				tmpRes = std::atoi(op1.c_str()) - std::atoi(op2.c_str());
			s.pop();
			if (s.empty())
				break;
			s.push(std::to_string(tmpRes));
		}
		res = tmpRes;
	}
	return (res);
}