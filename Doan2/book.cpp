#include"book.h"


SACHTV::SACHTV()
{
	_code = "";
	_name = "";
	_author = "";
	_publisher = "";
	_price = "";
}

void SACHTV::Input_book(bool str)
{
	cout << "---Input data of book:" << endl;
	//

	cout << "Input_name: ";
	cin >> ws;
	getline(cin, _name);
	cout << "Input_author: ";
	getline(cin, _author);
	if (str)
	{
		cout << "Input_code: ";
		getline(cin, _code);
		cout << "Input_publisher: ";
		getline(cin, _publisher);
		cout << "Input_price: ";
		cin >> _price;
	}
}

void SACHTV::Write_book(ostream& infile)
{
	
	infile << "0" << endl;
	infile << "Book's code: " << endl;
	infile << _code << endl;
	infile << "Book's name: " << endl;
	infile << _name << endl;
	infile << "Book's author: " << endl;
	infile << _author << endl;
	infile << "Book's publisher: " << endl;
	infile << _publisher << endl;
	infile << "Book's price: " << endl;
	infile << _price << endl;
	
}

void SACHTV::Read_book(istream& infile)
{
	getline(infile, _code);
	getline(infile, _code);
	getline(infile, _name);
	getline(infile, _name);
	getline(infile, _author);
	getline(infile, _author);
	getline(infile, _publisher);
	getline(infile, _publisher);
	getline(infile, _price);
	getline(infile, _price);
}
bool SACHTV::kind()
{
	return 0;
}

void SACHTV::Output_book()
{
	cout << "SACHTV    ";
	cout << "Book's code: ";
	cout << _code;
	cout << "      Book's name: ";
	cout << _name;
	cout << "      Book's author: ";
	cout << _author;
	cout << "      Book's publisher: ";
	cout << _publisher;
	cout << "      Book's price: ";
	cout << _price << endl;
}












string SACHTV::get_code()
{
	return _code;
}
string SACHTV::get_name()
{
	return _name;
}
string SACHTV::get_author()
{
	return _author;
}
string SACHTV::get_publisher()
{
	return _publisher;
}

string SACHTV::get_price()
{
	return _price;
}

string SACHTV::get_ISBN()
{
	return "";
}

void SACHTV::set_code(string code)
{
	_code = code;
}
void SACHTV::set_name(string name)
{
	_name = name;
}
void SACHTV::set_author(string author)
{
	_author = author;
}
void SACHTV::set_publisher(string publisher)
{
	_publisher = publisher;
}
void SACHTV::set_price(string price)
{
	_price = price;
}






SACHTV::~SACHTV()
{

}