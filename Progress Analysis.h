#pragma once
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "1.h"

using namespace std;
class Progress {
public:
    struct WorkoutSession {
        string date;
        double duration; // in minutes
        double caloriesBurned;
    };

    struct WeightEntry {
        string date;
        double weight;
    };

    void ProgressAnalysisMenu(string un) {
        cout << "\n\t\t\t\t\t\t    Progress Analysis Menu:\n";
        cout << "\t\t\t\t\t\t    1] View Progress Charts\n";
        cout << "\t\t\t\t\t\t    2] Analyze Workout Performance\n";
        cout << "\t\t\t\t\t\t    3] Track Weight Fluctuations\n";
        cout << "\t\t\t\t\t\t    4] View Calorie Expenditure\n";
        cout << "\t\t\t\t\t\t    5] View Progress History\n";
        cout << "\t\t\t\t\t\t    6] View Workout Performance History\n";
        cout << "\t\t\t\t\t\t    7] View Weight Fluctuation History\n";
        cout << "\t\t\t\t\t\t    8] View Calorie Expenditure History\n";
        selection(un);
    }

    void selection(string un) {
        int n;
        while (true) {
            cin >> n;
            if (n == 1 || n == 2 || n == 3 || n == 4 || n == 5 || n == 6 || n == 7 || n == 8)
            {
                break;
            }
            else
                cout << "Invalid Input, Try again\n";
        }
        if (n == 1) {
            WorkoutSession workouts[3];
            WeightEntry weights[3];
            inputData(workouts, 3);
            inputData(weights, 3);
            viewProgressCharts(workouts, 3, weights, 3, un);
        }
        else if (n == 2) {
            WorkoutSession workouts[3];
            inputData(workouts, 3);
            analyzeWorkoutPerformance(workouts, 3, un);
        }
        else if (n == 3) {
            WeightEntry weights[3];
            inputData(weights, 3);
            trackWeightFluctuations(weights, 3, un);
        }
        else if (n == 4) {
            WorkoutSession workouts[3];
            inputData(workouts, 3);
            viewCalorieExpenditure(workouts, 3, un);
        }
        else if (n == 5)
        {
            ViewProgressHistory(un);
        }
        else if (n == 6)
        {
            ViewWorkoutPerformanceHistory(un);
        }
        else if (n == 7)
        {
            ViewWeightFluctuationHistory(un);
        }
        else if (n == 8)
        {
            ViewCalorieExpenditureHistory(un);
        }
    }

    //----------------------------------------------------------------------//


    // Function to prompt user for data input for WorkoutSession
    void inputData(WorkoutSession workouts[], int numWorkouts) {
        for (int i = 0; i < numWorkouts; ++i) {
            cout << "Enter workout session details for session " << i + 1 << ":\n";
            cout << "Date: ";
            cin >> workouts[i].date;
            cout << "Duration (minutes): ";
            cin >> workouts[i].duration;
            cout << "Calories Burned: ";
            cin >> workouts[i].caloriesBurned;
        }
    }

    // Function to prompt user for data input for WeightEntry
    void inputData(WeightEntry weights[], int numWeights) {
        for (int i = 0; i < numWeights; ++i) {
            cout << "Enter weight entry details for entry " << i + 1 << ":\n";
            cout << "Date: ";
            cin >> weights[i].date;
            cout << "Weight (kg): ";
            cin >> weights[i].weight;
        }
    }


    //--------------------------------------------------------------------------------------// 





    // Function to display progress charts
    void viewProgressCharts(const WorkoutSession workouts[], int numWorkouts, const WeightEntry weights[], int numWeights, string un)
    {

        fstream Charts;
        Charts.open(un + "'s_Progress Charts.txt", ios::binary | ios::app);
        if (Charts.is_open() == 0)
        {
            cout << "Error Opening File\n";
        }

        cout << "Progress Charts" << endl;

        // Display workout progress
        cout << "Workout Progress:" << endl;
        cout << "Date\t\tDuration(min)\tCalories Burned" << endl;

        for (int i = 0; i < numWorkouts; ++i) {
            cout << workouts[i].date << "\t" << workouts[i].duration << "\t\t" << workouts[i].caloriesBurned << endl;
        }
        Charts << "Date\tDuration(min)\tCalories Burned" << endl;
        for (int i = 0; i < numWorkouts; ++i) {
            Charts << workouts[i].date << "\t" << workouts[i].duration << "\t\t" << workouts[i].caloriesBurned << endl;
        }

        // Display weight progress
        cout << "\nWeight Progress:" << endl;
        cout << "Date\tWeight(kg)" << endl;
        Charts << "Date\tWeight(kg)" << endl;
        for (int i = 0; i < numWeights; ++i) {
            cout << weights[i].date << "\t" << weights[i].weight << endl;
            Charts << weights[i].date << "\t" << weights[i].weight << endl;
        }
    }

