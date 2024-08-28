#pragma once
#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "1.h"

//#include "Main Menu.h"
using namespace std;

class Workout
{

public:

	void workoutmenu(string un)
	{
		cout << "\n\t\t\t\t\t\t    Workout Tracking Menu:\n";
		cout << "\t\t\t\t\t\t    1] Log a Workout\n";
		cout << "\t\t\t\t\t\t    2] View Workout History\n";
		cout << "\t\t\t\t\t\t    3] Set Workout Goals\n";
		cout << "\t\t\t\t\t\t    4] View Workout Goals\n";
		cout << "\t\t\t\t\t\t    5] View Workout Plans Made by Trainers\n";
		cout << "\t\t\t\t\t\t    6] Back to Main Menu" << endl;
		selection(un);
		return;
	}

	void selection(string un)
	{
		int n;
		while (true)
		{
			cin >> n;
			if (n == 1 || n == 2 || n == 3 || n == 4 || n == 5 || n == 6)
				break;
			else
				cout << "\t\t\t\t\t\t    Invalid Input, Try again\n";
		}
		if (n == 1)
		{
			logWorkout(un);
		}
		if (n == 2)
		{
			viewWorkoutHistory(un);
		}
		if (n == 3)
		{
			setWorkoutGoals(un);
		}
		if (n == 4)
		{
			viewWorkoutGoals(un);
		}
		if (n == 5)
		{
			designWorkoutPlans();
		}
	}

	//---------------------------------------------------------------------------------------------------//



	void designWorkoutPlans()
	{
		fstream design;
		design.open("Workout_Plans.txt", ios::binary | ios::in);
		if (design.is_open() == 0)
		{
			cout << "\t\t\t\t\t\t    Error Opening file\n";
		}

		string workout;
		while (getline(design, workout, '\n'))
		{
			cout << "\t\t\t\t\t\t     " << workout << endl;
		}
		design.close();
	}


	//---------------------------------------------------------------------------------------------------//

	void logWorkout(string un)
	{
		ofstream outputFile(un + "_workout_history.txt", ios::binary | ios::app);
		if (!outputFile.is_open()) {
			cout << "\t\t\t\t\t\t    Error opening file for writing." << endl;
			return;
		}

		string workoutDetails;
		cout << "\t\t\t\t\t\t    Enter details of the workout: ";
		cin.ignore();
		getline(cin, workoutDetails);

		outputFile << workoutDetails << endl;
		cout << "\t\t\t\t\t\t    Workout logged successfully." << endl;

		outputFile.close();
	}


	//-------------------------------------------------------------------------------------------------------------------------//



	void viewWorkoutHistory(string un)
	{
		fstream inputFile(un + "_workout_history.txt", ios::in);
		if (!inputFile.is_open())
		{
			cout << "\t\t\t\t\t\t    Error opening file for reading." << endl;
		}

		string line;
		cout << "\t\t\t\t\t\t    Workout History:\n";

		while (getline(inputFile, line, '\n'))
		{
			cout << "\t\t\t\t\t\t    " << line << endl;
		}

		inputFile.close();
	}


	//----------------------------------------------------------------------------------------------------------//

	void setWorkoutGoals(string un)
	{

		ofstream intputFile(un + "_workout_goals.txt", ios::binary | ios::app);
		if (!intputFile.is_open())
		{
			cout << "\t\t\t\t\t\t    Error opening file for writing." << endl;
			return;
		}

		string goals;
		cout << "\t\t\t\t\t\t    Enter your workout goals: ";
		cin.ignore();
		getline(cin, goals);

		intputFile << goals << endl;
		cout << "\t\t\t\t\t\t    Workout goals set successfully." << endl;

		intputFile.close();
	}


	//-------------------------------------------------------------------------------------------------------------//


	void viewWorkoutGoals(string un)
	{
		fstream inputFile(un + "_workout_goals.txt", ios::binary | ios::in);

		if (!inputFile.is_open())
		{
			cout << "\t\t\t\t\t\t    Error opening file for reading." << endl;
		}

		string goals;
		cout << "\t\t\t\t\t\t    Your previous workout goals:\n";

		while (getline(inputFile, goals, '\n'))
		{
			cout << "\t\t\t\t\t\t    " << goals << endl;
		}

		inputFile.close();
	}


};



