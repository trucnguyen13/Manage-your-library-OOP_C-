#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class SACHTV    //sach tieng viet
{
protected:
	string _code;
	string _name;
	string _author;
	string _publisher;
	string _price;

public:
	SACHTV();

	virtual void Input_book(bool);      //nhap du lieu
	virtual void Write_book(ostream&);  //viet vao file
	virtual void Read_book(istream&);   //doc file
	virtual bool kind();                //loai sach
	virtual void Output_book();         //xuay sach man hinh

	string get_code();
	string get_name();
	string get_author();
	string get_publisher();
	string get_price();
	string get_ISBN();

	void set_code(string);
	void set_name(string);
	void set_author(string);
	void set_publisher(string);
	void set_price(string);

	~SACHTV();
};



