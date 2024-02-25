/*
For each class we need to write:
-- acessors and mutators for each data member
-- constructor to set numeric values to zero (or a value out of a valid range),
    enums to the smallest enumerator value, and pointers to nullptr.
-- destructors to release any dynamically allocated memory
The program:
a) Write a class "person" with the data members
    i) ID: an integer > 0
    ii) Name: variable size c string
b) Derive a class from "person" and name it "employee" with data members:
    i) UNIT: an enumerator with values MARKETING = 0, SALES = 1, ENGINEERING = 2,
    and CUSTOMER_SUPPORT = 3;

-----The information for a) is in a file named person.txt
The format:
    <ID> <NAME>
Where:
    ID is an integer > 0
    NAME is a variable size C string

----- The information for the employee is found in a file named employee.txt
The format:
    <ID> <UNIT>
Where: 
    ID is an integer > 0
    UNIT is an enum value (0 to 3 representing MARKETING... CUSTOMER_SUPPORT)

You can write the classes as inline
a) Read the input files and match the employee and person data
b) Count the number of employees per UNIT
c) Write a friend function to display the state of an employee object
d) Display the employee information sorted by unit using the table format
    <ID>    <UNIT _AS_CSTRING>  <FULL_NAME>
For example: 
    10026   SALES   Cornelius Sparks

You can set the data members of the base class as protected and inherit all the behaviors as public.
The header files allowed are iostream, fstream, and iomanip
*/

#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

//base class
class person{
    int id;
    char* name;
protected:
//Accessor/getters
int getId(){return id;}
char* getName(){return name;}
//Mutators
void setID(int i){id = i;}
void setName(const char* s){
    if(name != nullptr){
        delete[] name;
    }
int i = 0;
while(s[i] != '\0'){
    i++;
}
name = new char[i+1];
i = 0;
while(s[i] != '\0'){
    name[i] = s[i];
    i++;
}
name[i] = '\0';  
}
//Destructors
person(){
    id = 0;
    name = nullptr;
    }   
~person(){
     if(name != nullptr){
        delete[] name;
    }
}
};

//derived class
enum UNIT {MARKETING, SALES, ENGINEERING, CUSTOMER_SUPPORT};
class employee : public person{
    UNIT department;
public: 
    UNIT getDepartment(){return department;}
    void setDepartment(UNIT g){department = g;}
    /*
    Typecasting method: void setDaprtment(int g) {department = (UNIT)g;}
    */
    employee(){
        department = MARKETING;
    }
~employee(){}
friend void display(const employee&);
};
void display(const employee& o){
cout << fixed << setw(10)<< o.id
switch(o.department){
    case MARKETING: cout << setw(20) << "MARKETING";
    case SALES: cout << setw(20) << "SALES"; 
    case ENGINEERING << setw(20) << "ENGINEERING";
    case CUSTOMER_SUPPORT << setw(20) << "CUSTOMER_SUPPORT"
}
cout << setw(30) << o.name << endl;
}

int getNumberOfRecords(char* fn){
    ifstream in;
    in.open(fn);

    if(!in.is_open())
    return -1;
    char buffer[1000];
    int counter = 0;
    while (!in.eof()){
        in.getline(buffer, sizeof(buffer));
        counter++;
    }
    in.close();
    return counter;
}

int readEmployeeFile(const char* fn, employee*& d, int aSize){
    ifstream in;
    in.open(fn);

    if(!in.is_open())
    return -1;
    char buffer[1000];
    int counter = 0;
    //<ID> <UNIT>
    int intHelper;
    while (!in.eof()){
        in >> intHelper;
        d[counter].setId(intHelper);
        in >> intHelper;
        d[counter].setDepartment(intHelper);
        counter++;
    }
    in.close();
    return counter;
}


int readPersonFile(const char* fn, employee*& d, int aSize){
    ifstream in;
    in.open(fn);

    if(!in.is_open())
    return -1;
    char buffer[1000];
    int counter = 0;
    //<ID> <NAME>
    int intHelper;
    while (!in.eof()){
        in >> intHelper;
        in.getline(buffer, sizeof(buffer));
        d[counter].setName(buffer);
        counter++;
    }
    in.close();
    return counter;

int countEmployeesinSALES(employee* d, int aSize){
    int counter = 0;
    for(int i = 0, i< aSize; i++){
        if(d[i].getDepartment()!= SALES)
        continue;
        counter++
    }
    return counter;
}

}
int main(){
    int N = getNumberOfRecords("employee.txt");
    employee* data = new employee[N];
    readEmployeeFile("employee.txt", data, N);
    readPersonFile("person.txt", data, N);
    for(int i = 0; i < N; i++)
    {
        display (data[i]);
    }

    return 0;
}