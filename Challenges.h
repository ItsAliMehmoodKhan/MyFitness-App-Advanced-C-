#pragma once
#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "1.h"

using namespace std;
class Challenges
{
public:
	void menu(string un)
	{
		cout << "\n\t\t\t\t\t\t    Challenges and Competitions Menu:\n\n";
		cout << "\t\t\t\t\t\t    1] View Current Challenges\n";
		cout << "\t\t\t\t\t\t    2] Join a Challenge\n";
		cout << "\t\t\t\t\t\t    3] View your selected Challenges\n";

		selection(un);
	}
	void selection(string un)
	{
		int n;
		while (true)
		{
			cin >> n;
			if (n == 1 || n == 2 || n == 3)
			{
				break;
			}
			else
				cout << "\t\t\t\t\t\t    Invalid Input, Try again\n";
		}

		if (n == 1)
		{
			viewCurrentChallenges();
		}
		if (n == 2)
		{
			joinChallenge(un);
		}

		if (n == 3)
		{
			viewMyChallenge(un);
		}
	}

	void viewCurrentChallenges()
	{
		fstream design;
		design.open("Challenges.txt", ios::binary | ios::in);
		if (design.is_open() == 0)
		{
			cout << "\t\t\t\t\t\t    Error Opening file\n";
		}

		string c;

		while (getline(design, c, '\n'))
		{
			cout << "\t\t\t\t\t\t    " << c;
			cout << endl;
		}


		design.close();
	}
	void joinChallenge(string un)
	{
		fstream join;
		join.open(un + "'s_Challenges", ios::binary | ios::app);
		if (join.is_open() == 0)
		{
			cout << "No current challenges selected\n" << endl;
		}
		string c;
		cout << "Enter Challenge Name: " << endl;
		cin >> c;

		string f;
		cout << "Enter Challenge details: " << endl;
		cin.ignore();
		getline(cin, f);

		join << "Challenge Name : " << c;
		join << endl;
		join << "Details : " << f;
		join << endl;

		join.close();

	}

	void viewMyChallenge(string un)
	{
		fstream join;
		join.open(un + "'s_Challenges", ios::binary | ios::in);
		if (join.is_open() == 0)
		{
			cout << "\t\t\t\t\t\t    No current challenges selected\n" << endl;
		}
		string c;

		while (getline(join, c, '\n'))
		{
			cout << "\t\t\t\t\t\t    " << c << endl;
		}
		join.close();

	}
};
