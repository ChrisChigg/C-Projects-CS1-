#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double getFutureValue()
{
    double futureVal = 0;
    do
    {
        cout << "Enter the future value of the investment: ";
        cin >> futureVal;

        if (futureVal <= 0)
        {
            cout << "Error the future value must be greater than zero." << endl;
        }
    }
    while(futureVal <= 0);
    return futureVal;
}

int readYears()
{
    int years = 0;
    do
    {
        cout << "Enter the whole number of years of the investment: ";
        cin >> years;

        if(years <= 0)
        {
cout << "Error the number of years must be greater than zero." << endl;
        }
    }
    while(years <= 0);
    return years;
}

double getInterestRate()
{
    double rate = 0;
    do
    {
        cout << "Enter the annual interest rate: ";
        cin >> rate;

        if(rate <= 0)
        {
            cout << "Error the annual interest rate must be greater than zero." << endl;
        }

    } 
    while (rate <= 0);
    return rate;
    
}

double presentValue(long double futureValue, long double interestRate, int numberYears)
{
interestRate = interestRate/100;

double presentVal = futureValue / (pow(1 + interestRate, numberYears));
return presentVal;
}

double displayResults(long double futureValue, long double interestRate, int numberYears, long double presentValue)
{
cout << fixed << setprecision(2) << showpoint;
cout << "Present value: $" << presentValue << endl; 
cout << fixed << setprecision(1) << showpoint;
cout << "Years: " << numberYears << endl;
cout << fixed << setprecision(3) << showpoint;
cout << "Annual interest rate: " << interestRate << "%" << endl;
cout << fixed << setprecision(2) << showpoint;
cout << "Future value: $" << futureValue << endl;
return 0;
}

int main()
{
    long double futureVal, rate, pv;
    int years;

    futureVal = getFutureValue();
    rate = getInterestRate();
    years = readYears();
    pv = presentValue(futureVal, rate, years);
    displayResults(futureVal, rate, years, pv);

}