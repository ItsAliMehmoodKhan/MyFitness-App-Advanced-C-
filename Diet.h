#pragma once
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "1.h"

using namespace std;
class Diet
{
public:
    void dietmenu(string un)
    {
        cout << "\n\t\t\t\t\t\t    Nutrition Tracking Menu:\n";
        cout << "\t\t\t\t\t\t    1] Log a Meal\n";
        cout << "\t\t\t\t\t\t    2] View Meal History\n";
        cout << "\t\t\t\t\t\t    3] Get Diet Recommendations\n";
        cout << "\t\t\t\t\t\t    4] View Diet Plans" << endl;
        cout << "\t\t\t\t\t\t    5] Add New Diet Plan" << endl;
        cout << "\t\t\t\t\t\t    6] View Your Diet Plan" << endl;
        cout << "\t\t\t\t\t\t    7] View Diet Plans made by professional Trainers" << endl;
        selection(un);
    }
    void selection(string un)
    {
        int n;
        while (true)
        {
            cin >> n;
            if (n == 1 || n == 2 || n == 3 || n == 4 || n == 5 || n == 6 || n == 7)
            {
                break;
            }
            else
                cout << "\t\t\t\t\t\t    Invalid Input, Try again\n";
        }

        if (n == 1)
        {
            logMeal(un);
        }
        if (n == 2)
        {
            viewMealHistory(un);
        }
        if (n == 3)
        {
            getDietRecommendations();
        }
        if (n == 4)
        {
            viewDietPlans();
        }
        if (n == 5)
        {
            addNewDiet(un);
        }
        if (n == 6)
        {
            viewyourdietplans(un);
        }
        if (n == 7)
        {
            dietPlans();
        }

    }
    //------------------------------------------------------------------------------------------------------------------------//


    void dietPlans()
    {
        fstream design;
        design.open("Diet_Plans.txt", ios::binary | ios::in);
        if (design.is_open() == 0)
        {
            cout << "\t\t\t\t\t\t    Error Opening file\n";
        }

        string diet;
        while (getline(design, diet, '\n'))
        {
            cout << "\t\t\t\t\t\t     " << diet << endl;
        }
        design.close();
    }

    //------------------------------------------------------------------------------------------------------------------------//

    void logMeal(string un)
    {

        ofstream meal(un + "_Meal_history.txt", ios::binary | ios::app);
        if (!meal.is_open())
        {
            cout << "\t\t\t\t\t\t    Error opening file for writing." << endl;
            return;
        }

        string mealName;
        cout << "\t\t\t\t\t\t    Enter name of the meal: ";
        cin.ignore();
        getline(cin, mealName);


        string calories;
        cout << "\t\t\t\t\t\t    Enter calories of your meal: ";
        getline(cin, calories);


        meal << mealName;
        meal << endl;
        meal << calories;
        meal << endl;
        cout << "\t\t\t\t\t\t    Meal logged successfully." << endl;

        meal.close();

    }

    //---------------------------------------------------------------------------------------------------------------//


    void viewMealHistory(string un) {



        fstream inputFile(un + "_Meal_history.txt", ios::in);

        if (!inputFile.is_open())
        {
            cout << "\t\t\t\t\t\t    Error opening file for reading." << endl;
        }

        string line;
        cout << "\t\t\t\t\t\t    Nutrition History:\n";
        cout << "\t\t\t\t\t\t    Meals And Calories:\n";


        while (getline(inputFile, line, '\n'))
        {
            cout << "\t\t\t\t\t\t    " << line << endl;
        }

        inputFile.close();

    }



    //-----------------------------------------------------------------------------------------------------------------------------//


    void addNewDiet(string un)
    {
        ofstream newDiet(un + "_New_Diet.txt", ios::binary | ios::app);
        if (!newDiet.is_open())
        {
            cout << "\t\t\t\t\t\t    Error opening file for writing." << endl;
            return;
        }

        int mealNumber;
        cout << "\t\t\t\t\t\t    Enter number of meals in your day: ";
        cin >> mealNumber;

        newDiet << "No of Meals in your day:" << mealNumber;
        newDiet << endl;
        string mealName;
        string mealCalories;

        for (int i = 0; i < mealNumber; i++)
        {
            cout << "\t\t\t\t\t\t    Enter name of your number " << i + 1 << " meal: ";
            cin >> mealName;
            cout << "\t\t\t\t\t\t    Enter Calories of Meal " << i + 1 << ": ";
            cin >> mealCalories;

            newDiet << "Meal " << i + 1 << ": " << mealName;
            newDiet << endl;
            newDiet << "Meal " << i + 1 << " Calories : " << mealCalories;
            newDiet << endl;
        }

        newDiet.close();
    }


    //----------------------------------------------------------------------------------------------------------------//



    void viewyourdietplans(string un)
    {
        fstream inputFile(un + "_New_Diet.txt", ios::in);
        if (!inputFile.is_open())
        {
            cout << "\t\t\t\t\t\t    Error opening file for reading." << endl;
        }

        string line;
        cout << "\t\t\t\t\t\t    Personalized Diet Plan:\n";

        while (getline(inputFile, line, '\n'))
        {
            cout << "\t\t\t\t\t\t    " << line << endl;
        }

        inputFile.close();
    }


    //-----------------------------------------------------------------------------------------------------------------//

    void getDietRecommendations()
    {
        cout << "\nDiet Recommendations:\n";
        cout << "1. Increase your intake of vegetables and fruits.\n";
        cout << "2. Choose whole grains over refined grains.\n";
        cout << "3. Limit processed foods and added sugars.\n";
        cout << "4. Stay hydrated.\n";
        cout << "5. Balance your macronutrients (proteins, carbs, and fats).\n";

    }


    //-------------------------------------------------------------------------------------------------------------------//
    void viewDietPlans() {
        double currentWeight, targetWeight;
        int timeframeInDays;

        cout << "Enter your current weight (in kg): ";
        cin >> currentWeight;

        cout << "Enter your target weight (in kg): ";
        cin >> targetWeight;

        cout << "Enter your timeframe for achieving this goal (in days): ";
        cin >> timeframeInDays;

        if (targetWeight >= currentWeight) {
            cout << "Target weight must be less than current weight.\n";
        }

        if (timeframeInDays <= 0)
        {
            cout << "Timeframe must be positive.\n";
        }
        const double CALORIES_PER_KG = 7700;

        double totalDeficit = (currentWeight - targetWeight) * CALORIES_PER_KG;

        int dailyDeficit = totalDeficit / timeframeInDays;

        cout << "\nBased on your weight loss goal, you need a daily calorie deficit of "
            << dailyDeficit << " calories.\n";
        cout << "Here are some diet plans that may help you achieve this goal:\n";

        if (dailyDeficit < 500) {
            cout << " Balanced Diet Plan\n"
                << "   - Focus on a balanced intake of carbohydrates, proteins, and healthy fats.\n"
                << "   - Reduce sugar and processed food.\n"
                << "   - Aim for 30 minutes of moderate exercise daily.\n";
        }
        else if (dailyDeficit < 1000) {
            cout << " Low-Carb Diet Plan\n"
                << "   - Reduce carbohydrate intake, focusing on proteins and healthy fats.\n"
                << "   - Include more vegetables and whole grains.\n"
                << "   - Exercise regularly.\n";
        }
        else {
            cout << " Intensive Weight Loss Plan\n"
                << "   - Consider consulting a healthcare professional.\n"
                << "   - Drastically reduce calorie intake with a high-protein, low-carb diet.\n"
                << "   - Intensive exercise (ensure medical clearance).\n";
        }
    }

};

