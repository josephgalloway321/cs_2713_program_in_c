#include <stdlib.h>
#include "route-records.h"

RouteRecord* createRecords(FILE* fileIn) {
  // Go through fileIn and count # of total records, skipping header
  int totalRecords = 0;
  fileIn = fopen("data-2024.csv", "r");

  if (fileIn == NULL) {
    printf("Error opening file.\n");
    return NULL;
  }

  while (!feof(fileIn)) {
    totalRecords++;
  }
  totalRecords--;  // Subtract one because of the header
  //printf("Total Records = %d", totalRecords);
  
  //Dynamically allocate memory for an array of RouteRecords based on count
  RouteRecord* routes = (RouteRecord*)malloc(totalRecords * sizeof(RouteRecord));


  // Each RouteRecord struct object in the array has an array of 6 integers
  // to hold the # of passengers for 6 months; initialize each value to 0
  for (int i = 0; i < totalRecords; i++) {
    for (int j = 0; j < 6; j++) {
      routes[i].passengersPerMonth[j] = 0;
    }
  }


  // TODO-4: Rewind the fileIn pointer back to the top of the document then close document
  // TODO-5: Return the pointer of the array you dynamically allocated

  fclose(fileIn);
  return routes;
}

int fillRecords(RouteRecord* r, FILE* fileIn) {
  return 0;
}

int findAirlineRoute(RouteRecord* r, int length, const char* origin, 
                     const char* destination, const char* airline, int curIdx) {
  return 0;
}

void searchRecords(RouteRecord* r, int length, const char* key1, const char* key2,
                   SearchType st) {

}

void printMenu() {
  printf("\n\n######### Airline Route Records Database MENU #########\n");
  printf("1.  Search by Route\n");
  printf("2.  Search by Origin Airport\n");
  printf("3.  Search by Destination Airport\n");
  printf("4.  Search by Airline\n");
  printf("5.  Quit\n");
  printf("Enter your selection: ");
}