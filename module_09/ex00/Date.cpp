#include "Date.hpp"

Date::Date(std::string &date)
{
	std::istringstream	ibuf(date);
	char				skip, skip2;
	ibuf >> year >> skip >> month >> skip2 >> day;
	if (skip != '-' || skip2 != '-')
		std::__throw_runtime_error("Date is invalid.");
	else if (year < 1800 || year > 3000 || month < 1  || month > 12 | day < 1 || day > 31)
		std::__throw_runtime_error("Date is invalid.");
	dateDayVal = year * 365 + month * 30 + day;
};

Date::Date(int Y, int M, int D)
{
	year = Y;
	month = M;
	day = D;
	if (year < 1800 || year > 3000 || month < 1  || month > 12 | day < 1 || day > 31)
		std::__throw_runtime_error("Date is invalid.");
	dateDayVal = year * 365 + month * 30 + day;
};

Date::Date() {
};

Date::Date(const Date& copy)
{
	operator=(copy);
};

Date&	Date::operator=(const Date& copy)
{
	if (this != &copy)
	{
		year = copy.year;
		month = copy.month;
		day = copy.day;
		dateDayVal = copy.dateDayVal;
	}
	return (*this);
};

bool	Date::operator<(const Date& second) const
{
	return (dateDayVal < second.dateDayVal);
}

int	Date::getYear(void) const
{
	return (year);
}

int	Date::getMonth(void) const
{
	return (month);
}

int	Date::getDay(void) const
{
	return (day);
}

int	Date::getDateDayVal(void) const
{
	return(dateDayVal);
}

Date::~Date()	{}

std::ostream&	operator<<(std::ostream& os, const Date& d)
{
	os << d.getYear() << '-' << d.getMonth() << '-' << d.getDay();
	return (os);
}
