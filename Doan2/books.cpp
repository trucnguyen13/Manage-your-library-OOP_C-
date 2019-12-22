#include"books.h"



BOOKS::BOOKS()
{
	
}
BOOKS::~BOOKS()
{

}
void BOOKS::pushback_books(bool str)
{
	int num;
	cout << "So luong sach ban muon them: ";
	cin >> num;
	
	SACHTV* sach;
	for (int i = 0; i < num; i++)
	{
		int kind;
		cout << "--------------BOOK " << i + 1 << " :----------" << endl;
		cout << "Loai sach:  0-SACHTV   1-SACHNN" << endl;
		cout << "     0 or 1      ";
		cin >> kind;
		if (!kind)
			sach = new SACHTV;
		else
			sach = new SACHNN;
		
		sach->Input_book(str);
		_arr.push_back(sach);
	}

}
void BOOKS::Output_books()
{
	cout << "BOOK LIST" << endl << endl;
	for (int i = 0; i < _arr.size(); i++)
	{
		cout << "--BOOK " << i + 1 << " :     ";
		_arr[i]->Output_book();
	}
}

void BOOKS::Write_books(string filename, bool tr)
{
	if (tr)
	{
		ofstream infile("bookss.txt", ios::binary);
		infile.clear();
		infile.close();
	}

	ofstream infile(filename, ios::binary | ios::app);
	infile << _arr.size() << endl;

	for (int i = 0; i < _arr.size(); i++)
	{
		_arr[i]->Write_book(infile);
	}
	infile.close();

}




void BOOKS::Read_books(istream& inffile, bool str)
{
	if (str)
	{
		ifstream infile("bookss.txt", ios::binary);
		string num;
		getline(infile, num);
		int number = stoi(num);

		SACHTV* sach;

		for (int i = 0; i < number; i++)
		{
			string kind;
			getline(infile, kind);
			int kinds = stoi(kind);
			if (!kinds)
				sach = new SACHTV;
			else
				sach = new SACHNN;
			sach->Read_book(infile);
			_arr.push_back(sach);
		}
		infile.close();
		return;
	}


	string num;
	getline(inffile, num);
	int number = stoi(num);

	SACHTV* sach;

	for (int i = 0; i < number; i++)
	{
		string kind;
		getline(inffile, kind);
		int kinds = stoi(kind);
		if (!kinds)
			sach = new SACHTV;
		else
			sach = new SACHNN;
		sach->Read_book(inffile);
		_arr.push_back(sach);
	}

}


void BOOKS::reset_books()
{
	/*ofstream infile("bookss.txt", ios::binary);
	infile.clear();
	infile << "0" << endl;
	infile.close();*/
	_arr.clear();
}

void BOOKS::delete_books()
{
	int num;
	cout << "So luong sach muon xoa: ";
	cin >> num;
	for (int j = 0; j < num; j++)
	{
		cout << "--BOOK " << j + 1 << " : " << endl;
		string name, author;
		cout << "Nhap ten va tac gia cua cuon sach: " << endl;
		cin >> ws;
		getline(cin, name);
		getline(cin, author);

		if (!check_books(name, author))
		{
			cout << "------SACH KHONG TON TAI !!!------" << endl;
		}
		else
		{
			for (int i = 0; i < _arr.size(); i++)
			{
				if (name == _arr[i]->get_name() && author == _arr[i]->get_author())
				{
					_arr.erase(_arr.begin() + i);
					break;
				}
			}
		}
	}
}

void BOOKS::delete_books(string name, string author)
{
	//cout << name << " " << author << endl;
	for (int i = 0; i < _arr.size(); i++)
	{
		if (name == _arr[i]->get_name() && author == _arr[i]->get_author())
		{
			_arr.erase(_arr.begin() + i);
			return;
		}
	}
}

void BOOKS::fix_data()
{
	int num;
	cout << "So luong sach muon sua: ";
	cin >> num;
	for (int j = 0; j < num; j++)
	{
		cout << "--BOOK " << j + 1 << " : " << endl;
		string name, author;
		cout << "Nhap ten va tac gia cua cuon sach: " << endl;
		cin >> ws;
		getline(cin, name);
		getline(cin, author);

		if (!check_books(name, author))
		{
			cout << "------SACH KHONG TON TAI !!!------" << endl;
		}
		else
		{
			this->delete_books(name, author);
			cout << "  >>NHAP LAI SACH CAN CHINH SUA " << endl;
			SACHTV* sach;
			int kind;
			cout << "--------------BOOK---------" << endl;
			cout << "Loai sach:  0-SACHTV   1-SACHNN" << endl;
			cout << "     0 or 1      ";
			cin >> kind;
			if (!kind)
				 sach = new SACHTV;
			else
				 sach = new SACHNN;
			sach->Input_book(1);
			_arr.push_back(sach);

		}
	}
}



