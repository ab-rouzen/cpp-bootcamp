#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()	{}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void) copy;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter &copy)
{
	(void) copy;
	return (*this);
}

ScalarConverter::~ScalarConverter()	{}

void	ScalarConverter::convert(char *str)
{
	literalType	type = getType(str);
	switch(type)
	{
		std::cout.setf(std::ios::showpos);
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
		case LPINF : case LNINF: case LPINFF: case LNINFF: case LNANF: case LNAN:
			std::cout << "this is scientific stuff." << std::endl;
			convertScientific(str); 
	}
}

literalType	ScalarConverter::getType(std::string literal)
{
	literalType	type = LUNDEFINED;

	if (literal.length() == 1)
		if (literal[0] < '0' || literal[0] > '9')
			return (LCHAR);
	bool	dotFound = false;
	for (unsigned int i = 0; i < literal.length(); i++)
	{
		if (i == 0 && (literal[0] == '-' || literal[0] == '+'))
			;
		else if ((literal[i] >= '0' && literal[i] <= '9'))
			type = LINTEGER;
		else if (literal[i] == '.' && i != 0 && i < literal.length() - 1 && dotFound == false)
			dotFound = true;
		else if (literal[i] == 'f' && i == literal.length() - 1)
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
		type = LNINF;
	else if (literal == "nan")
		type = LNAN;
	else if (literal == "+inff")
		type = LPINFF;
	else if (literal == "-inff")
		type = LNINFF;
	else if (literal == "nanf")
		type = LNANF;
	return (type);
}

void	ScalarConverter::convertInt(char *str)
{
	std::string literal = str;
	std::stringstream stream(literal);
	long long int	val;
	stream >> val;
	float	floatVal = static_cast<float> (val);
	double	doubleVal = static_cast<double> (val);
	printChar(val);
	if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min())
		std::cout << "int    : " << "impossible" << std::endl;
	else
		std::cout << "int    : " << val << std::endl;
	std::cout << "float  : " << std::setprecision(1) << std::fixed << floatVal << "f" << std::endl;
	std::cout << "double : " << std::setprecision(1) << std::fixed << doubleVal << std::endl;
}

void	ScalarConverter::convertFloat(char *str)
{
	std::string literal = str;
	std::stringstream stream(literal.erase(literal.size() - 1));
	float val;
	stream >> val;
	double	doubleVal = static_cast<double> (val);
	printChar(val);
	printInt(val);
	std::cout << "float  : " << std::setprecision(1) << std::fixed << val << "f" << std::endl;
	std::cout << "double : " << std::setprecision(1) << std::fixed << doubleVal << std::endl;
}
void	ScalarConverter::convertDouble(char *str)
{
	std::string literal = str;
	std::stringstream stream(literal);
	double val;
	stream >> val;
	float	floatVal = static_cast<float> (val);
	printChar(val);
	printInt(val);
	std::cout << "float  : " << std::setprecision(1) << std::fixed << floatVal << "f" << std::endl;
	std::cout << "double : " << std::setprecision(1) << std::fixed << val << std::endl;
}

void	ScalarConverter::convertChar(char *str)
{
	char	val = *str;
	double	doubleVal = static_cast<double> (val);
	int		intVal = static_cast<int> (val);
	float	floatVal = static_cast<float> (val);
	std::cout << "char   : '" << val << "'" << std::endl;
	std::cout << "int    : " << intVal << std::endl;
	std::cout << "float  : " << std::setprecision(1) << std::fixed << floatVal << "f" << std::endl;
	std::cout << "double : " << std::setprecision(1) << std::fixed << doubleVal << std::endl;
}

void	ScalarConverter::printChar(double val)
{
	char	charVal = static_cast<char> (val);
	if (val > UCHAR_MAX || val < 0)
		std::cout << "char   : " << "impossible" << std::endl;
	else if (std::isprint(charVal))
		std::cout << "char   : '" << charVal << "'" << std::endl;
	else
		std::cout << "char   : " << "Non displayable" << std::endl;
}

void	ScalarConverter::convertScientific(char *str)
{
	std::string literal = str;
	if (literal == "nanf" || literal == "+inff" || literal == "-inff")
		literal.erase(literal.length() - 1);
	std::stringstream stream(literal);
	double val;
	stream >> val;
	float	floatVal = static_cast<float> (val);
	std::cout << "char   : " << "impossible" << std::endl;
	std::cout << "int    : " << "impossible" << std::endl;
	std::cout << "float  : " << std::setprecision(1) << std::fixed << floatVal << "f" << std::endl;
	std::cout << "double : " << std::setprecision(1) << std::fixed << val << std::endl;
}

void	ScalarConverter::printInt(double val)
{
	int		intVal = static_cast<int> (val);
	if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min())
		std::cout << "int    : " << "impossible" << std::endl;
	else
		std::cout << "int    : " << intVal << std::endl;
}
