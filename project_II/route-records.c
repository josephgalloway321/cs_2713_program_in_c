#include <stdlib.h>
#include <string.h>
#include "route-records.h"

RouteRecord* createRecords(FILE* fileIn) {
  // Go through fileIn and count # of total records, skipping header
  int totalRecords = 0;
  char charReadInFile;
  //fileIn = fopen("data-2024.csv", "r");

  if (fileIn == NULL) {
    printf("Error opening file.\n");
    return NULL;
  }
  
  while (charReadInFile != EOF) {
    charReadInFile = fgetc(fileIn);
    if (charReadInFile == '\n') {
      totalRecords++;
    }
  }
  totalRecords--;  // Subtract one because of the header
  //printf("Total Records = %d\n", totalRecords);
  
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
  //fclose(fileIn);
  return routes;
}

int fillRecords(RouteRecord* r, FILE* fileIn) {
  // Open file to analyze contents
  int usedRecords = 0;
  char buffer[10000];
  char* month = NULL;
  char* originAirportCode = NULL;
  char* destAirportCode = NULL;
  char* airlineCode = NULL;
  char* totalPassengersForMonthForRoute = NULL;
  int routeRecordIdx = -1;
  int rSize = sizeof(r) / sizeof(r[0]);
  fileIn = fopen("data-2024.csv", "r");

  if (fileIn == NULL) {
    printf("Error opening file.\n");
    return -1;
  }

  fgets(buffer, sizeof(buffer), fileIn);  // Read & ignore first/header line of CSV

  // fgets returns a pointer to the string that was read & NULL if no more characters or end of line
  // The file pointer is advanced to the beginning of the next line after successfully reading a line
  // Subsequenct calls to fgets will continue reading through a file
  while (fgets(buffer, sizeof(buffer), fileIn)) {
    //printf("%s\n", buffer);  // Print each line for testing

    // Parse current line into useful data
    month = strtok(buffer, ",");  // Read current line, split into multiple tokens using delimeter
    originAirportCode = strtok(NULL, ","); 
    destAirportCode = strtok(NULL, ",");
    airlineCode = strtok(NULL, ",");
    totalPassengersForMonthForRoute = strtok(NULL, ",");

    // Analyze IATA Airline Code
    if (strlen(airlineCode) == 3) {
      continue;  // Skip to next iteration
    }
    
    // Call findAirlineRoute() to see if route was already entered in array, r
    // If found, then update record w/ passenger data for that month
    // If not then add new route to the array
    routeRecordIdx = findAirlineRoute(r, rSize, originAirportCode, destAirportCode, airlineCode, rSize);
    if (routeRecordIdx != -1) {
      // Update record w/ passenger data for that month
      r[routeRecordIdx].passengersPerMonth[atoi(month)] = atoi(totalPassengersForMonthForRoute);
    }
    else {
      // Create new record w/ route info then add to array
      struct RouteRecord newRouteRecord;
      strcpy(newRouteRecord.originAirportCode, originAirportCode);
      strcpy(newRouteRecord.destAirportCode, destAirportCode);
      strcpy(newRouteRecord.airlineCode, airlineCode);
      newRouteRecord.passengersPerMonth[atoi(month)] = atoi(totalPassengersForMonthForRoute);
      
      // TODO: Double check this is correct
      r[usedRecords] = newRouteRecord;
    }

    // Increment usedRecords after adding route to RouteRecord array
    usedRecords++;
  }

  // Return actual number of RouteRecords used in the array
  // Value returned will be less than the size of the array created since not all
  // records in the original CSV file will be entered into the array
  // Close file
  fclose(fileIn);
  return usedRecords;
}

int findAirlineRoute(RouteRecord* r, int length, const char* origin, const char* destination, const char* airline, int curIdx) {
  if (curIdx < 0) {
    return -1;
  }
  // If route record found in array, r
  if(strcmp(r[curIdx].originAirportCode, origin) == 0 && strcmp(r[curIdx].destAirportCode, destination) == 0 && strcmp(r[curIdx].airlineCode, airline) == 0) {
    return curIdx;
  }

  return findAirlineRoute(r, length, origin, destination, airline, curIdx - 1);
}

void searchRecords(RouteRecord* r, int length, const char* key1, const char* key2, SearchType st) {
  // If user searches by origin, destination, or airline
  if (st == 1 || st == 2 || st == 3) {
    // Merp
  }
  // User searched by route
  else {

  }

  // TODO: Print out info
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