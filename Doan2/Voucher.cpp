#include"Voucher.h"

Voucher::Voucher()
{
	_name = "";
}
Voucher::~Voucher()
{

}
void Voucher::Input_voucher()
{
	cout << "Nhap ten nguoi muon: ";
	cin >> ws;
	getline(cin, _name);
	_arr.pushback_books(0);
	_date.ondate();
}
void Voucher::Output_voucher()
{
	cout << "--->>  NAME: " << _name << endl;
	_arr.Output_books();
	_date.Output_date(cout);
}
void Voucher::Write_voucher(ostream& inFile)
{
	inFile << _name << endl;
	_arr.Write_books("voucherss.txt", 0);
	_date.Output_date(inFile);
}
void Voucher::Read_voucher(istream& inFile)
{
	getline(inFile, _name);
	_arr.Read_books(inFile, 0);
	_date.Read_date(inFile);
}
string Voucher::get_name()
{
	return _name;
}
void Voucher::Delete_books(string name,string author)
{
	_arr.delete_books(name, author);
}

bool Voucher::Delete_voucher()
{
	if (_arr.number_books() == 0)
		return 1;
	return 0;
}
void Voucher::add_books()
{
	_arr.add_books();
}
void Voucher::check_all()
{
	_arr.check_all();
}



int Voucher::fee_books()
{
	date dt;
	dt.ondate();
	int day_borrow = _date.date_return(dt);
	if (day_borrow > 7)
		return (day_borrow - 7) * _arr.fee_books();
	else 
		return 0;
}

