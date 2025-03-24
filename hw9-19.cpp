// Lab9-19.cpp - displays two monthly car payments
// Created/revised by <your name> on <current date>

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function prototype
void getPayment(int, double, int, double&, double&);

int main()
{
    int carPrice = 0;
    int rebate = 0;
    double creditRate = 0.0;
    double dealerRate = 0.0;
    int term = 0;
    double creditPayment = 0.0;
    double dealerPayment = 0.0;
    double creditTotal = 0.0;
    double dealerTotal = 0.0;

    // Input data
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

    // Calculate payments
    getPayment(carPrice - rebate, creditRate / 12, term * 12, creditPayment, creditTotal);
    getPayment(carPrice, dealerRate / 12, term * 12, dealerPayment, dealerTotal);

    // Display results
    cout << fixed << setprecision(2) << endl;
    if (creditPayment != -1)
    {
        cout << "Credit union payment: $" << creditPayment << endl;
        cout << "Total amount paid through credit union: $" << creditTotal << endl;
    }
    else
        cout << "Credit union payment calculation error (invalid denominator)." << endl;

    if (dealerPayment != -1)
    {
        cout << "Dealer payment: $" << dealerPayment << endl;
        cout << "Total amount paid through dealer: $" << dealerTotal << endl;
    }
    else
        cout << "Dealer payment calculation error (invalid denominator)." << endl;

    return 0;
}

// Function definition
void getPayment(int prin, double monthRate, int months, double& monthlyPayment, double& totalPayment)
{
    if (monthRate == 0 || months <= 0)
    {
        monthlyPayment = -1; // Return -1 if the denominator is invalid
        totalPayment = -1;
    }
    else
    {
        monthlyPayment = prin * monthRate / (1 - pow(1 + monthRate, -months));
        totalPayment = monthlyPayment * months;
    }
}
