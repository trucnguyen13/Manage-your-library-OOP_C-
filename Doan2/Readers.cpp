#include"Readers.h"

Readers::Readers()
{
	ifstream infile("Readerss.txt", ios::binary);
	string num;
	getline(infile, num);
	int number = stoi(num);

	
	for (int i = 0; i < number; i++)
	{
		Reader person;
		person.Read_name(infile);
		_arr.push_back(person);
	}
	infile.close();
}
void Readers::Reset()
{
	_arr.clear();
	ofstream infile("Readerss.txt", ios::binary);
	infile.clear();
	infile << "0" << endl;
	infile.close();
}
void Readers::Push_back()
{
	int num;
	cout << "Nhap so luong nguoi can them: ";
	cin >> num;
	
	for (int i = 0; i < num; i++)
	{
		Reader person;
		cout << "---Reader " << i + 1 << " : ";
		person.Input_name();
		_arr.push_back(person);
	}

	ofstream infile("Readerss.txt", ios::binary);
	infile.clear();
	infile << _arr.size() << endl;
	infile.close();

	for (int i = 0; i < _arr.size(); i++)
	{
		_arr[i].Write_name();
	}

}
void Readers::Delete()
{
	string temp;
	cout << "Nhap ten can xoa: ";
	cin >> ws;
	getline(cin, temp);
	for (int i = 0; i < _arr.size(); i++)
	{
		if (temp == _arr[i].get_name())
		{
			_arr.erase(_arr.begin() + i);
			break;
		}
	}

	ofstream infile("Readerss.txt", ios::binary);
	infile.clear();
	infile << _arr.size() << endl;
	infile.close();

	for (int i = 0; i < _arr.size(); i++)
	{
		_arr[i].Write_name();
	}

}
void Readers::Output_reader()
{
	cout << "------------DANH SACH DOC GIA NGAY HOM NAY" << endl << endl;
	for (int i = 0; i < _arr.size(); i++)
	{
		cout << ">>>>>>  Reader " << i + 1 << " : ";
		_arr[i].Output_name();
	}
}


bool Readers::search_name()
{
	string temp;
	cout << "Input name to search: ";
	cin >> ws;
	getline(cin, temp);
	for (int i = 0; i < _arr.size(); i++)
		if (temp == _arr[i].get_name())
			return 1;
	return 0;
	
}















Readers::~Readers()
{

}