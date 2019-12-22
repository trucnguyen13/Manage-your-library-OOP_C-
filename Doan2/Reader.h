#pragma once
#include"book_foreign.h"


class Reader      //doc gia
{
private:
	string _name;
public:
	Reader();

	void Input_name();   //nhap du lieu
	void Output_name();  //xuat name man hinh
	void Read_name(ifstream&);  //doc file
	void Write_name();  //viet vao file

	string get_name();
	void set_name(string);

	~Reader();
};








