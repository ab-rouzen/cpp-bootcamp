#ifndef	SCALAR_CONVERTER_H
#define SCALAR_CONVERTER_H

#include <iostream>
#include <string>
#include <sstream>

enum literalType{
	LUNDEFINED,
	LCHAR,
	LINTEGER,
	LFLOAT,
	LDOUBLE,
	LMINFF,
	LPINFF,
	LNANF,
	LPINF,
	LMINF,
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
};

#endif // ! SCALAR_CONVERTER_H