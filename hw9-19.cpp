// Lab9-2.cpp - displays two monthly car payments and total amounts
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
    double creditTotal = 0.0;
    double dealerTotal = 0.0;

    // User input
    cout << "Car price (after any trade-in): ";
    cin >> carPrice;
    cout << "Rebate: ";
    cin >> rebate;
    cout << "Credit union annual rate (in decimal, e.g. 0.05): ";
    cin >> creditRate;
    cout << "Dealer annual rate (in decimal, e.g. 0.06): ";
    cin >> dealerRate;
    cout << "Term in years: ";
    cin >> term;

    int months = term * 12;

    // Call function to calculate monthly payments
    creditPayment = getPayment(carPrice - rebate, creditRate / 12, months);
    dealerPayment = getPayment(carPrice, dealerRate / 12, months);

    cout << fixed << setprecision(2) << endl;

    // Display results for credit union
    if (creditPayment != -1)
    {
        creditTotal = creditPayment * months;
        cout << "Credit union monthly payment: $" << creditPayment << endl;
        cout << "Total amount paid through credit union: $" << creditTotal << endl;
    }
    else
    {
        cout << "Error: Credit union payment calculation invalid (division by zero)." << endl;
    }

    // Display results for dealer
    if (dealerPayment != -1)
    {
        dealerTotal = dealerPayment * months;
        cout << "Dealer monthly payment: $" << dealerPayment << endl;
        cout << "Total amount paid through dealer: $" << dealerTotal << endl;
    }
    else
    {
        cout << "Error: Dealer payment calculation invalid (division by zero)." << endl;
    }

    return 0;
}

// ****** Function Definition ******
double getPayment(int principal, double monthRate, int months)
{
    double denominator = 1 - pow(1 + monthRate, -months);

    // Check if denominator is zero
    if (denominator == 0)
        return -1; // Return -1 if denominator is zero

    double monthPay = principal * monthRate / denominator;
    return monthPay;
}
