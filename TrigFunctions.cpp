#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
 int main()
 {
double input, Pi, radians;
cout << "Input degrees:" << "\n"; 
cin >> input;
Pi = acos(-1);
radians = input*(Pi/180);
cout << "sine(" << radians << ") = " << sin(radians) << "\n" << "cosine(" << radians << ") = " << cos(radians) << "\n" << "tangent(" << radians << ") = " << tan(radians) << endl;
 }