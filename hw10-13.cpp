// Lab9-2.cpp - displays two monthly car payments
// Created/revised by <your name> on <current date>

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Function prototype
void getPayment(int, double, int, double&);

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
    getPayment(carPrice - rebate, creditRate / 12, term * 12, creditPayment);
    getPayment(carPrice, dealerRate / 12, term * 12, dealerPayment);

    // Display payments
    cout << fixed << setprecision(2) << endl;
    cout << "Credit union payment: $" << creditPayment << endl;
    cout << "Dealer payment: $" << dealerPayment << endl;

    return 0;
}

// ****** Function Definition ******
void getPayment(int prin, double monthRate, int months, double& monthPay)
{
    if (monthRate == 0 || months == 0)
    {
        monthPay = -1; // Handle division by 0 scenario
        return;
    }

    monthPay = prin * monthRate / (1 - pow(1 + monthRate, -months));
}
