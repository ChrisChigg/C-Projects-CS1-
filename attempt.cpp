#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;  
//Write here any code or function you need
enum STATUS{USED = 10, NEW = 20, CERTIFIED = 30;}

class car{
    int year;
    STATUS status;
    int mileage;
    int price;
    char* model;

    public:
    //Accessors/getters
    int getYear(){return year;}
    STATUS getStatus(){return status;}
    int getMileage(){return mileage;}
    int getPrice(){return price;}
    char* getModel(){return model;}

    //Mutators
    void setYear(int i){year = i;}
    void setStatus(UNIT g){status = g;}
    void setMileage(int i){mileage = i;}
    void setPrice(int i){price = i;}
    void setModel(char* s){
        if (model != nullptr){
            delete[] model;
        }
        int i = 0;
        while (s[i] != '\0'){
            i++;
        }
        model = new char[i + 1];

        i = 0;
        while(s[i] != '\0'){
            model[i] = s[i];
            i++;
        } 
        name[i] = '\0';
    }


}

int getNumberOfRecords(const char* fn){
    ifstream in;
    in.open(fn);

    if(!in.is_open()){
        return -1;
    }

    int counter = 0;
    char buffer[1000];
    while (!in.eof()){
        in.getline(buffer, sizeof(buffer));
        counter++;
    }
    in.close();
    return counter;
}

int readInputFile(const char* fn, car*& d, int aSize){
    ifstream in;
    in.open(fn);

    if(!in.is_open()){
        return -2;
    }
    int counter = 0;
    int intHelper;
    while(!in.eof() && counter < aSize){
        in >> intHelper;
        d[counter].setYear(intHelper);
        in >> intHelper;
        d[counter].setStatus((STATUS)intHelper);
    }_
}




int main() {
    // Write here your code to count the number of records, read the input file, 
    // dynamically allocate the array, etc.

    //************************* [TEST] ****************************************//
    cout <<  << endl; //Call the static function to get the number of NEW Cars
    cout <<  << endl; //Call the static function to get the number of USED  Cars
    cout <<  << endl; //Call the static function to get the number of CERTIFIED Cars

    char inputString[1000] = "2014 Dodge Durango Limited";
    car* qa = findCarByModel();//PRovide the paramters to Call the function to find the car model in inputString
    print(*qa);//Call the friend function print

    cout << getNumberOfCarsPerManufaturer() << endl; //Provide the paramters and call the function searching 
                                                    //for all the BMW
    cout << getAveragePricePerStatus() << endl; //Provide the paramters and call the function to 
                                                // get teh average price for NEW cars
    cout << getAverageMileagePerStatus() << endl;//Provide the paramters and call the function to      
                                                //get the average mileage for CERTIFIED cars

    return 0;
}