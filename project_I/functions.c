#include "functions.h"

int getRandomNumber(int min, int max) {
  return rand() % (max - min + 1) + min;
}

enum CHAMPION createChampion() {
  int randNum = getRandomNumber(1, 3);
  if (randNum == 1) {
    return MAGE;
  }
  else if (randNum == 2) {
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

void printChampion(enum CHAMPION c) {
  if (c == 0) {
    printf("MAGE");
  }
  else if (c == 1) {
    printf("FIGHTER");
  }
  else {
    printf("TANK");
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

  printf("Player points at the start of the round -- P1 = %d       P2 = %d\n", *p1_total, *p2_total);
  printf("P1: ");
  printChampion(c1);
  printf("-%d   vs   P2 : ", c1_points);
  printChampion(c2);
  printf("-%d\n", c2_points);
  
  // Both players are MAGE
  if (c1 == 0 && c2 == 0) {
    if (championWithHigherPoints == 2) {
      printf("Player 1 (");
      printChampion(c1);
      printf(") loses their current points.\n");
      *p1_total -= c1_points;
      printf("Player 2 (");
      printChampion(c2);
      printf(") wins their current points.\n");
      *p2_total += c2_points;
    }
    else if (championWithHigherPoints == 1) {
      printf("Player 1 (");
      printChampion(c1);
      printf(") wins their current points.\n");
      *p1_total += c1_points;
      printf("Player 2 (");
      printChampion(c2);
      printf(") loses their current points.\n");
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
      printf("Player 1 (");
      printChampion(c1);
      printf(") loses their current points.\n");
      *p1_total -= c1_points;
      printf("Player 2 (");
      printChampion(c2);
      printf(") wins but no reward.\n");
    }
    else if (championWithHigherPoints == 1) {
      printf("Player 1 (");
      printChampion(c1);
      printf(") wins their current points.\n");
      *p1_total += c1_points;
      printf("Player 2 (");
      printChampion(c2);
      printf(") loses but with no penalty.\n");
    }
    else if (championWithHigherPoints == 0) {
      printf("Nothing happens...\n");
    }
  }
  // Player 1 is FIGHTER, Player 2 is MAGE
  else if (c1 == 1 && c2 == 0) {
    if (championWithHigherPoints == 2) {
      printf("Player 1 (");
      printChampion(c1);
      printf(") loses but with no penalty.\n");
      printf("Player 2 (");
      printChampion(c2);
      printf(") wins their current points.\n");
      *p2_total += c2_points;
    }
    else if (championWithHigherPoints == 1) {
      printf("Player 1 (");
      printChampion(c1);
      printf(") wins but no reward.\n");
      printf("Player 2 (");
      printChampion(c2);
      printf(") loses their current points.\n");
      *p2_total -= c2_points;
    }
    else if (championWithHigherPoints == 0) {
      printf("Nothing happens...\n");
    }
  }
  // Player 1 is MAGE, Player 2 is TANK or 
  else if (c1 == 0 && c2 == 2) {
    printf("Player 1 (");
    printChampion(c1);
    printf(") wins and gains their current points.\n");
    *p1_total += c1_points;
    printf("Player 2 (");
    printChampion(c2);
    printf(") loses their current points.\n");
    *p2_total -= c2_points;
  }
  // Player 1 is TANK, Player 2 is MAGE
  else if (c1 == 2 && c2 == 0) {
    printf("Player 1 (");
    printChampion(c1);
    printf(") loses their current points.\n");
    *p1_total -= c1_points;
    printf("Player 2 (");
    printChampion(c2);
    printf(") wins and gains their current points.\n");
    *p2_total += c2_points;
  }
  // Player 1 is FIGHTER, Player 2 is TANK
  else if (c1 == 1 && c2 == 2) {
    printf("Player 1 (");
    printChampion(c1);
    printf(") wins and gains their current points.\n");
    *p1_total += c1_points;
    printf("Player 2 (");
    printChampion(c2);
    printf(") loses but with no penalty.\n");
  }
  // Player 1 is TANK, Player 2 is FIGHTER
  else if (c1 == 2 && c2 == 1) {
    printf("Player 1 (");
    printChampion(c1);
    printf(") loses but with no penalty.\n");
    printf("Player 2 (");
    printChampion(c2);
    printf(") wins and gains their current points.\n");
    *p2_total += c2_points;
  }

  printf("Player points at the end of the round -- P1 = %d       P2 = %d\n", *p1_total, *p2_total);
}