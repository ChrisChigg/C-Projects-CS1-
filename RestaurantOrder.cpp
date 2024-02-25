#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

const int MAXPRODUCTS = 100;
string names[MAXPRODUCTS];
double prices[MAXPRODUCTS];
string codes[MAXPRODUCTS];
int numProducts = 0;

void readConfiguration() {
    //CODE HERE
    ifstream infile;
    infile.open("menu.txt");

    int i = 0;
    while(infile >> codes[i] >> names[i] >> prices[i])
    {
        i++;
        numProducts++;
    }
}

//return valid index if the item is found, return -1 otherwise.
int findItem(string inputCode) {
    //CODE HERE
    for(int i = 0; i < numProducts; i++)
    {
        if(codes[i] == inputCode)
        {
            return i;
        }
    }
    return -1;
}

// read order string like “A1 A1 E1 E2 S1” and generate the restaurant bill.
// Output the item name and price in each line, total in the final line.
void process() {
    //CODE HERE
    string order;
    getline(cin, order, '\n');
    string temp;
    stringstream newstream(order);
    double total = 0.0;

    while(getline(newstream, temp, ' '))
    {
int i = findItem(temp);
if(i != -1)
{
    cout << names[i] << ": $" << setprecision(2) << fixed << prices[i] << endl;
    total += prices[i];
}
    }
    cout << "Total: $" << setprecision(2) << fixed << total << endl;
    return 0;
}

int main() {
   readConfiguration();
   process();
}
