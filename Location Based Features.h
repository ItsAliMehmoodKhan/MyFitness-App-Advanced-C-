#pragma once
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "1.h"
using namespace std;

class Location
{
public:
	void menu(string un)
	{
		cout << "\n\t\t\t\t\t\t   (Activities Near You) Menu\n\n";
		cout << "\t\t\t\t\t\t    1] View Activities near you\n";
		cout << "\t\t\t\t\t\t    2] Check Cycling and tracking routes in your area\n";
		cout << "\t\t\t\t\t\t    3] Check Fitness Facilities near you\n";
		cout << "\t\t\t\t\t\t    4] Check Weather\n";

		selection(un);
	}
	void selection(string un)
	{
		int n;
		while (true)
		{
			cin >> n;
			if (n == 1 || n == 2 || n == 3 || n == 4)
			{
				break;
			}
			else
				cout << "\t\t\t\t\t\t    Invalid Input, Try again\n";
		}

		if (n == 1)
		{
			activitiesNearYou();
		}
		if (n == 2)
		{
			updateCyclingRoutes();
		}

		if (n == 3)
		{
			FitnessFacilities();
		}
		if (n == 4)
		{
			checkWeather();
		}
	}
	void activitiesNearYou()
	{
		string area;
		cout << "\t\t\t\t\t\t    Enter your area: ";
		cin >> area;

		fstream activities;
		activities.open(area + "_Activities.txt", ios::binary | ios::in);
		if (activities.is_open() == 0)
		{
			cout << "\t\t\t\t\t\t    Cannot Open File\n";
		}

		string active;
		while (getline(activities, active, '\n'))
		{
			cout << "\t\t\t\t\t\t    " << active << endl;
		}

		activities.close();

	}

	void updateCyclingRoutes()
	{
		string area;
		cout << "\t\t\t\t\t\t    Enter your area : ";
		cin >> area;

		fstream routes;
		routes.open(area + "_Cycling_Routes.txt", ios::binary, ios::in);
		if (routes.is_open() == 0)
		{
			cout << "\t\t\t\t\t\t    Error opening file\n";
		}
		string active;
		while (getline(routes, active, '\n'))
		{
			cout << "\t\t\t\t\t\t    " << active << endl;
		}
		routes.close();

	}


	void FitnessFacilities()
	{
		string area;
		cout << "\t\t\t\t\t\t    Enter your area : ";
		cin >> area;

		fstream facilities;
		facilities.open(area + "_Facilities.txt", ios::binary, ios::in);
		if (facilities.is_open() == 0)
		{
			cout << "\t\t\t\t\t\t    Error opening file\n";
		}
		string active;
		while (getline(facilities, active, '\n'))
		{
			cout << "\t\t\t\t\t\t    " << active << endl;
		}
		facilities.close();

	}


	void checkWeather()
	{
		string area;
		cout << "\t\t\t\t\t\t    Enter the area where you want to check Weather: ";
		cin >> area;

		fstream Weather;
		Weather.open(area + "_Weather_Condition.txt", ios::binary, ios::in);
		if (Weather.is_open() == 0)
		{
			cout << "\t\t\t\t\t\t    Error opening file\n";
		}
		string active;
		while (getline(Weather, active, '\n'))
		{
			cout << "\t\t\t\t\t\t     " << active << endl;
		}
		Weather.close();

	}
};
