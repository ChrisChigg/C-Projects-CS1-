#include <iostream>
#include <math.h>
#include<iomanip>
using namespace std;

double getSeconds(){
    double Fall_Time; 
    cout<<"Please enter the fall time (in seconds): ";
    cin>>Fall_Time;
    
    while(Fall_Time < 0){
       if(Fall_Time<0){
           cout<<"Error the fall time must be 0 or more.\n";
           cout<<"Please enter the fall time (in seconds): ";
           cin>>Fall_Time;
       }
    }
    
    return Fall_Time; 
}

double findEarthFallDist(double Fall_Time){
    const double g = 9.81; 
    double distance = (0.5 * g) * (pow(Fall_Time, 2)); 
    
    return distance;
}


double findMoonFallDist(double Fall_Time){
    const double g = 1.625;
    double distance = (0.5 * g) * (pow(Fall_Time, 2)); 
    
    return distance; 
}

void Display(double Fall_Time,double EarthDist,double MoonDist){

    cout<<"The object traveled "<<fixed<<setprecision(3)<<EarthDist<<" meters in "<<fixed<<setprecision(1)<<Fall_Time<<" seconds on Earth.\n";
 
    cout<<"The object traveled "<<fixed<<setprecision(3)<<MoonDist<<" meters in "<<fixed<<setprecision(1)<<Fall_Time<<" seconds on the Moon.\n";
}

int main()
{
    
    double Fall_Time = getSeconds(); 
    cout<<"\n";
    double EarthDist = findEarthFallDist(Fall_Time); 
    double MoonDist = findMoonFallDist(Fall_Time); 
    
    Display(Fall_Time,EarthDist,MoonDist);
    
}