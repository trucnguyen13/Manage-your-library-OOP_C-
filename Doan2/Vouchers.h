#pragma once
#include"Voucher.h"


class Vouchers  //danh sach phieu muon
{
private:
	vector<Voucher> _arr;
public:
	Vouchers();

	void pushback_vouchers();   //them phieu muon
	void Output_vouchers();     //xuat man hinh
	void Write_vouchers();      //viet file
	void Read_vouchers();       //doc file
	
	void delete_name();      //xoa phieu dua vao ten
	void delete_books();     //nop sach 
	void delete_vouchers();  //xoa nhung phieu ko co sach muon.
	
	void check_all();        //kiem tra sach them vao hop le, neu ko thi xoa sach do
	bool check_name(string); //kiem tra ten co trong phieu muon
	void check_fee();        //danh sach phat tien

	void add_books();    //them du lieu cho sach khi nhap
	void reset();        //xoa toan bo phieu muon

	~Vouchers();
};