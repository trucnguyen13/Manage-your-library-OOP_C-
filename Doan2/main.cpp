#include"menu.h"


int main()
{
	date dtt;
	dtt.ondate();
	
	int option;
	while (true)
	{
		system("cls");

		cout << "\n\n\t\t ============ CHAO MUNG DEN THU VIEN VNU ============";
		cout << "\n\t\t\t             ";  dtt.Output_date(cout);
		cout << "\n\t\t 1. QUAN LY SACH THU VIEN";
		cout << "\n\t\t 2. QUAN LY DOC GIA HOM NAY";
		cout << "\n\t\t 3. QUAN LY DOC PHIEU MUON";
		cout << "\n\t\t 0. Thoat";
		cout << "\n\n\t\t    ==============       END      ==============";

		cout << "\nNhap lua chon: ";
		cin >> option;

		if (option == 1)
		{
			menu::yeucau_book(dtt);
		}
		else if (option == 2)
		{
			menu::yeucau_reader(dtt);
		}
		else if (option == 3)
		{
			menu::yeucau_voucher(dtt);
		}
		else if (option == 0)
		{
			break;
		}

	}

	return 0;
}

