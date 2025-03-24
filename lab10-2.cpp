// Lab10-2.cpp - displays total owed
// Created/revised by <your name> on <current date>

#include <iostream>
#include <iomanip>
#include <cmath> // For ceil, if used
using namespace std;

// Function prototypes
void displayOptions();
void getRegular(int windows, double price, double &total);
void getBoGo(int windows, double price, double &total);

int main()
{
    int option = 0;
    int numOrdered = 0;
    double winPrice = 0.0;
    double totalOwed = 0.0;

    cout << fixed << setprecision(2);

    // Display options and get pricing choice
    displayOptions();
    cout << "Pricing option? ";
    cin >> option;

    // Validate and handle pricing option
    if (option == 1 || option == 2)
    {
        // Get input for number of windows and price
        cout << "Number of windows: ";
        cin >> numOrdered;
        cout << "Price per window: ";
        cin >> winPrice;

        if (numOrdered <= 0 || winPrice <= 0)
        {
            cout << "Invalid input. Number of windows and price must be positive." << endl;
        }
        else
        {
            // Calculate total based on pricing option
            if (option == 1)
                getRegular(numOrdered, winPrice, totalOwed);
            else
                getBoGo(numOrdered, winPrice, totalOwed);

            // Display the total amount owed
            cout << "Total owed -----> $" << totalOwed << endl << endl;
        }
    }
    else
    {
        cout << "Invalid option" << endl;
    }

    return 0;
}

// ***** Function Definitions *****
void displayOptions()
{
    cout << "Pricing options:" << endl;
    cout << "1 Regular pricing" << endl;
    cout << "2 BOGO pricing (Buy One, Get One Free)" << endl;
}

void getRegular(int windows, double price, double &total)
{
    total = windows * price;
}

void getBoGo(int windows, double price, double &total)
{
    total = (windows / 2 + windows % 2) * price; // Or use total = ceil(windows / 2.0) * price;
}
