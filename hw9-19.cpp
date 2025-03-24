// Lab9-2.cpp - displays two monthly car payments
// Created/revised by <your name> on <current date>

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function prototype
double getPayment(int, double, int);

int main()
{
    int carPrice = 0;
    int rebate = 0;
    double creditRate = 0.0;
    double dealerRate = 0.0;
    int term = 0;
    double creditPayment = 0.0;
    double dealerPayment = 0.0;

    cout << "Car price (after any trade-in): ";
    cin >> carPrice;
    cout << "Rebate: ";
    cin >> rebate;
    cout << "Credit union rate: ";
    cin >> creditRate;
    cout << "Dealer rate: ";
    cin >> dealerRate;
    cout << "Term in years: ";
    cin >> term;

    // Call function to calculate payments
    creditPayment = getPayment(carPrice - rebate, creditRate / 12, term * 12);
    dealerPayment = getPayment(carPrice, dealerRate / 12, term * 12);

    // Check if payments were successfully calculated
    if (creditPayment == -1 || dealerPayment == -1)
    {
        cout << "Error: Denominator in the formula is 0." << endl;
    }
    else
    {
        // Display monthly payments
        cout << fixed << setprecision(2) << endl;
        cout << "Credit union payment: $" << creditPayment << endl;
        cout << "Dealer payment: $" << dealerPayment << endl;

        // Calculate total payments
        double creditTotal = creditPayment * term * 12;
        double dealerTotal = dealerPayment * term * 12;

        // Display total amounts
        cout << "Total amount paid through credit union: $" << creditTotal << endl;
        cout << "Total amount paid through dealer: $" << dealerTotal << endl;
    }

    return 0;
}

// ****** Function Definition ******
double getPayment(int prin, double monthRate, int months)
{
    if (1 - pow(1 + monthRate, -months) == 0)
    {
        return -1; // Return -1 if the denominator is 0
    }
    double monthPay = 0.0;
    monthPay = prin * monthRate / (1 - pow(1 + monthRate, -months));
    return monthPay;
}
