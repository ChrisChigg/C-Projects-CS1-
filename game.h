#ifndef GAME_H
#define GAME_H

enum PLATFORM { ANDROID = 100, IOS = 200, ANDROID_IOS = 300, WEB = 400, ANDROID_WEB = 500, IOS_WEB = 600, ANDROID_IOS_WEB = 700 };

class game {
    int ID;
    int releaseYear;
    int popularity_level;
    double price;
    PLATFORM platform;
    char* title;

public:
    // Constructors and Destructor
    game();
    game(int id, double price);
    ~game();

    // Accessors and Mutators
    int getID() const;
    void setID(int id);

    int getYear() const;
    void setYear(int year);

    int getPopularityLevel() const;
    void setPopularityLevel(int popularity_level);

    double getPrice() const;
    void setPrice(double price);

    PLATFORM getPlatform() const;
    const char* getPlatformAsCString() const;
    void setPlatform(PLATFORM platform);

    char* getTitle() const;
    void setTitle(const char* title);

    // Other Methods
    void print() const;
};

#endif