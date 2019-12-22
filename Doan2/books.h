#pragma once
#include"book_foreign.h"

class BOOKS     //danh sach sach
{
private:
	vector<SACHTV*> _arr;
public:
	BOOKS();

	void Output_books();        //xuat sach man hinh
	void pushback_books(bool);  //them sach
	void Write_books(string, bool);   //viet vao file  string-ten file, bool 1 sach, bool 0 vouchers
	void Read_books(istream&, bool);  //doc file, cin-cout, bool 1 sach, bool 0 voucher

	
	void delete_books();         //xoa sach dua vao ten sach va tac gia
	void delete_books(string, string);   

	void check_all();    //kiem tra sach co thu vien, neu ko thi xoa
	bool check_books();  //kiem tra sach co trong thu vien ko
	bool check_books(string, string);

	void add_datas(SACHTV*&);  //them du lieu con thue cho sach, danh cho voucher
	void add_books();

	void fix_data();     //sua chua thong tin sach
	int fee_books();     //tong tien sach no trong 1 ngay
	void reset_books();  //xoa toan bo sach
	int number_books();  //so luong sach
	
	void search_code();
	void search_name();
	void search_author();
	void search_publisher();
	void search_price();
	void search_ISBN();

	~BOOKS();
};