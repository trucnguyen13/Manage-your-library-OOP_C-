#include"menu.h"


menu::menu()
{

}

menu::~menu()
{

}


void menu::yeucau_book(date dtt)
{
	BOOKS book;
	book.Read_books(cin, 1);

	int option;
	while (true)
	{
		system("cls");

		cout << "\n\n\t\t ============ CHAO MUNG DEN THU VIEN VNU ============";
		cout << "\n\t\t\t             ";  dtt.Output_date(cout);
		cout << "\n\t 1. Xuat tat ca sach trong thu vien";
		cout << "\n\t 2. Ban muon tang them sach cho thu vien?";
		cout << "\n\t 3. Ban muon xoa 1 vai cuon sach trong thu vien?";
		cout << "\n\t 4. Ban muon chinh sua sach co trong thu vien";
		cout << "\n\t 5. Ban muon tra cuu thong tin sach trong thu vien?";
		cout << "\n\t 6. Ban muon kiem tra sach co trong thu vien khong?";
		cout << "\n\t 7. Reset thu vien";
		cout << "\n\t 8. Sao chep vao file";
		cout << "\n\t 0. Thoat";
		cout << "\n\n\t\t    ==============       END      ==============";


		cout << "\nNhap lua chon: ";
		cin >> option;

		if (option == 1)
		{
			book.Output_books();

		}
		else if (option == 2)
		{
			book.pushback_books(1);

		}
		else if (option == 3)
		{
			book.delete_books();

		}
		else if (option == 4)
		{
			book.fix_data();
		}
		else if (option == 5)
		{
			int op;
			cout << "\t--- BAN MUON TRA CUU BANG GI: " << endl;
			cout << "\n\t 1. Ma sach";
			cout << "\n\t 2. Ten sach";
			cout << "\n\t 3. Tac gia";
			cout << "\n\t 4. NXB";
			cout << "\n\t 5. Gia";
			cout << "\n\t 6. Ma ISBN";

			cout << "\nNhap lua chon: ";
			cin >> op;

			if (op == 1)
			{
				book.search_code();
			}
			if (op == 2)
			{
				book.search_name();
			}
			if (op == 3)
			{
				book.search_author();
			}
			if (op == 4)
			{
				book.search_publisher();
			}
			if (op == 5)
			{
				book.search_price();
			}
			if (op == 6)
			{
				book.search_ISBN();
			}

		}
		else if (option == 6)
		{
			if (book.check_books())
			{
				cout << "---SACH CO TON TAI " << endl;
			}
			else
				cout << "---SACH KHONG TON TAI " << endl;

		}
		else if (option == 7)
		{
			book.reset_books();
			cout << "--TOAN BO SACH DA BI XOA !!!" << endl;

		}
		else if (option == 8)
		{
			book.Write_books("bookss.txt", 1);
		}
		else if (option == 0)
		{
			break;
		}

		system("pause");
	}

}

void menu::yeucau_reader(date dtt)
{
	Readers read;

	int option;
	while (true)
	{
		system("cls");

		cout << "\n\n\t\t ============ CHAO MUNG DEN THU VIEN VNU ============";
		cout << "\n\t\t\t             ";  dtt.Output_date(cout);
		cout << "\n\t 1. Xuat tat ca doc gia";
		cout << "\n\t 2. Ban muon tang them doc gia hom nay";
		cout << "\n\t 3. Ban muon xoa 1 vai doc gia";
		cout << "\n\t 4. Ban muon kiem tra doc gia";
		cout << "\n\t 5. Reset doc gia cho ngay hom nay";
		cout << "\n\t 0. Thoat";
		cout << "\n\n\t\t    ==============       END      ==============";


		cout << "\nNhap lua chon: ";
		cin >> option;

		if (option == 1)
		{
			read.Output_reader();

		}
		else if (option == 2)
		{
			read.Push_back();

		}
		else if (option == 3)
		{
			read.Delete();
		}
		else if (option == 4)
		{
			if (read.search_name())
				cout << "--DOC GIA TON TAI" << endl;
			else
				cout << "--DOC GIA KHONG TON TAI" << endl;
		}
		else if (option == 5)
		{
			cout << "--THU VIEN DA DONG CUA CHO NGAY HOM NAY" << endl;
			read.Reset();
		}

		else if (option == 0)
		{
			read.Reset();
			break;
		}
		system("pause");
	}

}


void menu::yeucau_voucher(date dtt)
{
	Vouchers vch;
	vch.Read_vouchers();


	int option;
	while (true)
	{
		system("cls");

		cout << "\n\n\t\t ============ CHAO MUNG DEN THU VIEN VNU ============";
		cout << "\n\t\t\t             ";  dtt.Output_date(cout);
		cout << "\n\t 1. Xuat tat ca phieu da muon";
		cout << "\n\t 2. Ban muon tang them phieu muon hom nay";
		cout << "\n\t 3. Ban muon xoa 1 vai phieu muon";
		cout << "\n\t 4. Tra sach";
		cout << "\n\t 5. Danh sach bi phat";
		cout << "\n\t 6. Reset phieu muon";
		cout << "\n\t 7. Sao chep vao file";
		cout << "\n\t 0. Thoat";
		cout << "\n\n\t\t    ==============       END      ==============";


		cout << "\nNhap lua chon: ";
		cin >> option;

		if (option == 1)
		{
			vch.Output_vouchers();
		}
		else if (option == 2)
		{
			vch.pushback_vouchers();
			vch.check_all();
			vch.delete_vouchers();
			vch.add_books();
		}
		else if (option == 3)
		{
			vch.delete_name();
		}
		else if (option == 4)
		{
			vch.delete_books();
			vch.delete_vouchers(); //CAP NHAT SACH = 0;
		}
		else if (option == 5)
		{
			vch.check_fee();
		}
		else if (option == 6)
		{
			vch.reset();

		}
		else if (option == 7)
		{
			vch.Write_vouchers();
		}

		else if (option == 0)
		{
			break;
		}
		system("pause");
	}

}
