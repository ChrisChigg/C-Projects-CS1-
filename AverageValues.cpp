#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;
int main()
{
//Declaring variables
ifstream Input;
ofstream Output;
double total = 0.0, average = 0.0, number;
string filename;
int count = 0, valid = 0, invalid = 0;

//Ask for file name and open the input file
cout << "Enter the input file name: " << endl;
cin >> filename;

Input.open(filename.c_str());

//File name check
if(Input.fail())
{
    cout << "The file \"nofile.txt\" could not be opened." << endl; 
return 1;
}

//If file is valid, create/open badvalues.txt
else
{
    Output.open("badvalues.txt");

//Check which numbers are valid or invalid
    while(Input >> number)
    {
count ++;
if(number >= 0 && number <= 110)
{
total += number;
valid++;
}
else
{
invalid++;
Output << number << endl;
}
    }
    Input.close();
}

//Displaying results
cout << "Total number of values read: " << count << endl;
cout << "Valid values read: " << valid << endl;
cout << "Invalid values read: " << invalid  << endl;

if(valid == 0)
{
    cout << "The file did not contain any valid values." << endl;
}
else
{
    //Set to show 2 decimal places    
cout << setprecision(2) << fixed << showpoint;
average = total / valid;
cout << "The average of the valid numbers read = " << average << endl;
}
return 0;
}