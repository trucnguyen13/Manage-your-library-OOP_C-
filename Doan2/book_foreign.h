#pragma once
#include"book.h"


class SACHNN: public SACHTV     //sach ngoai ngu
{
private:
	string _ISBN;
public:
	SACHNN();

	void Input_book(bool);
	void Write_book(ostream&);
	void Read_book(istream&);
	bool kind();
	void Output_book();

	string get_ISBN();
	void set_ISBN(string);

	~SACHNN();
};



