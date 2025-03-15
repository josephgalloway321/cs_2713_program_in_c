#ifndef FUNCTIONS_H
#define FUNCTIONS_H

enum CHAMPION {MAGE, FIGHTER, TANK};

// Returns the String associated with the Champion value
const char* getChampionName(int championValue);

// Computes random number between min and max, inclusive, and returns it
int getRandomNumber(int min, int max);

// Decides the type of the Champion based on the probability values mentioned in games rules
// (33.33% each for MAGE, FIGHTER, and TANK)
enum CHAMPION createChampion();

// Calculates and returns the points associated with the given champion type
int getChampionPoints(enum CHAMPION c);

// Returns the player with the higher points (1 or 2); returns 0 if tie
int getChampionWithMorePoints(int c1_points, int c2_points);

// Prints out the champion type as a string when passed as an enum
void printChampion(enum CHAMPION c);

// Plays the game according to the rules 
// Takes input as the info for the current round
// Player points are updated directly as pointers
void playRound(int* p1_total, int* p2_total, enum CHAMPION c1, int c1_points, enum CHAMPION c2, int c2_points);

#endif