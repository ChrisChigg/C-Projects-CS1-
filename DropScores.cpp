#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main() {

  int best, max, sum=0, count, arr[100] = {0};   // variable declaration
  float average;                             // variable declaration
  char ch;                                   // variable declaration

  
  cin >> best >> max;  // Accept input from the user
  cin.ignore();    // ignore the enter
  
  for(count = 0; ch != '\n'; count++) // Loop to accept array elements
  {
  cin >> arr[count];              // Accept array elements
  cin.get(ch);
  }  

 /* sort the array elements in ascending order*/
 for(int i=0; i < count; i++) 
   {
 for(int j = 0; j < count-i-1; j++)
   {
 if(arr[j] > arr[j+1])
 {
 int temp = arr[j];  
 arr[j] = arr[j+1];
 arr[j+1] = temp; 
 }
 }
 }

 for(int i = count - 1, j = 0; j < best && i >= 0; j++, i--){ // Loop runs for all valid scores count
   sum += arr[i];            // Calculate the sum
 }
   
 average = sum / (double)(best*max)*100; // Calculate the average
 cout << setprecision(1) << fixed << average << "%" << endl;  // print average
}