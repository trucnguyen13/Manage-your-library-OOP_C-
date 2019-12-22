#include"Vouchers.h"


Vouchers::Vouchers()
{
	
}
Vouchers::~Vouchers()
{

}
void Vouchers::pushback_vouchers()
{
	int num;
	cout << "Nhap so luong phieu can them: ";
	cin >> num;
	

	for (int i = 0; i < num; i++)
	{
		Voucher person;
		cout << endl << endl;
		cout << "  >>>Reader " << i + 1 << " : " << endl;
		person.Input_voucher();
		_arr.push_back(person);
	}

}

void Vouchers::Output_vouchers()
{
	cout << "-----DANH SACH PHIEU MUON------" << endl << endl;
	for (int i = 0; i < _arr.size(); i++)
	{
		cout << "Reader " << i + 1 << " : ";
		_arr[i].Output_voucher();
		cout << "------------------------------------------------------------------" << endl << endl << endl;
	}
}

void Vouchers::Write_vouchers()
{

	ofstream inFile("voucherss.txt", ios::binary);
	inFile.clear();
	inFile.close();

	ofstream infile("voucherss.txt", ios::binary | ios::app);
	
	infile << _arr.size() << endl;
	

	for (int i = 0; i < _arr.size(); i++)
	{
		_arr[i].Write_voucher(infile);
	}
	infile.close();
}


void Vouchers::Read_vouchers()
{
	ifstream infile("voucherss.txt", ios::binary);
	string num;
	getline(infile, num);
	int number = stoi(num);


	for (int i = 0; i < number; i++)
	{
		Voucher person;
		person.Read_voucher(infile);
		_arr.push_back(person);
	}
	infile.close();

}


void Vouchers::reset()
{
	_arr.clear();

}
void Vouchers::delete_vouchers()
{
	for (int i = 0; i < _arr.size(); i++)
	{
		if (_arr[i].Delete_voucher())
		{
			_arr.erase(_arr.begin() + i);
			i--;
		}
	}
}

void Vouchers::delete_books()
{

	/*this->Write_vouchers();
	this->reset();
	this->Read_vouchers();*/

	string namereader;
	int num;
	cout << "Nhap so luong nguoi tra: ";
	cin >> num;


	for (int j = 0; j < num; j++)
	{
		
		cout << j + 1 << " .Nhap ten nguoi tra: ";
		cin >> ws;
		getline(cin, namereader);

		if (!check_name(namereader))
			cout << "---TEN NHAP SAI !!!" << endl;
		else
		{

			int num;
			cout << "Nhap so luong sach tra :";
			cin >> num;
			for (int k = 0; k < num; k++)
			{
				string name, author;
				cout << "Nhap ten va tac gia cua sach: " << endl;
				cin >> ws;
				getline(cin, name);
				getline(cin, author);

				for (int i = 0; i < _arr.size(); i++)
				{
					if (namereader == _arr[i].get_name())
					{
						_arr[i].Delete_books(name, author);

					}
				}
			}
		}


	}
}


void Vouchers::add_books()
{
	for (int i = 0; i < _arr.size(); i++)
		_arr[i].add_books();
}

void Vouchers::delete_name()
{

	/*this->Write_vouchers();
	this->reset();
	this->Read_vouchers();*/



	string name;
	int num;
	cout << "Nhap so phieu se xoa: ";
	cin >> num;


	for (int j = 0; j < num; j++)
	{
		//int tr = 0;
		cout << j + 1 << " .Nhap ten nguoi lap phieu: ";
		cin >> ws;
		getline(cin, name);

		if (!check_name(name))
			cout << "---TEN NHAP SAI !!!" << endl;

		else
		{
			for (int i = 0; i < _arr.size(); i++)
			{
				if (name == _arr[i].get_name())
				{
					_arr.erase(_arr.begin() + i);
					i--;

				}
			}
		}

	}

}


void Vouchers::check_all()
{
	cout << endl << endl;
	cout << "  >>>>DANH SACH KHONG CO TRONG THU VIEN " << endl << endl;
	for (int i = 0; i < _arr.size(); i++)
		_arr[i].check_all();
	cout << endl << endl;
	cout << "  >>>>VUI LONG XEM SACH TRUOC KHI THEM " << endl << endl;
}



void Vouchers::check_fee()
{
	Write_vouchers();
	cout << "DANH SACH PHAT TIEN: " << endl;

	while (_arr.size())
	{
		string name = _arr[0].get_name();
		int sum = 0;
		for (int i = 0; i < _arr.size(); i++)
		{
			if (name == _arr[i].get_name())
			{
				sum += _arr[i].fee_books();
				_arr.erase(_arr.begin() + i);
				i--;
			}
		}
		if (sum > 0)
			cout << "Reader: " << name << "   " << sum << " dong" << endl;
	}


	this->reset();
	Read_vouchers();
}


bool Vouchers::check_name(string name)
{
	for (int i = 0; i < _arr.size(); i++)
	{
		if (name == _arr[i].get_name())
			return 1;
	}
	return 0;
}