#include <iostream>
#include <iomanip>
using namespace std;
int main() 

{
int lower, upper, count = 0;
cout << "Enter the ASCII code that is the lower bound [32 through 126]: ";
cin >> lower;
cout << "Enter the ASCII code that is the upper bound [" << lower << " through 126]: " << endl;
cin >> upper;

//Input validation
do
{
    if(lower < 32 || lower > 126)
    {
cout << "Error: Lower bound is invalid. Valid range of inputs are 32 through 126." << endl;
cout << "Enter the ASCII code that is the lower bound [32 through 126]:";
cin >> lower;
    }
 if(upper < 37 || upper > 126)
    {
cout << "Error: Upper bound is invalid. Valid range of inputs are " << lower << " through 126.";
cout << "Enter the ASCII code that is the upper bound [" << lower << " through 126]: ";
cin >> upper;
    }

} 
while (lower < 32 || lower > 126 || upper < 32 || upper > 126);


//Prints out the line of corresponding ASCII characters, and an if statement for making a new line every 15 characters
cout << "The characters with ASCII values in range " << lower << " through " << upper << " are:" << endl;
cout << endl;
while (lower <= upper)
{
cout << char(lower);
lower++;
count++;
if (count == 15)
{
    cout << endl;
    count = 0;
}
}
cout << endl;
return 0;
 }
