#include <iostream>
#include <iomanip>
using namespace std;
int main() 
{
int input, remainder;
    cout << "Enter a positive whole number between 2 and 1000: " << endl;
    cin >> input;
    remainder = input % 2;

if(input > 1000 || input < 2)
{
cout << "Number is not in the range 2 through 1000." << endl;
}
else if (input == 2)
{ 
    cout << "2 is prime." << endl;
    return 0;
}
switch (remainder)
{
    case 1:
    cout << input << " is prime." << endl;
    cout << input << " is divisible by:" << endl;
    if((input%2) == 0)
{
cout << "2" << endl;
}
if(input%3 == 0)
{
cout << "3" << endl;
}
 if(input%5 == 0)
{
cout << "5" << endl;
}
 if(input%7 == 0)
{
cout << "7" << endl;
}
 if(input%11 == 0)
{
cout << "11" << endl;
}
 if(input%13 == 0)
{
cout << "13" << endl;
}
 if(input%17 == 0)
{
cout << "17" << endl;
}
 if(input%19 == 0)
{
cout << "19" << endl;
}
 if(input%23 == 0)
{
cout << "23" << endl;
}
 if(input%29 == 0)
{
cout << "29" << endl;
}
 if(input%31 == 0)
{
cout << "31" << endl;
}   
return 0;
    break;

    case 0:
    cout << input << " is divisible by:" << endl;
    if((input%2) == 0)
{
cout << "2" << endl;
}
if(input%3 == 0)
{
cout << "3" << endl;
}
 if(input%5 == 0)
{
cout << "5" << endl;
}
 if(input%7 == 0)
{
cout << "7" << endl;
}
 if(input%11 == 0)
{
cout << "11" << endl;
}
 if(input%13 == 0)
{
cout << "13" << endl;
}
 if(input%17 == 0)
{
cout << "17" << endl;
}
 if(input%19 == 0)
{
cout << "19" << endl;
}
 if(input%23 == 0)
{
cout << "23" << endl;
}
 if(input%29 == 0)
{
cout << "29" << endl;
}
 if(input%31 == 0)
{
cout << "31" << endl;
}   
return 0;
    break;
}

}