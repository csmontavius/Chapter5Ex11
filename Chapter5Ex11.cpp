 /* File Name : Chapter5Ex11.cpp
 Programmer: Montavius Spratley Burford
 Date: 04/25/2025
 Requirements: Create a program to predict the population growth of organisms. 
 Includes input validation, repeatable functionality, and modularized structure.
 */
#include <iostream>
#include <iomanip>
using namespace std;

int validateInput(const string& prompt, int minValue) {
    int value;
    do {
        cout << prompt;
        cin >> value;
        if (value < minValue) {
            cout << "Invalid input. Please enter a value greater than or equal to " << minValue << ".\n";
        }
    } while (value < minValue);
    return value;
}

void displayPopulationGrowth(int startSize, double dailyIncrease, int days) {
    cout << fixed << setprecision(2); 
    cout << "Day\tPopulation Size\n";
    cout << "---------------------\n";
    double population = startSize;
    for (int day = 1; day <= days; ++day) {
        cout << day << "\t" << population << endl;
        population += population * (dailyIncrease / 100); 
    }
}

int main() {
    char repeat; 
    do {
        
        int startSize = validateInput("Enter the starting number of organisms (minimum 2): ", 2);
        double dailyIncrease;
        do {
            cout << "Enter the average daily population increase (percentage, non-negative): ";
            cin >> dailyIncrease;
            if (dailyIncrease < 0) {
                cout << "Invalid input. Please enter a non-negative value.\n";
            }
        } while (dailyIncrease < 0);
        int days = validateInput("Enter the number of days they will multiply (minimum 1): ", 1);

        displayPopulationGrowth(startSize, dailyIncrease, days);

        cout << "\nDo you want to run the program again? (y/n): ";
        cin >> repeat;

    } while (tolower(repeat) == 'y'); 

    cout << "Goodbye!\n";
    return 0;
}
