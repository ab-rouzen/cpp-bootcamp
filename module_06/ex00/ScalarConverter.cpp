#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()	{}

void	ScalarConverter::convert(char *str)
{
	literalType	type = getType(str);
	//std::string	literal = str;
	switch(type)
	{
		std::cout.setf(std::ios::showpos);
		// std::cout.setf(std::ios::showpos);
		case LUNDEFINED:
			std::cout << "String literal undefined." << std::endl;
			break;
		case LINTEGER:
			std::cout << "String literal is of type integer." << std::endl;
			convertInt(str);
			break;
		case LFLOAT:
			std::cout << "String literal is of type float." << std::endl;
			convertFloat(str);
			break;
		case LDOUBLE:
			std::cout << "String literal is of type double." << std::endl;
			convertDouble(str);
			break;
		case LCHAR:
			std::cout << "string literal is of type char." << std::endl;
			convertChar(str);
			break;
	}
	std::cout << str << std::endl;
}

literalType	ScalarConverter::getType(std::string literal)
{
	literalType	type = LUNDEFINED;

	if (literal.size() == 1)
		if (literal[0] < '0' || literal[0] > '9')
			return (LCHAR);
	bool	dotFound = false;
	for (unsigned int i = 0; i < literal.size(); i++)
	{
		if (i == 0 && (literal[0] == '-' || literal[0] == '+'))
			;
		else if ((literal[i] >= '0' && literal[i] <= '9'))
			type = LINTEGER;
		else if (literal[i] == '.' && i != 0 && i < literal.size() - 1 && dotFound == false)
			dotFound = true;
		else if (literal[i] == 'f' && i == literal.size() - 1)
			type = LFLOAT;
		else
		{
			type = LUNDEFINED;
			break;
		}
	}
	if (dotFound == true & type == LINTEGER)
		type = LDOUBLE;
	else if (literal == "+inf")
		type = LPINF;
	else if (literal == "-inf")
		type = LMINF;
	else if (literal == "nan")
		type = LNAN;
	else if (literal == "+inff")
		type = LPINFF;
	else if (literal == "-inff")
		type = LMINFF;
	else if (literal == "nanf")
		type = LNANF;
	return (type);
}

void	ScalarConverter::convertInt(char *str)
{
	std::string literal = str;
	std::stringstream stream(literal);
	int val;
	stream >> val;
	char	charVal = static_cast<char> (val);
	float	floatVal = static_cast<float> (val);
	double	doubleVal = static_cast<double> (val);
	std::cout.setf(std::ios::showbase);
	std::cout << "char   : " << charVal << std::endl;
	std::cout << "int    : " << val << std::endl;
	std::cout << "float  : " << floatVal << ".0f" << std::endl;
	std::cout << "double : " << doubleVal << ".0" << std::endl;
}

void	ScalarConverter::convertFloat(char *str)
{
	std::string literal = str;
	std::stringstream stream(literal);
	float val;
	stream >> val;
	char	charVal = static_cast<char> (val);
	int		intVal = static_cast<int> (val);
	double	doubleVal = static_cast<double> (val);
	std::cout.setf(std::ios::showbase);
	std::cout << "char   : " << charVal << std::endl;
	std::cout << "int	 : " << intVal << std::endl;
	std::cout << "float  : " << val << std::endl;
	std::cout << "double : " << doubleVal << std::endl;
}

void	ScalarConverter::convertDouble(char *str)
{
	std::string literal = str;
	std::stringstream stream(literal);
	double val;
	stream >> val;
	char	charVal = static_cast<char> (val);
	int		intVal = static_cast<int> (val);
	float	floatVal = static_cast<float> (val);
	std::cout << "char   : " << charVal << std::endl;
	std::cout << "int	 : " << intVal << std::endl;
	std::cout << "float  : " << floatVal << std::endl;
	std::cout << "double : " << val << std::endl;
}

void	ScalarConverter::convertChar(char *str)
{
	char	val = *str;
	double	doubleVal = static_cast<double> (val);
	int		intVal = static_cast<int> (val);
	float	floatVal = static_cast<float> (val);
	std::cout << "char   : " << val << std::endl;
	std::cout << "int	 : " << intVal << std::endl;
	std::cout << "float  : " << floatVal << std::endl;
	std::cout << "double : " << doubleVal << std::endl;
}
