#include"date.h"



date::date()
{
	_day = _mon = _year = 0;
}

void date::ondate()
{
	time_t now = time(0);
	tm local;
	localtime_s(&local, &now);
	_day = local.tm_mday;
	_mon = local.tm_mon + 1;
	_year = local.tm_year + 1900;
}
date::~date()
{
	_day = _mon = _year = 0;
}

bool date::IsLeapYear(int year)
{
	return ((!(year % 4) && year % 100) || !(year % 400));
}
int date::sum_day(int day, int mon, int year)
{
	int sum = 0;
	for (int i = 1; i < mon; i++)
	{
		if (i == 4 || i == 6 || i == 9 || i == 11)
			sum += 30;
		else if (i == 2)
		{
			if (!IsLeapYear(year))
				sum += 28;
			if (IsLeapYear(year) && day > 29)
				sum += 29;
		}
		else
			sum += 31;
	}
	return sum + day;
}
int date::date_return(date dt)
{
	int day = dt._day;
	int mon = dt._mon;
	int year = dt._year;

	if (year == _year)
	{
		return sum_day(day, mon, year) - sum_day(_day, _mon, _year);
	}
	else
	{
		if (!IsLeapYear(_year))
			return sum_day(day, mon, year) - sum_day(_day, _mon, _year) + 365;
		else
			return sum_day(day, mon, year) - sum_day(_day, _mon, _year) + 366;
	}

}

void date::Output_date(ostream& infile)
{
	infile << _day << " " << _mon << " " << _year << endl;
}
void date::Read_date(istream& infile)
{
	string _date;
	getline(infile, _date);

	istringstream ss(_date);

	string temp;
	ss >> temp;
	_day = stoi(temp);
	ss >> temp;
	_mon = stoi(temp);
	ss >> temp;
	_year = stoi(temp);
}
void date::Write_date(ostream& outfile)
{
	outfile << _day << " " << _mon << " " << _year << endl;
}