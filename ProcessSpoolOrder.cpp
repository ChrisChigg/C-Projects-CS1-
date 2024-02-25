#include <iostream>
#include <iomanip>
using namespace std;

void getOrder(int &onOrder, int &inStock, double &diffCharge, double &handling)
{
cout << "Please enter the number of spools ordered: ";
cin >> onOrder;

if(onOrder <= 0)
{
    cout << "Error, the number of spools must bet at least 1.";
    cin >> onOrder;
}


cout << "Please enter the number of spools in stock: ";
cin >> inStock;
if(inStock < 0)
{
    cout << "Error, the spools in stock should be 0 or more.";
    cin >> inStock; 
}

char ch;
cout << "Is there a custom shipping and handling charge (Enter Y for Yes or N for No)? ";
cin >> ch;
if(ch == 'Y' || ch == 'y')
{
    cout << "What is the shipping and handling charge? ";
    cin >> diffCharge;
    if(diffCharge < 0)
    {
        cout << "Error, the charge must be at least $0.00.";
        cin >> diffCharge;
    }
}

}

int calcShipping(int onOrder, int inStock, float diffCharge, float handling)
{
    int ship_pools;
cout << "\n";
if(onOrder <= inStock)
{
cout << "Spools ready for shipping: " << onOrder << endl;
ship_pools = onOrder;
}

else
{
cout << "Spools ready for shipping: " << inStock <<endl;
cout << "Spools on back order: " << onOrder-inStock << endl;
ship_pools = inStock;
}
float charge_pools = ship_pools * 157.55;
cout << fixed << setprecision(2);
cout << "Charges for " << ship_pools << " spools: $" << charge_pools << endl;

if(diffCharge == 0)
{
    float fee = ship_pools * handling;
    cout << fixed << setprecision(2);
    cout << "Shipping and handling for " << ship_pools << " spools: $" << fee << endl;
    cout << fixed << setprecision(2);
cout << "Total charges (Incl. shipping & handling): $" << charge_pools + fee << endl;
}
else
{
    double fee = ship_pools * diffCharge;
    cout << fixed << setprecision(2);
    cout <<"Shipping and handling for " << ship_pools << " spools: $" << fee << endl; 
    cout << fixed << setprecision(2);
cout << "Total charges (Incl. shipping & handling): $" << charge_pools + fee << endl;
}
return 0;   
}



int main()
{
int onOrder, inStock;
float diffCharge = 0.0, handling = 20.95;

getOrder(onOrder, inStock, diffCharge, handling);
calcShipping(onOrder, inStock, diffCharge, handling);

    return 0;
}