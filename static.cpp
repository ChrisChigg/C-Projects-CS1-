#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std; 
//Write here any code or function you need
enum STATUS {USED = 10, NEW = 20, CERTIFIED = 30};

class car {
private:
    int year;
    STATUS status;
    int mileage;
    int price;
    char* model;

    static int new_count;
    static int used_count;
    static int certified_count;

public:
    car();
    ~car();

    int getYear() const;
    void setYear(int);

    STATUS getStatus() const;
    void setStatus(STATUS);

    int getMileage() const;
    void setMileage(int);

    int getPrice() const;
    void setPrice(int);

    const char* getModel() const;
    void setModel(const char*);

    static int getNewCount();
    static int getUsedCount();
    static int getCertifiedCount();

    const char* getStatusAsCString() const;
    friend void print(const car&);
};

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

int getStringLength(const char* str) {

int i = 0;

while (str[++i] != '\0');
return i;
}

void copyString(const char* src, char*& dst) {

int len = getStringLength(src);

dst = new char[len + 1];

int i = 0;
while (src[i] != '\0') {

dst[i] = src[i];

i++;
}

dst[i] = '\0';
}

int readCarDataBase(const char fn[], car*& c, int size){
ifstream in;
in.open(fn);
if(!in.is_open()){
return -2;
}
char buffer[1000];
int counter = 0;
int num;
while(!in.eof() && counter < size){
in >> num;
c[counter].setYear(num);
in >> num;
c[counter].setStatus((STATUS) num);
in >> num;
c[counter].setMileage(num);
in >> num;
c[counter].setPrice(num);
in.getline(buffer, sizeof(buffer));
c[counter].setModel(buffer);

counter++;
}
in.close();
return counter;
}

car* findCarByModel(car* cars, int size, const char* model) {
    for (int i = 0; i < size; i++) {
        if ((cars[i].getModel(), model) == 0) {
            return &cars[i];
        }
    }
    return nullptr;
}

int getNumberOfCarsPerManufacturer(car* cars, int size, const char* manufacturer) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if ((cars[i].getModel(), manufacturer) != nullptr) {
            count++;
        }
    }
    return count;
}

double getAveragePricePerStatus(car* cars, int size, STATUS status) {
    int count = 0;
    double totalPrice = 0.0;
    for (int i = 0; i < size; i++) {
        if (cars[i].getStatus() == status) {
            count++;
            totalPrice += cars[i].getPrice();
        }
    }
    return (count == 0) ? 0.0 : totalPrice / count;
}

double getAverageMileagePerStatus(car* cars, int size, STATUS status) {
    int count = 0;
    double totalMileage = 0.0;
    for (int i = 0; i < size; i++) {
        if (cars[i].getStatus() == status) {
            count++;
            totalMileage += cars[i].getMileage();
        }
    }
    return (count == 0) ? 0.0 : totalMileage / count;
}

int main() {

char filename[] = "cars_db2.txt";

int car_records = getNumberOfRecords(filename);

if(car_records < 0){
    return car_records;
}

car* oto = new car[car_records];

int data_val = readCarDataBase(filename, oto, car_records);

if(data_val < 0){
    return data_val;
    //************************* [TEST] ****************************************//
    cout <<  << endl; 
    cout <<  << endl; 
    cout <<  << endl; 

    char inputString[1000] = "2014 Dodge Durango Limited";
    car* qa = findCarByModel();
    print(*qa);

    cout << getNumberOfCarsPerManufaturer() << endl; 
                                                    
    cout << getAveragePricePerStatus() << endl; 
                                                
    cout << getAverageMileagePerStatus() << endl;
                                                

    return 0;
}
}