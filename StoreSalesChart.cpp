#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//Functions read and display
bool read(ifstream &file_name, long long int &value, unsigned int &index)

{
file_name >> index >> value;

while(file_name) 
{
if(index < 1 || index > 99)
{
    cout << "Error! The store number " << index << " is not valid." << endl;
}
else if(value < 0)
{
    cout << "Error! The sales value for store " << index << " is negative." << endl;
}
else
{
    return true;
}
file_name >> index >> value;
}
return false;
}

void display(ofstream &output_name, long long int value, unsigned int index)

{
output_name << "Store " << setw(2) << index << ": ";
for(int i = 0; i < value/5000; i++)
{
output_name << "*";
}
output_name << "\n";
}

int main()
{
string file_name;
long long int value;
unsigned int store_index;

bool valid = true;

ifstream inputfile;
cout << "Enter input file name: " << endl;
cin >> file_name;

inputfile.open(file_name);
ofstream output_file;

if(!inputfile)
{
cout << "Error File \"" << file_name << "\" could not be opened." << endl;
return -1;
}

output_file.open("saleschart.txt");

while(read(inputfile, value, store_index) == true)
{
if(valid)
{
    output_file << "SALES BAR CHART" << endl;
    output_file << "(Each * equals 5,000 dollars)" << endl;
    valid = false;
}

display(output_file, value, store_index);
}
inputfile.close();
output_file.close();
return 0;
}