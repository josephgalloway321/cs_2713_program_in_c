#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "route-records.h"


int main( int argc, char *argv[] ) {  
  /* 1. Declare variables here */
  FILE* fileIn;
  RouteRecord* r;
  int userSelection;
  char* key1;  // Used for searching
  char* key2;  // Used for searching
  int continueProgram = 1;  // 1 = continue, 0 = end program
  int nonIntEntered;  // Used to check if non-int entered during menu selection 
  int clearInputBuffer;
  int rLength;  // Size/length of route records array

  
  /* 2. Check command line arguments here. If a command lincheckIntChosen == 0e argument (for the file name) is missing, print out the following: ERROR: Missing file name and end the program */
  if (argc < 2) {
    printf("ERROR: Missing file name\n");
    return 0;
  }
  
  /* 3. Attempt to open the file. Print out Opening <filename>... before you call fopen(). */
  printf("Opening %s...\n", argv[1]);
  fileIn = fopen(argv[1], "r");

  /* 4. Check to see if the file opens. If it does not open, print out ERROR: Could not open file and end the program. */
  if (fileIn == NULL) {
    printf("ERROR: Could not open file\n");
    return 0;
  }

  // 5. Do the following to load the records into an array of RouteRecords
  	
  // 5.1 Call createRecords(), which will read through the file once to find the total number of lines/records in the file. Use this count 
  // to dynamically allocate memory for an array of RouteRecords. It returns a pointer to that array. Don't forget to rewind the file pointer.
  r = createRecords(fileIn);

  // 5.2 Call fillRecords() to go through the CSV file again to fill in the values. It will then return the actual number of items the array has. 
  // Recall that not all records in the original CSV file will be entered into the array. 
  // Print the number of unique routes operated by different airlines: Unique routes operated by airlines: ???
  rLength = fillRecords(r, fileIn);
  printf("Unique routes operated by airlines: %d\n", rLength);

  // 5.3 Close the the file.
  //printf("Closing %s...\n", argv[1]);
  fclose(fileIn);
  
  // 6. Create an infinite loop that will do the following:
  while (continueProgram) {
    // 6.1 Call printMenu()
    printMenu();

    // 6.2 Ask the user to input a value for the menu
    // User is asked at the end of the printMenu() function
    nonIntEntered = scanf("%d", &userSelection);
    while ((clearInputBuffer = getchar()) != '\n');  // Clear standard input buffer

    // 6.3 Handle the case in which a non-integer value is entered
    if (nonIntEntered < 1) {
      printf("ERROR: Non-int entered; please choose a menu option\n");
      continue;
    }

    // 6.4 Create a switch/case statement to handle all the menu options
    switch(userSelection) {
      // 6.4.1 Each option requires the user to enter a search key
      case 1: 
        // Search by route
        printf("Enter origin: ");
        scanf("%s", key1);
        while ((clearInputBuffer = getchar()) != '\n');  // Clear standard input buffer
        
        printf("Enter destination: ");
        scanf("%s", key2);
        while ((clearInputBuffer = getchar()) != '\n');  // Clear standard input buffer
        
        printf("Searching by route...\n");
        searchRecords(r, rLength, key1, key2, ROUTE);
        break;

      case 2: 
        // Search by origin airport
        printf("Enter your origin: ");
        scanf("%s", key1);
        while ((clearInputBuffer = getchar()) != '\n');  // Clear standard input buffer
        
        printf("Searching by origin...\n");
        searchRecords(r, rLength, key1, key2, ORIGIN);
        break;

      case 3:
        // Search by destination airport
        printf("Enter your destination: ");
        scanf("%s", key1);
        while ((clearInputBuffer = getchar()) != '\n');  // Clear standard input buffer

        printf("Searching by destination...\n");
        searchRecords(r, rLength, key1, key2, DESTINATION);
        break;

      case 4:
        // Search by airline
        printf("Enter your airline: ");
        scanf("%s", key1);
        while ((clearInputBuffer = getchar()) != '\n');  // Clear standard input buffer

        printf("Searching by airline...\n");
        searchRecords(r, rLength, key1, key2, AIRLINE);
        break;

      // 6.4.2 Quit needs to free the array
      case 5:
        // Quit
        printf("Good-bye!\n");
        free(r);  // Free allocated memory for route records array
        continueProgram = 0;
        break;

      default:
        printf("ERROR: Please choose a valid menu option\n");
        break;
    }
  }

  return 0;
}
