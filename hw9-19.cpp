// Lab9-19.cpp - displays two monthly car payments and total amounts
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

    // Input data
    cout << "Car price (after any trade-in): ";
    cin >> carPrice;
    cout << "Rebate: ";
    cin >> rebate;
    cout << "Credit union annual rate (as a decimal): ";
    cin >> creditRate;
    cout << "Dealer annual rate (as a decimal): ";
    cin >> dealerRate;
    cout << "Term in years: ";
    cin >> term;

    // Call function to calculate payments
    creditPayment = getPayment(carPrice - rebate, creditRate / 12, term * 12);
    dealerPayment = getPayment(carPrice, dealerRate / 12, term * 12);

    // Calculate total amounts
    if (creditPayment != -1)
        creditTotal = creditPayment * (term * 12);
    if (dealerPayment != -1)
        dealerTotal = dealerPayment * (term * 12);

    // Display payments and totals
    cout << fixed << setprecision(2) << endl;

    if (creditPayment != -1)
    {
        cout << "Credit union monthly payment: $" << creditPayment << endl;
        cout << "Total amount paid through credit union: $" << creditTotal << endl;
    }
    else
        cout << "Error: Invalid calculation for credit union payment (denominator was zero)." << endl;

    if (dealerPayment != -1)
    {
        cout << "Dealer monthly payment: $" << dealerPayment << endl;
        cout << "Total amount paid through dealer: $" << dealerTotal << endl;
    }
    else
        cout << "Error: Invalid calculation for dealer payment (denominator was zero)." << endl;

    return 0;
}

// ****** Function Definition ******
double getPayment(int prin, double monthRate, int months)
{
    if (months <= 0) // Invalid term
        return -1;

    double denominator = (1 - pow(1 + monthRate, -months));
    if (denominator == 0) // Check denominator
        return -1;

    double monthPay = prin * monthRate / denominator;
    return monthPay;
}
