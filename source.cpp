#include <iostream>
#include <iomanip>
#include <fstream>

#include "game.h" 

using namespace std; 

int getNumberOfRecords(char fn[]) {

	ifstream input;
	
	input.open(fn);

	if (!input.is_open())
		return -1;
	int counter = 0;
	
	char buffer[1000] = { '\0' };


	while (!input.eof()) {
		
		input.getline(buffer, sizeof(buffer));
	
		counter++;
	}

	input.close();
	
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
/***********************************************************************/
//Write here your code to define  and any additional function you may need.
// The class game MUST be defined in game.h and implemented in game.cpp


int readGameDataBase(char* filename, game* games, int size) {
    ifstream input;
    input.open(filename);
    if(!input.is_open())
    return -2;

    int counter = 0;
    char helper[1000];
    while(!input.eof()){

input >> games[counter].ID;
input >> games[counter].releaseYear;
input >> games[counter].popularity_level;
input >> games[counter].price;
input >> games[counter].platform;

input.getline(helper, sizeof(helper));
games[counter].name = nullptr;
copyString(helper, games[counter].name);
counter++;
    }
    input.close();
    return counter;
}

game* findGameById(game* games, int size, int id) {
    for (int i = 0; i < size; i++) {
        if (games[i].id == id) {
            return &games[i];
        }
    }
    return nullptr;
}

game* getMostPopularGamePerYear(game* games, int size, int year) {
    int maxNumPopular = 0;
    game* mostPopularGame = nullptr;
    for (int i = 0; i < size; i++) {
        if (games[i].releaseYear == year && games[i].popularity_level > maxNumPopular) {
            maxNumPopular = games[i].popularity_level;
            mostPopularGame = &games[i];
        }
    }
    return mostPopularGame;
}

int getNumberOfGamesPerPlatform(game* games, int size, PLATFORM platform) {
    int numGames = 0;
    for (int i = 0; i < size; i++) {
        if (games[i].platform == platform) {
            numGames++;
        }
    }
    return numGames;
}

double getAveragePricePerPlatform(game* games, int size, PLATFORM platform, int numGames) {
    double total = 0.0;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (games[i].platform == platform) {
            total += games[i].price;
            count++;
        }
    }
    if (count == 0) {
        return 0.0;
    }
    return total / numGames;
}



int main() {      
 
    char game_db_filename[] = "games_db2.txt";


    int game_db_size = getNumberOfRecords(game_db_filename);


    if (game_db_size <= 0)
        return game_db_size;


    game* game_db_array = new game[game_db_size];


    int ret_value = readGameDataBase(game_db_filename, game_db_array, game_db_size);
    
  
    if (ret_value <= 0)
        return ret_value;
    
  
    int test_game_id;
    cin >> test_game_id;
    game* cgame = findGameById(game_db_array, game_db_size, test_game_id);
    if (cgame != nullptr)
        cgame->print();
    
   
    int test_year;
    cin >> test_year;
    cgame = getMostPopularGamePerYear(game_db_array, game_db_size, test_year);
    if (cgame != nullptr)
        cgame->print();

   
    int test_platform;
    cin >> test_platform;
    int number_of_games = getNumberOfGamesPerPlatform(game_db_array, game_db_size, (PLATFORM)test_platform);

   
    double test_average_price = getAveragePricePerPlatform(game_db_array, game_db_size, (PLATFORM)test_platform, number_of_games);
    cout << fixed << setprecision(2) << test_average_price << endl;
    
    return 0;
}