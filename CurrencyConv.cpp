#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
double dollar, euro, yen, peso;
cout << "Amount: " << endl;
cin >> dollar;
peso = dollar * 20.06;
euro = dollar * 0.99;
yen = dollar * 143.08;
cout << fixed << setprecision(2);
cout << setw(10) << "Dollars" << "\t" << setw(10) << "Pesos" << "\t" << setw(10) << "Euros" << "\t" << setw(10) << "Yen" << endl;
cout << setw(10) << dollar << "\t" << setw(10) << peso << "\t" << setw(10) << euro << "\t" << setw(10) << yen << endl;

return 0;
} 


