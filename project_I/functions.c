#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {

  srand(time(NULL)); // Seed using the current time

  int rounds = 0;
  int p1_total = 0;  // Initialize total points for player 1
  int p2_total = 0;  // Initialize total points for player 2

  printf("Enter the number of rounds: ");
  scanf("%d", &rounds);
  printf("\n");
  
  for (int i = 1; i <= rounds; i++) {
    // TODO: Move appropriate sections to playRound()
    enum CHAMPION c1 = createChampion();  // Decide champion for player 1
    enum CHAMPION c2 = createChampion();  // Decide champion for player 2
    int c1_points = getChampionPoints(c1);
    int c2_points = getChampionPoints(c2);

    printf("ROUND %d\n", i);
    printf("----------\n");
    playRound(&p1_total, &p2_total, c1, c1_points, c2, c2_points);
    
    printf("GAME OVER!!\n");
    if (p1_total > p2_total) {
      printf("P1 Won\n");
    }
    else {
      printf("P2 Won\n");
    }
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

int getChampionWithMorePoints(int c1_points, int c2_points) {
  if (c1_points > c2_points) {
      // Champion 1 has more points
      return 1;
    }
    else if (c1_points < c2_points) {
      // Champion 2 has more points
      return 2;
    }
    else {
      // Tie
      return 0;
    }
}

void playRound(int* p1_total, int* p2_total, enum CHAMPION c1, int c1_points, enum CHAMPION c2, int c2_points) {
  int championWithHigherPoints = getChampionWithMorePoints(c1_points, c2_points);

  printf("Player points at the start of the round -- P1 = %d\tP2 = %d\n", *p1_total, *p2_total);
  printf("P1 : %s-%d\tvs\tP2 : %s-%d\n", getChampionName(c1), c1_points, getChampionName(c2), c2_points);
  
  // Both players are MAGE
  if (c1 == 0 && c2 == 0) {
    if (championWithHigherPoints == 2) {
      printf("Player 1 (%s) loses their current points.\n", getChampionName(c1));
      *p1_total -= c1_points;
      printf("Player 2 (%s) wins their current points.\n", getChampionName(c2));
      *p2_total += c2_points;
    }
    else if (championWithHigherPoints == 1) {
      printf("Player 1 (%s) wins their current points.\n", getChampionName(c1));
      *p1_total += c1_points;
      printf("Player 2 (%s) loses their current points.\n", getChampionName(c2));
      *p2_total -= c2_points;
    }
    else if (championWithHigherPoints == 0) {
      printf("Nothing happens...\n");
    }
  }
  // Both players are FIGHTER
  else if (c1 == 1 && c2 == 1) {
    printf("Both players gain their current points.\n");
    *p1_total += c1_points;
    *p2_total += c2_points;
  }
  // Both players are TANK
  else if (c1 == 2 && c2 == 2) {
    printf("Nothing happens...\n");
  }
  // Player 1 is MAGE, Player 2 is FIGHTER
  else if (c1 == 0 && c2 == 1) {
    if (championWithHigherPoints == 2) {
      printf("Player 1 (%s) loses their current points.\n", getChampionName(c1));
      *p1_total -= c1_points;
      printf("Player 2 (%s) wins but no reward.\n", getChampionName(c2));
    }
    else if (championWithHigherPoints == 1) {
      printf("Player 1 (%s) wins their current points.\n", getChampionName(c1));
      *p1_total += c1_points;
      printf("Player 2 (%s) loses but with no penalty.\n", getChampionName(c2));
    }
    else if (championWithHigherPoints == 0) {
      printf("Nothing happens...\n");
    }
  }
  // Player 1 is FIGHTER, Player 2 is MAGE
  else if (c1 == 1 && c2 == 0) {
    if (championWithHigherPoints == 2) {
      printf("Player 1 (%s) loses but with no penalty.\n", getChampionName(c1));
      printf("Player 2 (%s) wins their current points.\n", getChampionName(c2));
      *p2_total += c2_points;
    }
    else if (championWithHigherPoints == 1) {
      printf("Player 1 (%s) wins but no reward.\n", getChampionName(c1));
      printf("Player 2 (%s) loses their current points.\n", getChampionName(c2));
      *p2_total -= c2_points;
    }
    else if (championWithHigherPoints == 0) {
      printf("Nothing happens...\n");
    }
  }
  // Player 1 is MAGE, Player 2 is TANK or 
  else if (c1 == 0 && c2 == 2) {
    printf("Player 1 (%s) wins and gains their current points.\n", getChampionName(c1));
    *p1_total += c1_points;
    printf("Player 2 (%s) loses their current points.\n", getChampionName(c2));
    *p2_total -= c2_points;
  }
  // Player 1 is TANK, Player 2 is MAGE
  else if (c1 == 2 && c2 == 0) {
    printf("Player 1 (%s) loses their current points.\n", getChampionName(c1));
    *p1_total -= c1_points;
    printf("Player 2 (%s) wins and gains their current points.\n", getChampionName(c2));
    *p2_total += c2_points;
  }
  // Player 1 is FIGHTER, Player 2 is TANK
  else if (c1 == 1 && c2 == 2) {
    printf("Player 1 (%s) wins and gains their current points.\n", getChampionName(c1));
    *p1_total += c1_points;
    printf("Player 2 (%s) loses but with no penalty.\n", getChampionName(c2));
  }
  // Player 1 is TANK, Player 2 is FIGHTER
  else if (c1 == 2 && c2 == 1) {
    printf("Player 1 (%s) loses but with no penalty.\n", getChampionName(c1));
    printf("Player 2 (%s) wins and gains their current points.\n", getChampionName(c2));
    *p2_total += c2_points;
  }

  printf("Player points at the end of the round -- P1 = %d\tP2 = %d\n", *p1_total, *p2_total);
}