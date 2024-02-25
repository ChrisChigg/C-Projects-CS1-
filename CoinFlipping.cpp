#include <iostream>
#include <iomanip>
#include <cstdlib>       
using namespace std;
int main() 
{

unsigned int seed;
char input = 'Y';
int heads = 0, tails = 0, output, total = 0;
double hPercent, tPercent;

cin >> seed;

// Call the srand function to seed the random number generator
// The seed is the argument passed to the function

srand(seed);
do
{
//Execute if 'Y' is entered
    if(input == 'Y' || input == 'y')
    {
        output = (1 + rand() % 2);
if(output == 1)
{
    cout << "Flip = Heads" << endl;
    heads++;
    total++;
}
else if (output == 2)
{
      cout << "Flip = Tails" << endl;
    tails++;
    total++;
}
cout << "To keep flipping, press Y for Yes, to show results, press N for No." << endl;
cin >> input;
 }
//Execute if 'N' is entered
    if(input == 'N' || input == 'n')
    {
        hPercent = ((heads * 100.0)/total);
        tPercent = ((tails * 100.0)/total);
        cout << fixed << setprecision(1) << endl;
cout << heads << " of the " << total << " flips were Heads or " << hPercent << "% were Heads." << endl;
cout << tails << " of the " << total << " flips were Tails or " << tPercent << "% were Tails." << endl;
return 0;
    }

//Execute if an invalid entry is detected
else if (input != 'Y' && input != 'y' && input != 'N' && input != 'n')
    {
cout << "Invalid input. Press either 'Y' to keep flipping or 'N' to exit." << endl;
cin >> input;
    }
} while (input != 'N' || input != 'n');

    return 0;
}