void BOOKS::add_books() //them du lieu con thieu
{
	BOOKS book;
	book.Read_books(cin, 1);
	for (int i = 0; i < _arr.size(); i++)
	{
		book.add_datas(_arr[i]);
	}
}

void BOOKS::add_datas(SACHTV*& tv)
{
	for (int i = 0; i < _arr.size(); i++)
	{
		if (tv->get_name() == _arr[i]->get_name() && tv->get_author() == _arr[i]->get_author())
		{
			tv = _arr[i];
			return;
		}
	}
}

void BOOKS::check_all()
{
	BOOKS book;
	book.Read_books(cin, 1);

	for (int i = 0; i < _arr.size(); i++)
	{
		string name = _arr[i]->get_name();
		string author = _arr[i]->get_author();
		if (!book.check_books(name, author))
		{
			cout <<"  >>>Ten sach: "<< name << "      -Ten tac gia: " << author << endl;
			this->delete_books(name, author);
			i--;
		}
	}

}











bool BOOKS::check_books()
{
	string name, author;
	cout << "Nhap ten va tac gia cua cuon sach: " << endl;
	cin >> ws;
	getline(cin, name);
	getline(cin, author);
	for (int i = 0; i < _arr.size(); i++)
	{
		if (name == _arr[i]->get_name() && author == _arr[i]->get_author())
		{
			return 1;
		}
	}
	return 0;
}

bool BOOKS::check_books(string name, string author)
{
	for (int i = 0; i < _arr.size(); i++)
	{
		if (name == _arr[i]->get_name() && author == _arr[i]->get_author())
		{
			return 1;
		}
	}
	return 0;
}

int BOOKS::fee_books()
{
	int sum = 0;
	for (int i = 0; i < _arr.size(); i++)
	{
		if (_arr[i]->kind())
			sum += 20000;
		else
			sum += 10000;
	}
	return sum;
}




void BOOKS::search_code()
{
	string code;
	cout << "Nhap ma sach: ";
	cin >> ws;
	getline(cin, code);
	cout << endl << endl;
	cout << "Danh sach tim duoc: " << endl << endl;
	for (int i = 0; i < _arr.size(); i++)
	{
		if (code == _arr[i]->get_code())
		{
			_arr[i]->Output_book();
		}
	}
}

void BOOKS::search_name()
{
	string code;
	cout << "Nhap ten sach: ";
	cin >> ws;
	getline(cin, code);
	cout << endl << endl;
	cout << "Danh sach tim duoc: " << endl << endl;
	for (int i = 0; i < _arr.size(); i++)
	{
		if (code == _arr[i]->get_name())
		{
			_arr[i]->Output_book();
		}
	}

}
void BOOKS::search_author()
{
	string code;
	cout << "Nhap tac gia sach: ";
	cin >> ws;
	getline(cin, code);
	cout << endl << endl;
	cout << "Danh sach tim duoc: " << endl << endl;
	for (int i = 0; i < _arr.size(); i++)
	{
		if (code == _arr[i]->get_author())
		{
			_arr[i]->Output_book();
		}
	}
}

void BOOKS::search_publisher()
{
	string code;
	cout << "Nhap NXB sach: ";
	cin >> ws;
	getline(cin, code);
	cout << endl << endl;
	cout << "Danh sach tim duoc: " << endl << endl;
	for (int i = 0; i < _arr.size(); i++)
	{
		if (code == _arr[i]->get_publisher())
		{
			_arr[i]->Output_book();
		}
	}
}

void BOOKS::search_price()
{
	string code;
	cout << "Nhap gia sach: ";
	cin >> ws;
	getline(cin, code);
	cout << endl << endl;
	cout << "Danh sach tim duoc: " << endl << endl;
	for (int i = 0; i < _arr.size(); i++)
	{
		if (code == _arr[i]->get_price())
		{
			_arr[i]->Output_book();
		}
	}
}

void BOOKS::search_ISBN()
{
	string code;
	cout << "Nhap ma ISBN: ";
	cin >> ws;
	getline(cin, code);
	cout << endl << endl;
	cout << "Danh sach tim duoc: " << endl << endl;
	for (int i = 0; i < _arr.size(); i++)
	{
		if (code == _arr[i]->get_ISBN())
		{
			_arr[i]->Output_book();
		}
	}
}



int BOOKS::number_books()
{
	return _arr.size();
}