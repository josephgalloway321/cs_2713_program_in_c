#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {

  srand(time(NULL)); // Seed using the current time

  int rounds = 0;
  int p1_points = 0;  // Initialize points for player 1
  int p2_points = 0;  // Initialize points for player 2
  int* p1_total = &p1_points;  // Total points for player 1
  int* p2_total = &p2_points; // Total points for player 2

  printf("Enter the number of rounds: ");
  scanf("%d", &rounds);
  printf("\n");
  
  for (int i = 0; i < rounds; i++) {
    // TODO: Move appropriate sections to playRound()
    enum CHAMPION c1 = createChampion();  // Decide champion for player 1
    enum CHAMPION c2 = createChampion();  // Decide champion for player 2
    int c1_points = getChampionPoints(c1);
    int c2_points = getChampionPoints(c2);

    printf("%d\n", c1_points);
    printf("%d\n", c2_points);

    printf("ROUND %d\n", i);
    printf("________\n");
    // Call playRound();
  }

  return 0;
}


int getRandomNumber(int min, int max) {
  return rand() % (max - min + 1) + min;
}

enum CHAMPION createChampion() {
  int randNum = getRandomNumber(1, 3);
  if (randNum == 0) {
    return MAGE;
  }
  else if (randNum == 1) {
    return FIGHTER;
  }
  else {
    return TANK;
  }
}

int  getChampionPoints(enum CHAMPION c) {
  if (c == 0) {
    return getRandomNumber(1, 8);
  }
  else if (c == 1) {
    return getRandomNumber(3, 7);
  }
  else {
    return getRandomNumber(5, 9);
  }
}

// void playRound(int* p1_total, int* p2_total, enum CHAMPION c1, int c1_points, enum CHAMPION c2, int c2_points) {

// }