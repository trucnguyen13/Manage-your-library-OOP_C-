#pragma once
#include"Readers.h"
#include"Vouchers.h"


class menu
{
public:
	menu();

	static void yeucau_book(date);     //menu sach
	static void yeucau_reader(date);   //menu doc gia
	static void yeucau_voucher(date);  //menu phieu muon

	~menu();
};