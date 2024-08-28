#include <iostream>
#include <string>
#include <iomanip>
#include<fstream>

#include "1.h"

using namespace std;


int main()
{
	cout << "\n\n\n\t\t\t\t\t\tWelcome to MyFitnessApp \n\n" << endl;

	cout << "\t\t\t\t\t\t    Startup Menu " << endl;

	cout << "\t\t\t\t\t\t    Select: " << endl;

	int option0;

	cout << "\t\t\t\t\t\t    1] User " << endl;
	cout << "\t\t\t\t\t\t    2] Trainer " << endl;
	cout << "\t\t\t\t\t\t    3] Admin " << endl;

	while (true)
	{
		cin >> option0;

		if (option0 == 1 || option0 == 2 || option0 == 3)
			break;
		else
			cout << "\t\t\t\t\t\t    Invalid Input, Try Again\n";
	}
	system("CLS");

	if (option0 == 1)
	{
		cout << "\n\n\n\t\t\t\t\t\tUser's Login Page \n\n" << endl;

		int option1;

		cout << "\t\t\t\t\t\t    1] Login " << endl;
		cout << "\t\t\t\t\t\t    2] Sign Up " << endl;
		cout << "\t\t\t\t\t\t    3] Exit " << endl;

		while (true)
		{
			cin >> option1;

			if (option1 == 1 || option1 == 2)
				break;
			else if (option1 == 3)
				exit(0);
			else
				cout << "\t\t\t\t\t\t    Invalid Input, Try Again\n";
		}

		if (option1 == 1)
		{
			user logi;
			logi.login();
		}
		else if (option1 == 2)
		{
			user sign;
			sign.signup();
		}

	}
	else if (option0 == 2)
	{
		cout << "\n\n\n\t\t\t\t\t\tTrainer's Login Page \n\n" << endl;

		int option1;

		cout << "\t\t\t\t\t\t    1] Login " << endl;
		cout << "\t\t\t\t\t\t    2] Sign Up " << endl;
		cout << "\t\t\t\t\t\t    3] Exit " << endl;

		while (true)
		{
			cin >> option1;

			if (option1 == 1 || option1 == 2)
				break;
			else if (option1 == 3)
				exit(0);
			else
				cout << "\t\t\t\t\t\t    Invalid Input, Try Again\n";
		}

		if (option1 == 1)
		{
			Trainer logi;
			logi.login();
		}
		else if (option1 == 2)
		{
			Trainer sign;
			sign.signup();
		}


	}
	else
	{
		cout << "\n\n\n\t\t\t\t\t\tAdmin's Login Page \n\n" << endl;

		int option1;

		cout << "\t\t\t\t\t\t    1] Login " << endl;
		cout << "\t\t\t\t\t\t    2] Sign Up " << endl;
		cout << "\t\t\t\t\t\t    3] Exit " << endl;

		while (true)
		{
			cin >> option1;

			if (option1 == 1 || option1 == 2)
				break;
			else if (option1 == 3)
				exit(0);
			else
				cout << "\t\t\t\t\t\t    Invalid Input, Try Again\n";
		}

		if (option1 == 1)
		{
			Admin logi;
			logi.login();
		}
		else if (option1 == 2)
		{
			Admin sign;
			sign.signup();
		}

	}

}
