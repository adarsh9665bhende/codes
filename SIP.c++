#include<iostream>
#include<cmath>

using namespace std;

double calculateSIP(double amount, int years, double rate) {
    // Convert annual rate to monthly rate
    double monthlyRate = rate / 1200.0;
    
    // Calculate number of monthly installments
    int totalInstallments = years * 12;
    
    // Calculate SIP value using the formula
    double sipValue = amount * ((pow(1 + monthlyRate, totalInstallments) - 1) / monthlyRate) * (1 + monthlyRate);
    
    return sipValue;
}

int main() {
    while (true) {
        // Input variables
        double amount, rate;
        int years;

        // Get user input
        cout << "Enter the SIP amount: ";
        cin >> amount;

        cout << "Enter the number of years: ";
        cin >> years;

        cout << "Enter the annual interest rate (in percentage): ";
        cin >> rate;

        // Calculate SIP and display the result
        double sipValue = calculateSIP(amount, years, rate);
        cout << "amount invested :"<< 12*years*amount<<endl;
        
        cout << "The maturity amount after " << years << " years is: " << sipValue << endl;

        // Ask if the user wants to calculate for another set of values
        char choice;
        cout << "Do you want to calculate for another set of values? (y/n): ";
        cin >> choice;

        if (tolower(choice) != 'y') {
            break; // Exit the loop if the user does not want to calculate for another set of values
        }
    }

    return 0;
}
