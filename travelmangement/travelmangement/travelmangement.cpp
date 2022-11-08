// travelmangement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>
#include<string>
using namespace std;
void menu();
class Customers
{
public:
	string name, gender, address;
	int age, mobileNo;
	static int customID;
	char all[999];
	void detDetails()
	{
		//hear we will open the file and we will append the information to the file
		ofstream out("old-customer.txt",ios::app);
		{
			cout << "Enter the customerid" << endl;
			cin >> customID;
			cout << "Enter the Name" << endl;
			cin >> name;
			cout << "Enter the Age" << endl;
			cin >> age;
			cout << "Enter the Mobile number" << endl;
			cin >> mobileNo;
			cout << "Enter the Address" << endl;
			cin >> address;
			cout << "Enter the Gender" << endl;
			cin >> gender;
		}
		out << "\nCustomer id:" << customID << "\nName" << name << "\nAge:" << age << "\n Mobile no:" << mobileNo << "\nAddress:" << address <<  "\ngender:" << gender << endl;
		out.close();
		cout << "\n SAVED \n NOTE:we save your details record for future purpose \n" << endl;
	}
	void showDetails()
	{
		ifstream in("old-customer.txt");
		{
			if (!in)
			{
				cout << "file eeror" << endl;
			}
			while (!(in.eof()))
			{
				in.getline(all,999);
				cout << all;

			}
			in.close();
		}
	}
};
class Cabs
{
public:
	int cabChoice;
	int kilometer;
	float cabCoast;
	static float lastcabCoast;
	
	void cabDetails()
	{
		cout << "we collaborted with fastest,safest,and smartest cab service arounf the country " << endl;
		cout << "-------------------ABC Cabs---------------\n" << endl;
		cout << "1. Rent a Standard Cab -Rs .15 for 1km" << endl;
		cout << "2.Rent A Luxury Cab- Rs.25 per 1km" << endl;

		cout << "\n TO calculate the coast for your journey:"<<endl;
		cout << "Enter which kind of cab you need:" << endl;
		cin >> cabChoice;
		cout << "Enter kilometer you have to travel:" << endl;
		cin >> kilometer;
		int hireCab;
		if (cabChoice == 1)
		{
			cabCoast = kilometer * 15;
			cout << "\n your tour coast " << cabCoast << "rupees for a standard cab" << endl;
			cout << "press 1 to hire the cab:or" << endl;
			cout << "press 2 to select another cab" << endl;
			cin >> hireCab;
			system("CLS");
			if (hireCab == 1)
			{
				lastcabCoast = cabCoast;
				cout << "\n You have successfully hired a standard cab" << endl;
				cout << "Goto Menu and take the recipt"<<endl;
			}
			else if(hireCab==2)
			{
				cabDetails();
			}
			else
			{
				cout << "Invalid Input! Redirecting to previous menu \n Plaese wait" << endl;
				Sleep(999);
				system("CLS");
				cabDetails();
			}
		}
		else if (cabChoice == 2)
		{
			cabCoast = kilometer * 15;
			cout << "\n your tour coast " << cabCoast << "rupees for a standard cab" << endl;
			cout << "press 1 to hire the cab:or" << endl;
			cout << "press 2 to select another cab" << endl;
			cin >> hireCab;
			system("CLS");
			if (hireCab == 1)
			{
				lastcabCoast = cabCoast;
				cout << "\n You have successfully hired a standard cab" << endl;
				cout << "Goto Menu and take the recipt" << endl;
			}
			else if (hireCab == 2)
			{
				cabDetails();
			}
			else
			{
				cout << "Invalid Input! Redirecting to main menu \n Plaese wait" << endl;
				Sleep(999);
				system("CLS");
				menu();
			}

		}
		cout << "\n Press 1  to Redirect Main menu";
		cin >> hireCab;
		system("CLS");
		if (hireCab == 1)
		{
			menu();
		}
		else
		{
			menu();
		}
		


	}

};
float Cabs::lastcabCoast;
class Booking
{
public:
	
