#ifndef DATE_HPP
#define	DATE_HPP

#include <string>
#include <sstream>
#include <iostream>
#include <limits>

class	Date
{
	public:
		Date(std::string &date);
		Date(int Y, int M, int D);
		Date(const Date& copy);
		Date&	operator=(const Date& copy);
		~Date();
		int	getYear(void) const;
		int	getMonth(void) const;
		int	getDay(void) const;
		int	getDateDayVal(void) const;
		bool	operator<(const Date& second) const;

	private:
		int	year;
		int	month;
		int	day;
		int dateDayVal;
		Date();
};

std::ostream&	operator<<(std::ostream& os, const Date& d);

#endif	// ! DATE_HPP