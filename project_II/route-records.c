#include <stdlib.h>
#include <string.h>
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
  
  // Dynamically allocate memory for an array of RouteRecords based on count
  RouteRecord* routes = (RouteRecord*)malloc(totalRecords * sizeof(RouteRecord));


  // Each RouteRecord struct object in the array has an array of 6 integers
  // to hold the # of passengers for 6 months; initialize each value to 0
  for (int i = 0; i < totalRecords; i++) {
    for (int j = 0; j < 6; j++) {
      routes[i].passengersPerMonth[j] = 0;
    }
  }


  // Rewind the fileIn pointer back to the top of the document then close document
  rewind(fileIn);

  // Close file and return the pointer of the array you dynamically allocated
  fclose(fileIn);
  return routes;
}

int fillRecords(RouteRecord* r, FILE* fileIn) {
  // Open file to analyze contents
  int usedRecords = 0;
  char buffer[10000];
  //char* data = NULL;
  char* month = NULL;
  char* originAirportCode = NULL;
  char* destAirportCode = NULL;
  char* airlineCode = NULL;
  char* passengersPerMonth = NULL;
  fileIn = fopen("data-2024.csv", "r");

  if (fileIn == NULL) {
    printf("Error opening file.\n");
    return NULL;
  }

  if (fileIn == NULL) {
    printf("Error opening file.\n");
    return NULL;
  }

  fgets(buffer, sizeof(buffer), fileIn);  // Read & ignore first/header line of CSV

  // fgets returns a pointer to the string that was read & NULL if no more characters or end of line
  // The file pointer is advanced to the beginning of the next line after successfully reading a line
  // Subsequenct calls to fgets will continue reading through a file
  while (fgets(buffer, sizeof(buffer), fileIn)) {
    // Parse current line into useful data
    month = strtok(buffer, ",");  // Read current line, split into multiple tokens using delimeter
    originAirportCode = strtok(buffer, ","); 
    destAirportCode = strtok(buffer, ",");
    airlineCode = strtok(buffer, ",");
    passengersPerMonth = strtok(buffer, ",");

    // TODO: Analyze IATA Airline Code
    usedRecords++;
  }

  // TODO: CA;; findAirlineRoute() to see if route was already entered in array
  // If found, then update record w/ passenger data for that month


  // Return actual number of RouteRecords used in the array
  // Value returned will be less than the size of the array created since not all
  // records in the original CSV file will be entered into the array
  // Close file
  fclose(fileIn);
  return usedRecords;
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