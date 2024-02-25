#include <iostream>
#include <iomanip>
using namespace std;
int main() 
{
int menu;
double air = 1133.2, water = 4871.0, steel = 16400.0, result, input;

cout << "\t" << "Time for Sound to Travel through a Medium given Distance" << "\n" << endl;
cout << "1 - Air" << "\n" << "2 - Water" << "\n" << "3 - Steel" << "\n" << endl;
cout << "Enter the number of the medium:" << endl;
cin >> menu;
cout << "Enter the distance to travel (in feet):" << endl; 
cin >> input;

switch(menu)
{
case 1:
result = input/air; 
cout << fixed << setprecision(4) << right;
cout << "In air it will take " << result << " seconds to travel " << input << " feet." << endl;
break;

case 2:
result = input/water; 
cout << fixed << setprecision(4) << right;
cout << "In water it will take " << result << " seconds to travel " << input << " feet." << endl;
break;

case 3:
result = input/steel; 
cout << fixed << setprecision(4) << right;
cout << "In steel it will take " << result << " seconds to travel " << input << " feet." << endl;
break;

default:
cout << "The entry is invalid. Run the program again." << endl;

}

}
