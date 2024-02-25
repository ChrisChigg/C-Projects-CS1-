#include "game.h"
#include <cstring>
#include <iostream>

using namespace std;

// Default Constructor
game::game() {
    ID = 0;
    year = 0;
    popularity_level = 0;
    price = 0.0;
    platform = WEB;
    title = nullptr;
}

// Parameterized Constructor
game::game(int id, double price) {
    ID = id;
    year = 0;
    popularity_level = 0;
    this->price = price;
    platform = WEB;
    title = nullptr;
}

// Destructor
game::~game() {
    delete[] title;
}

// Accessors and Mutators
int game::getID() const {
    return ID;
}

void game::setID(int id) {
    ID = id;
}

int game::getYear() const {
    return year;
}

void game::setYear(int year) {
    this->year = year;
}

int game::getPopularityLevel() const {
    return popularity_level;
}

void game::setPopularityLevel(int popularity_level) {
    this->popularity_level = popularity_level;
}

double game::getPrice() const {
    return price;
}

void game::setPrice(double price) {
    this->price = price;
}

PLATFORM game::getPlatform() const {
    return platform;
}

const char* game::getPlatformAsCString() const {
    switch (platform) {
        case ANDROID:
            return "Android";
        case IOS:
            return "iOS";
        case ANDROID_IOS:
            return "Android and iOS";
        case WEB:
            return "Web";
        case ANDROID_WEB:
            return "Android and Web";
        case IOS_WEB:
            return "iOS and Web";
        case ANDROID_IOS_WEB:
            return "Android, iOS, and Web";
        default:
            return "Unknown";
    }
}

void game::setPlatform(PLATFORM platform) {
    this->platform = platform;
}

char* game::getTitle() const {
    return title;
}

void game::setTitle(const char* title) {
    // Deallocate any previously allocated memory
    delete[] this->title;

    // Allocate memory for the new title
    this->title = new char[strlen(title) + 1];

    // Copy the new title into the allocated memory
    strcpy(this->title, title);
}

// Other Methods
void game::print() const {
    cout << "Title: " << title << endl;
    cout << "ID: " << ID << endl;
    cout << "Year: " << year << endl;
    cout << "Popularity Level: " << popularity_level << endl;
    cout << "Price: $" << price << endl;
    cout << "Platform: " << getPlatformAsCString() << endl;
}