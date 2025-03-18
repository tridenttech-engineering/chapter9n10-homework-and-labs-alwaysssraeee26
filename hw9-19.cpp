// Lab 9-2.cpp - displays two monthly car payments
// Created/revised by <your name> on <current date>

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function prototype
double getPayment(int principal, double monthlyRate, int months);

int main()
{
    // Declare variables
    int carPrice = 0;
    int rebate = 0;
    double creditRate = 0.0;
    double dealerRate = 0.0;
    int term = 0;
    double creditPayment = 0.0;
    double dealerPayment = 0.0;

    // User input
    cout << "Car price (after any trade-in): ";
    cin >> carPrice;
    cout << "Rebate: ";
    cin >> rebate;
    cout << "Credit union rate (as %): ";
    cin >> creditRate;
    cout << "Dealer rate (as %): ";
    cin >> dealerRate;
    cout << "Term in years: ";
    cin >> term;

    // Convert rates from percentage to decimal
    creditRate /= 100;
    dealerRate /= 100;

    // Calculate monthly payments
    creditPayment = getPayment(carPrice - rebate, creditRate / 12, term * 12);
    dealerPayment = getPayment(carPrice, dealerRate / 12, term * 12);

    // Display results
    cout << fixed << setprecision(2) << endl;

    if (creditPayment == -1)
    {
        cout << "Error: Invalid loan calculation for Credit Union.\n";
    }
    else
    {
        cout << "Credit union monthly payment: $" << creditPayment << endl;
        cout << "Total amount paid through Credit Union: $" << (creditPayment * term * 12) << endl;
    }

    if (dealerPayment == -1)
    {
        cout << "Error: Invalid loan calculation for Dealer.\n";
    }
    else
    {
        cout << "Dealer monthly payment: $" << dealerPayment << endl;
        cout << "Total amount paid through Dealer: $" << (dealerPayment * term * 12) << endl;
    }

    return 0;
} // End of main function

// ***** Function Definition *****
double getPayment(int principal, double monthlyRate, int months)
{
    // Handle 0% interest rate
    if (monthlyRate == 0)
    {
        return static_cast<double>(principal) / months;
    }

    // Calculate denominator and validate
    double denominator = (1 - pow(1 + monthlyRate, -months));
    if (denominator == 0)
    {
        return -1; // Return -1 to indicate an error
    }

    // Calculate and return monthly payment
    return principal * monthlyRate / denominator;
} // End of getPayment function
