#include <iostream>
#include <iomanip>
using namespace std;

int main() {
   double a1, a2, a3, e1, e2, weightedscore;
   cout << "Enter the score for Assignment 1" << endl;
   cin >> a1;
   cout << "Enter the score for Assignment 2" << endl;
   cin >> a2;
   cout << "Enter the score for Assignment 3" << endl;
   cin >> a3;
   cout << "Enter the score for Exam 1" << endl;
   cin >> e1;
   cout << "Enter the score for Exam 2" << endl;
   cin >> e2;
   weightedscore = ((a1*0.1) + (a2*0.1) + (a3*0.1) + (e1*0.35) + (e2*0.35));
   cout << fixed << setprecision(1);
   cout << "Your weighted score: " << weightedscore << endl;

   return 0;
   
   }