#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
#include "Workout.h"
#include "Diet.h"
#include "Social.h"
#include "Challenges.h"
#include "Location Based Features.h"
#include "Progress Analysis.h"


class Menu
{
public:
	void menu(string un)
	{
		int option;
		cout << "\t\t\t\t\t\t    Welcome to Main Page\n";
		cout << "\t\t\t\t\t\t    Select from the following:\n";
		cout << "\t\t\t\t\t\t    1] WorkOuts\n";
		cout << "\t\t\t\t\t\t    2] Diet\n";
		cout << "\t\t\t\t\t\t    3] Open Social Feed\n";
		cout << "\t\t\t\t\t\t    4] Challenges and Competions\n";
		cout << "\t\t\t\t\t\t    5] Activities Available Near You\n";
		cout << "\t\t\t\t\t\t    6] Progress Analysis\n";

		while (true)
		{
			cin >> option;
			if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5 || option == 6)
			{
				break;
			}
			else
				cout << "Invalid input, Try Again\n";
		}
		if (option == 1)
		{
			system("CLS");
			Workout W;
			W.workoutmenu(un);
		}
		else if (option == 2)
		{
			system("CLS");
			Diet D;
			D.dietmenu(un);
		}
		else if (option == 3)
		{
			system("CLS");
			Social S;
			S.menu(un);
		}
		else if (option == 4)
		{
			system("CLS");
			Challenges C;
			C.menu(un);
		}
		else if (option == 5)
		{
			system("CLS");
			Location L;
			L.menu(un);
		}
		else if (option == 6)
		{
			system("CLS");
			Progress P;
			P.ProgressAnalysisMenu(un);
		}
		else
		{
			cout << "Invalid Input\n";
		}
	}
};

//-------------------------------------------------------------------------------------------------//




class TrainerMenu
{
public:

	void Menu(string un)
	{
		int option;
		cout << "\t\t\t\t\t\t    Welcome to Main Page\n";
		cout << "\t\t\t\t\t\t    Select from the following:\n";
		cout << "\t\t\t\t\t\t    1] Design WorkOuts Plans\n";
		cout << "\t\t\t\t\t\t    2] Design Diet Plans\n";
		cout << "\t\t\t\t\t\t    3] Open Social Feed\n";
		cout << "\t\t\t\t\t\t    4] Add Challenges and Competions\n";
		cout << "\t\t\t\t\t\t    5] Add Activities Available Near You\n";
		cout << "\t\t\t\t\t\t    6] Exit App\n";

		while (true)
		{
			cin >> option;
			if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5 || option == 6)
			{
				break;
			}
			else
				cout << "Invalid input, Try Again\n";
		}
		if (option == 1)
		{
			designWorkoutPlans();
		}
		else if (option == 2)
		{
			designDietPlans();
		}
		else if (option == 3)
		{
			Social S;
			S.menu(un);
		}
		else if (option == 4)
		{
			challengesAndCompetition();
		}
		else if (option == 5)
		{
			activitiesNearYou();
		}
		else if (option == 6)
		{
			exit(0);
		}
	}

	//----------------------------------------//


	void challengesAndCompetition()
	{
		fstream design;
		design.open("Challenges.txt", ios::binary | ios::app);
		if (design.is_open() == 0)
		{
			cout << "\t\t\t\t\t\t    Error Opening file\n";
		}
		int challenge;
		cout << " Enter no of challenges you want to add:" << endl;
		cin >> challenge;

		string c;
		string name;

		for (int i = 1; i <= challenge; i++)
		{
			cout << "Challenge " << i << " name :";
			cin.ignore();
			getline(cin, name);
			cout << "Challenge " << i << " Details " << ":";
			cin.ignore();
			getline(cin, c);
			design << name << " Challenge \n";
			design << "Details : " << c << endl;
			design << endl;
		}

		design.close();
	}

	//----------------------------------------//

	void activitiesNearYou()
	{
		string area;
		cout << "Enter your area\n";
		cin >> area;

		fstream activities;
		activities.open(area + "_Activities.txt", ios::binary | ios::app);
		if (activities.is_open() == 0)
		{
			cout << "Cannot Open File\n";
		}

		string active;
		cout << "Enter the events happening near you :" << endl;
		cin >> active;

		string location;
		cout << "Enter the location of event\n";
		cin >> location;

		activities << "Activities happening in : " << area;
		activities << endl;
		activities << active;
		activities << endl;
		activities << "Location : " << location;
		activities << endl;

		activities.close();

	}
	//----------------------------------------//
	void designWorkoutPlans()
	{
		fstream design;
		design.open("Workout_Plans.txt", ios::binary | ios::app);
		if (design.is_open() == 0)
		{
			cout << "\t\t\t\t\t\t    Error Opening file\n";
		}

		string workout;
		for (int i = 1; i <= 7; i++)
		{
			cout << "\t\t\t\t\t\t    Day " << i << " Workout: ";
			cin >> workout;

			design << "Day " << i << " Workout: " << workout;
			design << endl;
		}
		design.close();
	}

	//--------------------------------------//


	void designDietPlans()
	{
		ofstream newDiet("Diet_Plans.txt", ios::binary | ios::app);
		if (!newDiet.is_open())
		{
			cout << "\t\t\t\t\t\t    Error opening file for writing." << endl;
			return;
		}

		int mealNumber;
		cout << "\t\t\t\t\t\t    Enter number of meals in your day: ";
		cin >> mealNumber;

		string mealName;
		string mealCalories;

		for (int i = 1; i <= 7; i++)
		{
			for (int j = 1; j <= mealNumber; j++)
			{
				cout << "\t\t\t\t\t\t    Day " << i << endl;
				cout << "\t\t\t\t\t\t    Enter name of your meal " << j << ": ";
				cin >> mealName;
				cout << "\t\t\t\t\t\t    Enter Calories of Meal " << j << ": ";
				cin >> mealCalories;

				newDiet << "Meal " << i << ": " << mealName;
				newDiet << endl;
				newDiet << "Meal " << i << " Calories : " << mealCalories;
				newDiet << endl;
			}

		}

		newDiet.close();
	}



};

