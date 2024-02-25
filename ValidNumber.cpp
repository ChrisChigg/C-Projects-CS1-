#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int countWords(string line) //function for counting words
{

istringstream istr(line);
string temp;
int count = 0; //created loop to count number of words in line
while (istr >> temp)
count++;
return count;
}

bool validityCheck(string token){

for (int i = 0; i < token.length(); i++) //created function which checks if word is number or not
if (isdigit(token[i]) == false)
return false;

return true;

}


int main()
{
string line,s1,s2,s3,s4,s5;
cout<<"Enter 5 scores:"<<endl;
getline(cin,line);

istringstream istr(line); // Converting the line into individual words and storing them into s1,s2....
istr>>s1>>s2>>s3>>s4>>s5;

if(countWords(line) != 5){
cout<<"Exactly 5 numbers expected."<<endl;
}else if( validityCheck(s1)==true
&& validityCheck(s2)==true
&& validityCheck(s3)==true
&& validityCheck(s4)==true
&& validityCheck(s5)==true
){
cout<<"Valid set of values."<<endl;
int i1=0,i2=0,i3=0,i4=0,i5=0;
istringstream integ(line); // Converting string into integer values
integ>>i1>>i2>>i3>>i4>>i5;


float total =(((0.1)*i1)+((0.1)*i2)+((0.1)*i3) +((0.35)*i4) + ((0.35)*i5)); // Calculating the total weight

cout<<"Total Weight:"<<total<<endl;


}else {

if(validityCheck(s1)==false){cout<<"Unexpected input:"<<s1<<endl;} //printing an unexpected input if exists
if(validityCheck(s2)==false){cout<<"Unexpected input:"<<s2<<endl;}
if(validityCheck(s3)==false){cout<<"Unexpected input:"<<s3<<endl;}
if(validityCheck(s4)==false){cout<<"Unexpected input:"<<s4<<endl;}
if(validityCheck(s5)==false){cout<<"Unexpected input:"<<s5<<endl;}
}

return 0;
}