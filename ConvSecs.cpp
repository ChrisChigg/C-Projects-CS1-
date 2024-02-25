#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
long long int input, days, hours, minutes, seconds;
cout << "Enter number of seconds: " << endl;
cin >> input;
days = input/86400;
hours = ((input%86400)/3600);
minutes = (((input%86400)%3600)/60);
seconds = (((input%86400)%3600)%60); 
if(input <= 0)
{
    cout << "seconds must be greater than zero" << endl;
    return 0;
}
else
{
    if(days > 0)
    {
        cout << "Day(s): " << days << "\n";
        }
        if(hours > 0)
        {
          cout << "Hour(s): " << hours << "\n";  
        }
        if (minutes > 0)
        {
           cout << "Minute(s): " << minutes << "\n"; 
        }
        if(seconds > 0)
        {
           cout << "Remaining second(s): " << seconds << endl; 
        }
}
   return 0;
}