//-------------------------------------------------------------------------------------------------------------------------//

class AdminMenu
{
public:
	void menu(string un)
	{
		int option;
		cout << "\t\t\t\t\t\t    Welcome to Main Page\n";
		cout << "\t\t\t\t\t\t    Select from the following:\n";
		cout << "\t\t\t\t\t\t    1] Delete a User\n";
		cout << "\t\t\t\t\t\t    2] Delete a trainer\n";
		cout << "\t\t\t\t\t\t    3] Add Facilities in certain area\n";
		cout << "\t\t\t\t\t\t    4] Update Weather Condition in certain area\n";
		cout << "\t\t\t\t\t\t    5] Add Cycling Routes in certain area\n";
		cout << "\t\t\t\t\t\t    6] Add new Challenges\n";
		cout << "\t\t\t\t\t\t    7] Exit App\n";

		while (true)
		{
			cin >> option;
			if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5 || option == 6 || option == 7)
			{
				break;
			}
			else
				cout << "Invalid input, Try Again\n";
		}
		if (option == 1)
		{
			deleteuser(un);
		}
		else if (option == 2)
		{
			deletetrainer(un);
		}
		else if (option == 3)
		{
			updateFacilities();
		}
		else if (option == 4)
		{
			updateWeatherCondition();
		}
		else if (option == 5)
		{
			updateCyclingRoutes();
		}
		else if (option == 6)
		{
			addNewChallenges();
		}
		else if (option == 7)
		{
			exit(0);
		}
		else
		{
			cout << "Invalid Input\n";
		}
	}

	//---------------------------------------------------------------------//
	void deleteuser(string un)
	{
		fstream user;
		user.open("user_username.txt", ios::binary | ios::in);
		if (!user.is_open())
		{
			cout << "Cannot open file\n";
			return; // Exiting function if file cannot be opened
		}

		string s;
		cout << "List of users\n";
		while (getline(user, s, '\n'))
		{
			cout << s << endl;
		}

		string filename = "user_username.txt";
		string nameToRemove;
		cout << "Enter the name to remove\n"; // Name you want to remove
		cin >> nameToRemove;

		ifstream inFile(filename);
		if (!inFile) {
			cout << "Error: Unable to open input file." << endl;
			return; // Exiting function if file cannot be opened
		}

		ofstream outFile("temps.txt"); // Temporary file to store filtered names
		if (!outFile) {
			cout << "Error: Unable to create temporary file." << endl;
			inFile.close();
			return; // Exiting function if temporary file cannot be created
		}

		string name;

		// Read names from the file and write non-matching names to temporary file
		while (inFile >> name) {
			if (name != nameToRemove) {
				outFile << name << endl;
			}
		}

		inFile.close();
		outFile.close();

		// Rename temporary file to original filename
		if (remove(filename.c_str()) != 0) {
			cout << "Error: Unable to remove original file." << endl;
			return; // Exiting function if unable to remove original file
		}
		if (rename("temps.txt", filename.c_str()) != 0) { // corrected the name here
			cout << "Error: Unable to rename temporary file." << endl;
			return; // Exiting function if unable to rename temporary file
		}

		cout << "Name '" << nameToRemove << "' removed from the file." << endl;

		return;
	}


	//---------------------------------------------------------------------//



	void deletetrainer(string un)
	{
		fstream user;
		user.open("trainer_username.txt", ios::binary | ios::in);
		if (user.is_open() == 0)
		{
			cout << "Cannot open file\n";
		}
		string s;
		cout << "List of users\n";
		while (getline(user, s, '\n'))
		{
			cout << s << endl;
		}

		string filename = "trainer_name.txt";
		string nameToRemove; // Name you want to remove
		cout << "Enter the name of trainer you want to remove\n";
		cin >> nameToRemove;

		ifstream inFile(filename);
		if (!inFile) {
			cout << "Error: Unable to open input file." << endl;
		}

		ofstream outFile("temps.txt"); // Temporary file to store filtered names
		if (!outFile) {
			cout << "Error: Unable to create temporary file." << endl;
			inFile.close();
		}

		string name;

		// Read names from the file and write non-matching names to temporary file
		while (inFile >> name) {
			if (name != nameToRemove) {
				outFile << name << endl;
			}
		}

		inFile.close();
		outFile.close();

		// Rename temporary file to original filename
		if (remove(filename.c_str()) != 0) {
			cout << "Error: Unable to remove original file." << endl;
		}
		if (rename("temp.txt", filename.c_str()) != 0) {
			cout << "Error: Unable to rename temporary file." << endl;
		}

		cout << "Name '" << nameToRemove << "' removed from the file." << endl;
	}


	//---------------------------------------------------------------------//
	void updateFacilities()
	{
		string area;
		cout << "Enter the area where you want to add Facilities\n";
		cin >> area;

		fstream facilities;
		facilities.open(area + "_Facilities.txt", ios::binary | ios::app);
		if (facilities.is_open() == 0)
		{
			cout << "Error opening file\n";
		}

		string name;
		string location;

		cout << "Enter name of the facility\n";
		cin >> name;
		cout << "ENter the location of the facility\n";
		cin >> location;

		facilities << "Name : " << name;
		facilities << endl;
		facilities << "Location : " << location;
		facilities << endl;

		facilities.close();
	}

	//---------------------------------------------------------------------//


	void updateWeatherCondition()
	{
		string area;
		cout << "Enter the area where you want to update weather\n";
		cin >> area;

		fstream Weather;
		Weather.open(area + "_Weather_Condition.txt", ios::binary | ios::out);
		if (Weather.is_open() == 0)
		{
			cout << "Error opening file\n";
		}

		string condition;

		cout << "Enter condition of the area\n";
		cin >> condition;


		Weather << "Condition in " << area << " is " << condition;
		Weather << endl;

		Weather.close();
	}

	//---------------------------------------------------------------------//

	void updateCyclingRoutes()
	{
		string area;
		cout << "Enter the area for Cycling Routes\n";
		cin >> area;

		fstream routes;
		routes.open(area + "_Cycling_Routes.txt", ios::binary | ios::app);
		if (routes.is_open() == 0)
		{
			cout << "Error opening file\n";
		}

		string condition;

		int n;
		cout << "Enter no of routes you want to add\n";
		cin >> n;
		string km;
		for (int i = 1; i <= n; i++)
		{
			cout << "Enter cycling route number " << i << " of this area\n";
			cin.ignore();
			getline(cin, condition);
			cout << "Enter Distance in KiloMeters(km) \n";
			cin >> km;
			routes << "Cycling Routes no " << i << " in " << area << " is :";
			routes << endl;
			routes << condition;
			routes << endl;
			routes << "Total Distance: " << km;
			routes << endl;
		}

		routes.close();

	}


	//---------------------------------------------------------------------//

	void addNewChallenges()
	{
		fstream design;
		design.open("Challenges.txt", ios::binary | ios::app);
		if (design.is_open() == 0)
		{
			cout << "\t\t\t\t\t\t    Error Opening file\n";
		}
		int challenge;
		cout << " Enter no of challenges you want to add:" << endl;
		cin >> challenge;

		string c;
		string name;

		for (int i = 1; i <= challenge; i++)
		{
			cout << "Challenge " << i << " name :";
			cin.ignore();
			getline(cin, name);
			cout << "Challenge " << i << " Details " << ":";
			cin.ignore();
			getline(cin, c);
			design << name << " Challenge \n";
			design << "Details : " << c << endl;
			design << endl;
		}

		design.close();
	}

	//---------------------------------------------------------------------//
};

