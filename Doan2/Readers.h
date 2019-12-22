#pragma once
#include"Reader.h"

class Readers        //danh sach doc gia
{
private:
	vector<Reader> _arr;
public:
	Readers();  

	void Push_back(); //them ten
	void Output_reader();  //xuat ten

	void Delete();    //xoa ten
	void Reset();     //xoa toan bo ten
	bool search_name();    //tim ten

	~Readers();
};