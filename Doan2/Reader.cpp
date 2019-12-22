#include"Reader.h"

Reader::Reader()
{
	_name = "";
}
Reader::~Reader()
{

}
string Reader::get_name()
{
	return _name;
}
void Reader::set_name(string name)
{
	_name = name;
}
void Reader::Input_name()
{
	cout << "Input name: ";
	cin >> ws;
	getline(cin, _name);
}
void Reader::Output_name()
{
	cout << _name << endl;
}
void Reader::Read_name(ifstream& infile)
{
	getline(infile, _name);

}
void Reader::Write_name()
{
	ofstream infile("Readerss.txt", ios::binary | ios::app);
	infile << _name << endl;
	infile.close();
}

