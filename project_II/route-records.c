#include "route-records.h"

RouteRecord* createRecords(FILE* fileIn) {
  // TODO-1: Go through fileIn and count # of total records, skipping header
  int totalRecords = 0;
  fileIn = fopen("data-2024.csv", "r");

  if (fileIn == NULL) {
    printf("Error opening file.\n");
    return 1;
  }

  while (!feof(fileIn)) {
    totalRecords++;
  }
  totalRecords--;  // Subtract one because of the header
  //printf("Total Records = %d", totalRecords);
  
  RouteRecord routes[] = (RouteRecord*) malloc(totalRecords * sizeof(RouteRecord));

  fclose(fileIn);
  return routes;

  // TODO-2: Dynamically allocate memory for an array of RouteRecords based on count
  // TODO-3: Each RouteRecord struct object in the array has an array of 6 integers
  //         to hold the # of passengers for 6 months; initialize each value to 0
  // TODO-4: Rewind the fileIn pointer back to the top of the document then close document
  // TODO-5: Return the pointer of the array you dynamically allocated
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