    void ViewProgressHistory(string un)
    {
        fstream Charts;
        Charts.open(un + "'s_Progress Charts.txt", ios::binary | ios::in);
        if (Charts.is_open() == 0)
        {
            cout << "Error Opening File\n";
        }
        string s;
        while (getline(Charts, s, '\n'))
        {
            cout << s << endl;
        }
        Charts.close();
    }


    //-------------------------------------------------------------------------------------------------//


    // Function to analyze workout performance
    void analyzeWorkoutPerformance(const WorkoutSession workouts[], int numWorkouts, string un)
    {
        fstream Charts;
        Charts.open(un + "'s_Workout Performance Charts.txt", ios::binary | ios::app);
        if (Charts.is_open() == 0)
        {
            cout << "Error Opening File\n";
        }
        cout << "Workout Performance Analysis" << endl;

        // Calculate total duration and calories burned
        double totalDuration = 0;
        double totalCalories = 0;
        for (int i = 0; i < numWorkouts; ++i) {
            totalDuration += workouts[i].duration;
            totalCalories += workouts[i].caloriesBurned;
        }
        cout << "Total Workout Duration: " << totalDuration << " minutes" << endl;
        cout << "Total Calories Burned: " << totalCalories << " calories" << endl;

        Charts << "Total Workout Duration: " << totalDuration << " minutes" << endl;
        Charts << "Total Calories Burned: " << totalCalories << " calories" << endl;

        Charts.close();
    }



    void ViewWorkoutPerformanceHistory(string un)
    {
        fstream Charts;
        Charts.open(un + "'s_Workout Performance Charts.txt", ios::binary | ios::in);
        if (Charts.is_open() == 0)
        {
            cout << "Error Opening File\n";
        }
        string s;
        while (getline(Charts, s, '\n'))
        {
            cout << s << endl;
        }
        Charts.close();
    }
    //--------------------------------------------------------------------------------------------------// 


    // Function to track weight fluctuations
    void trackWeightFluctuations(const WeightEntry weights[], int numWeights, string un)
    {
        fstream Weight;
        Weight.open(un + "'s_Weight Tracking.txt", ios::binary | ios::app);
        if (Weight.is_open() == 0)
        {
            cout << "Cannot open file\n";
        }
        cout << "Weight Fluctuation Tracking" << endl;

        // Display weight fluctuations
        cout << "Date\t\tWeight(kg)" << endl;
        Weight << "Date\tWeight(kg)" << endl;
        for (int i = 0; i < numWeights; ++i)
        {
            cout << weights[i].date << "\t" << weights[i].weight << endl;
            Weight << weights[i].date << "\t" << weights[i].weight << endl;
        }
    }

    void ViewWeightFluctuationHistory(string un)
    {
        fstream Weight;
        Weight.open(un + "'s_Weight Tracking.txt", ios::binary | ios::in);
        if (Weight.is_open() == 0)
        {
            cout << "Cannot open file\n";
        }

        string s;
        while (getline(Weight, s, '\n'))
        {
            cout << s << endl;
        }
        Weight.close();
    }





    //--------------------------------------------------------------------------------------------------//
    // Function to view calorie expenditure
    void viewCalorieExpenditure(const WorkoutSession workouts[], int numWorkouts, string un)
    {
        fstream Weight;
        Weight.open(un + "'s_Calorie Expenditure.txt", ios::binary | ios::app);
        if (Weight.is_open() == 0)
        {
            cout << "Cannot open file\n";
        }
        cout << "Viewing Calorie Expenditure" << endl;

        // Calculate total calorie expenditure
        double totalCalories = 0;
        for (int i = 0; i < numWorkouts; ++i) {
            totalCalories += workouts[i].caloriesBurned;
        }
        cout << "Total Calorie Expenditure: " << totalCalories << " calories" << endl;
        Weight << "Total Calorie Expenditure: " << totalCalories << " calories" << endl;

        Weight.close();
    }



    void ViewCalorieExpenditureHistory(string un)
    {
        fstream Weight;
        Weight.open(un + "'s_Calorie Expenditure.txt", ios::binary | ios::in);
        if (Weight.is_open() == 0)
        {
            cout << "Cannot open file\n";
        }

        string s;
        while (getline(Weight, s, '\n'))
        {
            cout << s << endl;
        }
        Weight.close();
    }





};

