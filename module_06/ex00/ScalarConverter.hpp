#ifndef	SCALAR_CONVERTER_H
#define SCALAR_CONVERTER_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>

enum literalType{
	LUNDEFINED,
	LCHAR,
	LINTEGER,
	LFLOAT,
	LDOUBLE,
	LNINFF,
	LPINFF,
	LNANF,
	LPINF,
	LNINF,
	LNAN
};

class	ScalarConverter	{
	public:
		static void	convert(char *str);

	private:
		ScalarConverter();
		static literalType	getType(std::string literal);
		static	void		convertInt(char *str);
		static	void		convertDouble(char *str);
		static	void		convertFloat(char *str);
		static	void		convertChar(char *str);
		static	void		convertType(char *str);
		static	void		convertScientific(char *str);
		static	void		printChar(double val);
		static	void		printInt(double val);
};

#endif // ! SCALAR_CONVERTER_H