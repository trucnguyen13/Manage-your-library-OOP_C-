#include"book_foreign.h"


SACHNN::SACHNN()
{
	_code = "";
	_name = "";
	_author = "";
	_publisher = "";
	_price = "";
	_ISBN = "";
}

void SACHNN::Input_book(bool str)
{
	cout << "---Input data of foreign book:" << endl;
	

	
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
		cout << "Input_ISBN: ";
		getline(cin, _ISBN);
		cout << "Input_price: ";
		cin >> _price;
	}
	
}

void SACHNN::Write_book(ostream& infile)
{
	
	infile << "1" << endl;
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
	infile << "Book's ISBN: " << endl;
	infile << _ISBN << endl;
	
}

void SACHNN::Read_book(istream& infile)
{
	//getline(infile, _code);
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
	getline(infile, _ISBN);
	getline(infile, _ISBN);

}

void SACHNN::Output_book()
{
	cout << "SACHNN    ";
	cout << "Book's code: ";
	cout << _code;
	cout << "      Book's name: ";
	cout << _name;
	cout << "      Book's author: ";
	cout << _author;
	cout << "      Book's publisher: ";
	cout << _publisher;
	cout << "      Book's price: ";
	cout << _price;
	cout << "      Bool's ISBN ";
	cout << _ISBN << endl;
}

bool SACHNN::kind()
{
	return 1;
}


string SACHNN::get_ISBN()
{
	return _ISBN;
}
void SACHNN::set_ISBN(string ISBN)
{
	_ISBN = ISBN;
}


SACHNN::~SACHNN()
{

}