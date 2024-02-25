#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
double cdogs,dogs, chips, drinks, water, tax, taxable, summary, total;

tax = 8.25;

cout << "Enter amount of chili dogs sold: " << endl;
cin >> cdogs;
cout << "Enter amount of corn dogs sold: " << endl;
cin >> dogs;
cout << "Enter amount of chips sold: " << endl;
cin >> chips;
cout << "Enter amount of soft drinks sold: " << endl;
cin >> drinks;
cout << "Enter amount of water sold: " << endl;
cin >> water;
cdogs = cdogs * 8;
dogs = dogs * 6;
chips = chips * 2;
drinks = drinks * 5;
water = water * 4;

total = cdogs + dogs + chips + drinks;
taxable = (total * 8.25)/100;
summary = total + taxable + water;
cout << fixed << setprecision(2) << endl;
cout << "Taxable:     $" << setw(8) << total << "\n" << "Tax amount:  $" << setw(8) << taxable << "\n" << "Non-taxable: $" << setw(8) << water << "\n" << "Total:       $" << setw(8) << summary << endl;
    return 0;
}
