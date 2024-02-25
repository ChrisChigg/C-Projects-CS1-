#include <iostream>//for cin and cout
#include <cmath> //for sqrt and pow
#include <iomanip> //for output formatting
#include <cstdlib>//rand and srand
using namespace std;  //Define the namespace. 
int main() {
  int Min, Max;//For the range 
  int n;// For the number of samples
  double mean, standard_deviation, variance;//For the statistical parameters

//Use the following cin statements to get the information from the user
  cin>> Min;
  cin>> Max;
  if(Min > Max || Max < Min)
  {
    cin >> Min;
    cin >> Max;
  }
  cin>> n;
  if(n < 1)
  {
    cin >> n;
  }
/* Write your code here to generate the samples and compute the statistical values*/

double arr[n];
for (int i = 0; i < n; i++)
{
double random = Min + rand() % (Max - Min + 1);
arr[i] = random;
cout << arr[i] << " ";
}
cout << endl; 

//Calculate Mean
double sum = 0;
for(int i = 0; i < n; i++)
{
sum = sum + arr[i];
}
mean = sum/n;

//Calculate Standard Deviation
double sum1 = 0;
for(int i = 0; i < n; i++)
{
sum1 = sum1 + pow(arr[i] - mean, 2.0);
}
standard_deviation = sqrt(sum1/n);

//Calculate Variance
variance = pow(standard_deviation, 2.0);

//Now display the values, add any iomanip function as needed.
cout << fixed << setprecision(6);
cout << mean <<endl;
cout << standard_deviation <<endl;
cout << variance <<endl;


return 0;
}