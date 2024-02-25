#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
//Declaring variables
double input, earthWeight, marsWeight, venusWeight;
string detail;
earthWeight = 9.807;
marsWeight = 3.7;
venusWeight = 8.87;

cout << "Input mass in kilograms: ";
cin >> input;
earthWeight = earthWeight * input;
marsWeight = marsWeight * input;
venusWeight = venusWeight * input;

//Setting string
if(earthWeight >= 1500.0000)
{
    detail = "The object is heavy";
}
else if(earthWeight <= 5.0000)
{
    detail = "The object is light";
    }
    else
    {
detail;
    }

//Setting output
if(input <= 0)
{
    cout << "mass must be greater than zero." << endl;
    return 0;
}
else
{
    if(earthWeight > 5.0000 && earthWeight < 1500.0000)
    {
           cout << fixed << setprecision(4);
cout << setw(6) << "Planet" << "\t" << setw(14) << "Weight (N)" << "\n" << endl;
cout << setw(6) << left << "Earth" << "\t" << setw(14) << right << earthWeight << "\n";
cout << setw(6) << left << "Venus" << "\t" << setw(14) << right << venusWeight << "\n";
cout << setw(6) << left << "Mars" << "\t" << setw(14) << right << marsWeight << endl;
    }
    else{
    cout << fixed << setprecision(4);
cout << setw(6) << "Planet" << "\t" << setw(14) << "Weight (N)" << "\n" << endl;
cout << setw(6) << left << "Earth" << "\t" << setw(14) << right << earthWeight << "\t" << detail << "\n";
cout << setw(6) << left << "Venus" << "\t" << setw(14) << right << venusWeight << "\n";
cout << setw(6) << left << "Mars" << "\t" << setw(14) << right << marsWeight << endl;
    }
}
    return 0;
}