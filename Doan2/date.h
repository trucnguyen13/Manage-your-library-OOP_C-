#pragma once
#include<time.h>
#include<fstream>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

class date    //ngay muon
{
private:
	int _day;
	int _mon;
	int _year;
public:
	date();

	void ondate();            //chinh ngay hien tai
	void Read_date(istream&);    //doc file
	void Write_date(ostream&);   //viet vao file
	void Output_date(ostream&);  //xuat vao file
	static bool IsLeapYear(int); //kiem tra nam nhuan

	static int sum_day(int, int, int); //tong ngay vua tra qua trong nam
	int date_return(date);     //ngay nhieu hon

	~date();
};

