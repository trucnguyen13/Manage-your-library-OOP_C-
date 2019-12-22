#pragma once
#include"Reader.h"
#include"date.h"
#include"books.h"


class Voucher   //phieu muon
{
private:
	BOOKS _arr;
	date _date;
	string _name;
public:
	Voucher();   

	void Input_voucher();   //nhap du lieu
	void Output_voucher();  //xuat man hinh
	void Read_voucher(istream&);  //doc file
	void Write_voucher(ostream&); //viet file

	bool Delete_voucher();     //kiem tra so luong sach == 0
	void Delete_books(string, string);   //xoa sach dua vao ten sach va tac gia

	void add_books();   //them du lieu con thieu cho sach khi nhap
	void check_all();   //xuat va xoa nhung sach them vao khong hop le
	int fee_books();    //tien bi phat
	string get_name();  //lay ten

	~Voucher();
};

