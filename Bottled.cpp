#include <iostream>
using namespace std;
int main() 
{
    int s , v1 , v2, Nv1 , Nv2, r=0; 
    cin >> s >> v1 >> v2; 
    for (int i=0 ;; i++) 
    {
     r = s - v2 * i; 
    if (r % v1 == 0)
    { 
        Nv1 = r / v1; 
        Nv2 = i; 
    cout << Nv1 << " " << Nv2 << endl; 
    break;
    } 
    else if (r < 0)
    { 
        cout << "Impossible" << endl;
         break;
         } 
         else 
         {
            continue;
            }
             }
              return 0;
              }
