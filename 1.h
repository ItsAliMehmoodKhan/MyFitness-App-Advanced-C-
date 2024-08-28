#pragma once
#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include "Main Menu.h"

class user
{
public:
	string name;
	string code;

	string un;
	string pass;

	fstream user_username;
	fstream user_password;
public:

	void signup()
	{
		user_username.open("user_username.txt", ios::binary | ios::app);
		user_password.open("user_password.txt", ios::binary | ios::app);
		if (user_username.is_open() == 0)
		{
			cout << "Cannot open file" << endl;
		}

		cout << "\t\t\t\t\t\t    Enter your username\n";
		cin >> un;
		cout << "\t\t\t\t\t\t    Enter your password\n";
		cin >> pass;

		user_username << un;
		user_username << endl;
		user_password << pass;
		user_password << endl;

		user_username.close();
		user_password.close();

		int option2;
		cout << "\t\t\t\t\t\t    1] Login " << endl;
		cout << "\t\t\t\t\t\t    2] Exit " << endl;

		while (true)
		{
			cin >> option2;

			if (option2 == 1)
				break;
			else if (option2 == 2)
				exit(0);
			else
				cout << "\t\t\t\t\t\t    Invalid Input, Try Again\n";
		}
		if (option2 == 1)
			login();
	}

	void login()
	{
		user_username.open("user_username.txt", ios::binary | ios::in);
		user_password.open("user_password.txt", ios::binary | ios::in);

		cout << "\t\t\t\t\t\t    Enter your username\n";
		cin >> name;
		cout << "\t\t\t\t\t\t    Enter your password\n";
		cin >> code;
		string read_username;
		string read_password;

		bool login_successful = false;

		while (getline(user_username, read_username) && getline(user_password, read_password))
		{
			if (un == read_username && pass == read_password)
			{
				login_successful = true;
				cout << "\t\t\t\t\t\t    Login Successful" << endl;
				break;
			}
		}
		user_username.close();
		user_password.close();

		system("CLS");
		Menu M;
		M.menu(name);
	}
};


//--------------------------------------------------------------------------------------------------------------------//

class Trainer : public user {
protected:
	string name;
	string expertise;


public:
	fstream trainer_username;
	fstream trainer_password;

	void signup()
	{
		trainer_username.open("trainer_username.txt", ios::binary | ios::app);
		trainer_password.open("trainer_password.txt", ios::binary | ios::app);


		if (!trainer_username.is_open() || !trainer_password.is_open())
		{
			cout << "Error opening files!" << endl;
		}

		cout << "Enter your username: ";
		cin >> un;
		cout << "Enter your password: ";
		cin >> pass;

		trainer_username << un << endl;
		trainer_password << pass << endl;

		trainer_username.close();
		trainer_password.close();

		int option2;
		cout << "\t\t\t\t\t\t    1] Login " << endl;
		cout << "\t\t\t\t\t\t    2] Exit " << endl;

		while (true)
		{
			cin >> option2;

			if (option2 == 1)
				break;
			else if (option2 == 2)
				exit(0);
			else
				cout << "\t\t\t\t\t\t    Invalid Input, Try Again\n";
		}
		if (option2 == 1)
		{
			login();
		}
	}

	void login()
	{
		trainer_username.open("trainer_username.txt", ios::binary | ios::in);
		trainer_password.open("trainer_password.txt", ios::binary | ios::in);

		if (!trainer_username.is_open() || !trainer_password.is_open())
		{
			cout << "Error opening files!" << endl;
			return;
		}

		cout << "Enter your username: ";
		cin >> name;
		cout << "Enter your password: ";
		cin >> code;

		string read_username, read_password;
		bool login_successful = false;

		while (getline(trainer_username, read_username) && getline(trainer_password, read_password))
		{
			if (name == read_username && code == read_password)
			{
				login_successful = true;
				cout << "Login successful!" << endl;
				break;
			}
		}
		system("CLS");

		if (!login_successful) {
			cout << "Invalid credentials." << endl;
		}

		trainer_username.close();
		trainer_password.close();

		system("CLS");
		TrainerMenu M;
		M.Menu(name);
	}
};


//---------------------------------------------------------------------------------------------------------//

class Admin : public user
{
protected:
	string name;
	string expertise;


public:
	fstream Admin_username;
	fstream Admin_password;

	void signup()
	{
		Admin_username.open("Admin_username.txt", ios::binary | ios::app);
		Admin_password.open("Admin_password.txt", ios::binary | ios::app);

		if (!Admin_username.is_open() || !Admin_password.is_open())
		{
			cout << "Error opening files!" << endl;
			return;
		}

		cout << "Enter your username: ";
		cin >> un;
		cout << "Enter your password: ";
		cin >> pass;

		Admin_username << un << endl;
		Admin_password << pass << endl;

		Admin_username.close();
		Admin_password.close();

		int option2;
		cout << "\t\t\t\t\t\t    1] Login " << endl;
		cout << "\t\t\t\t\t\t    2] Exit " << endl;

		while (true)
		{
			cin >> option2;

			if (option2 == 1)
				break;
			else if (option2 == 2)
				exit(0);
			else
				cout << "\t\t\t\t\t\t    Invalid Input, Try Again\n";
		}
		if (option2 == 1)
		{
			login();
		}
	}

	void login()
	{
		Admin_username.open("Admin_username.txt", ios::binary | ios::in);
		Admin_password.open("Admin_password.txt", ios::binary | ios::in);

		if (!Admin_username.is_open() || !Admin_password.is_open())
		{
			cout << "Error opening files!" << endl;
			return;
		}

		cout << "Enter your username: ";
		cin >> name;
		cout << "Enter your password: ";
		cin >> code;

		string read_username, read_password;
		bool login_successful = false;

		while (getline(Admin_username, read_username) && getline(Admin_password, read_password))
		{
			if (name == read_username && code == read_password)
			{
				login_successful = true;
				cout << "Login successful!" << endl;
				break;
			}
		}
		system("CLS");

		if (!login_successful)
		{
			cout << "Invalid credentials." << endl;
		}

		Admin_username.close();
		Admin_password.close();

		system("CLS");
		AdminMenu M;
		M.menu(name);
	}
};
