#ifndef ROUTE_RECORDS
#define ROUTE_RECORDS

#include <stdio.h>

typedef struct RouteRecord {
  char originAirportCode[4];  // Include space for null terminator
  char destAirportCode[4];
  char airlineCode[4];
  int passengersPerMonth[7];
} RouteRecord;

typedef enum SearchType {
  ROUTE, ORIGIN, DESTINATION, AIRLINE
} SearchType;

// Creates the array of RouteRecord's and initializes it
RouteRecord* createRecords(FILE* fileIn);

// Process the data in the CSV file and enter it into the array
int fillRecords(RouteRecord* r, FILE* fileIn);

// Recursive function finds a record in the RouteRecord array with the same
// origin and destination airport codes and airline that are specified
int findAirlineRoute(RouteRecord* r, int length, const char* origin, const char* destination, const char* airline, int curIdx);

// Searches the RouteRecord array and prints our the results of the search
void searchRecords(RouteRecord* r, int length, const char* key1, const char* key2, SearchType st);

// Prints the menu
void printMenu();

#endif