	int choiceHotels;
	int packChoice;
	static float hotelCoast;
	void hotels()
	{
		string hotelNo[] = { "raj","raghu","prast" };
		for (int i = 0; i < 3; i++)
		{
			cout << (i + 1) << ". Hotel" << hotelNo[i] << endl;
		}
		cout << "\n Currently we callaborated with above hotel" << endl;

		cout << "Press any key to back or \n Enter number of the hotel you want to book";
		cin >> choiceHotels;
		system("CLS");

		if (choiceHotels == 1)
		{
			cout << "----------WELCOME TO HOTEL MANJUANTH---\n" << endl;
			cout << "The Garden,food and beverage .Enjoy all you can drink,Stay cool and get chilled in the summer sun" << endl;
			cout << "1. Standard Pack" << endl;
			cout << "\tAll basic facilities you need just for :Rs 50000.00" << endl;
			cout << "2. Premium Pack" << endl;
			cout << "3 Luxury pack" << endl;
			cout << "\t Live a Luxuxry at Manjuanth :Rs.15000.00" << endl;
			cout << "\n press another key to back or \n Enter package number you want to book:";
			cin >> packChoice;

			if (packChoice == 1)
			{
				hotelCoast = 5000.00;
				cout << "\n yoy have successfully booked standard pack at Manjuath" << endl;
				cout << "GOTo Menu and take receipt" << endl;

			}

			else if (packChoice == 2)
			{
				hotelCoast = 10000.00;
				cout << "\n yoy have successfully booked premium pack at Manjuath" << endl;
				cout << "GOTo Menu and take receipt" << endl;

			}

			else if (packChoice == 3)
			{
				hotelCoast = 15000.00;
				cout << "\n yoy have successfully booked Luxury pack at Manjuath" << endl;
				cout << "GOTo Menu and take receipt" << endl;

			}
			else
			{
				cout << "Invalid Input! Redirecting to Previous Menu \n Please wait" << endl;
				Sleep(1100);
				system("CLS");
				hotels();
			}
			int gotomenu;
			cout << "\n Press 1 to redirect main menu";
			cin >> gotomenu;
			if (gotomenu == 1)
			{
				menu();
			}
			else
			{
				menu();
			}
		}
		else
		{
			cout << "Invalid Input! Redirecting to main menu \n Plaese wait" << endl;
			Sleep(999);
			system("CLS");
			menu();
		}





	}
};
float Booking::hotelCoast;
class Charges:public Booking,Cabs,Customers
{
public:
	void printBill()
	{
		ofstream out("recipt.txt");
		{
			out << "----------ABC Travel Agency-------------" << endl;
			out << "--------------Recipt----------------------" << endl;
			out << "--------------------------------------------" << endl;
			out << "Customer Id:" << Customers::customID << endl<<endl;
			out << "Description\t\t Total" << endl;
			out << "Hotelcost:\t\t" << fixed << setprecision(2) << Booking::hotelCoast << endl;
			out << "Travel (Cab) coast:\t" << fixed << setprecision(2) << Cabs::lastcabCoast << endl;

			out << "-------------------------------------------------" << endl;
			out << "Total Charge:\t\t" << fixed << setprecision(2) << Booking::hotelCoast + Cabs::lastcabCoast << endl;
			out << "-----------------------------------------------" << endl;
			out << "---------THANK YOU------------" << endl;


		}
		out.close();
	}
	void showBill()
	{
		ifstream in("recipt.txt");
		{
			if (!in)
			{
				cout << "File opening error" << endl;

			}
			while (!(in.eof()))
			{
				in.getline(all, 999);
				cout << all << endl;
			}

		}
		in.close();
	}

};
void menu()
{
	int mainChoice;
	int choice;
	int gotomenu;


	cout << "\t\t       *ABC Travels*  \n" << endl;
	cout << "-----------------Main Menu-----------------" << endl;

	cout << "\t-------------------------------------------" << endl;
	cout << "\t|\t\t\t\t\t|" << endl;
	cout << "\t|\tCustomer Mangament ->1\t|" << endl;
	cout << "\t|\tCabs Mangament     ->2\t|" << endl;
	cout << "\t|\tBooking Mangament  ->3\t|" << endl;
	cout << "\t|\tCharges Mangament  ->4\t|" << endl;
	cout << "\t|\tExit               ->5\t|" << endl;
	cout << "\t|\t\t\t\t\t|" << endl;
	cout << "\t|---------------------------------|<<endl";
	cout << "\nEnter your Choice:";
	cin >> mainChoice;
	system("CLS");
	Customers customer;
	Cabs cab;
	Booking book;
	Charges charge;
	if (mainChoice == 1)
	{
		cout << "-------Customers--------\n" << endl;
		cout << "1. Enter the new customers " << endl;
		cout << "2. See old customers " << endl;

		cout << "\n Enter your choice " << endl;
		cin >> choice;
		system("CLS");
		if (choice == 1)
		{
			customer.detDetails();
		}
		else if (choice == 2)
		{
			customer.showDetails();
		}
		else
		{
			cout << "Invalid Input! Redirecting to main menu \n Plaese wait" << endl;
			Sleep(999);
			system("CLS");
			menu();
		}


		cout << "\nPress 1 to Rediret main menu :";
		cin >> gotomenu;
		system("CLS");
		if (gotomenu == 1)
		{
			menu();
		}
		else
		{
			menu();
		}
	}

	else if (mainChoice == 2)
	{
		cab.cabDetails();
	}
	else if (mainChoice == 3)
	{
		cout << "--->Book a luxury  Hotel using the system <---" << endl;
		book.hotels();
	}
	else if (mainChoice == 4)
	{
		cout << "---->Get your recipt------<" << endl;
		charge.printBill();

		cout << "your recipt is already printed you can get it fm the file path\n" << endl;
		cout << "to display the your recipt on your screen press 1 or press any other key to go back to the main menu" << endl;
		cin >> gotomenu;
		if (gotomenu == 1)
		{
			system("CLS");
			charge.showBill();
			cout << "\n press 1 to go to he main menu" << endl;
			cin >> gotomenu;
			system("CLS");
			if (gotomenu == 1)
			{
				menu();
			}
			else
			{
				menu();
			}
		}
		else
		{
			system("CLS");
			menu();
		}
	}
	else if (mainChoice == 5)
	{
		cout << "----GOOD BYE----" << endl;
		Sleep(999);
		system("CLS");
	}
	else
	{
		cout << "Invalid Input! Redirecting to main menu \n Plaese wait" << endl;
		Sleep(999);
		system("CLS");
		menu();
	}
}
int main()
{
	
	menu();
	system("pause");
    return 0;
}

