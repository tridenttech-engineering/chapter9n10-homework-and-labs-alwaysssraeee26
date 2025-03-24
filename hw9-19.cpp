// Lab9-19.cpp - Displays two monthly car payments and total amounts
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
    cout << "Credit union annual interest rate (as decimal): ";
    cin >> creditRate;
    cout << "Dealer annual interest rate (as decimal): ";
    cin >> dealerRate;
    cout << "Loan term in years: ";
    cin >> term;

    // Convert annual interest rates to monthly and years to months
    double creditMonthRate = creditRate / 12;
    double dealerMonthRate = dealerRate / 12;
    int months = term * 12;

    // Call function to calculate payments
    creditPayment = getPayment(carPrice - rebate, creditMonthRate, months);
    dealerPayment = getPayment(carPrice, dealerMonthRate, months);

    // Calculate total amounts
    if (creditPayment != -1)
        creditTotal = creditPayment * months;
    if (dealerPayment != -1)
        dealerTotal = dealerPayment * months;

    // Display payments and totals
    cout << fixed << setprecision(2) << endl;

    if (creditPayment != -1)
    {
        cout << "Credit union monthly payment: $" << creditPayment << endl;
        cout << "Total amount paid through credit union: $" << creditTotal << endl;
    }
    else
        cout << "Error: Invalid calculation for credit union payment." << endl;

    if (dealerPayment != -1)
    {
        cout << "Dealer monthly payment: $" << dealerPayment << endl;
        cout << "Total amount paid through dealer: $" << dealerTotal << endl;
    }
    else
        cout << "Error: Invalid calculation for dealer payment." << endl;

    return 0;
}

// ****** Function Definition ******
double getPayment(int prin, double monthRate, int months)
{
    if (months <= 0)  // Ensure valid loan term
        return -1;

    // Calculate denominator
    double denominator = (1 - pow(1 + monthRate, -months));

    // Ensure denominator is not zero
    if (denominator == 0)
        return -1;

    // Compute monthly payment
    double monthPay = prin * monthRate / denominator;
    return monthPay;
}
