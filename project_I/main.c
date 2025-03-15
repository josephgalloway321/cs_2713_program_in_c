#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.c"

int main() {

  srand(time(NULL)); // Seed using the current time

  int rounds = 0;
  int p1_total = 0;  // Initialize total points for player 1
  int p2_total = 0;  // Initialize total points for player 2

  printf("Enter the number of rounds: ");
  scanf("%d", &rounds);
  printf("\n");
  
  for (int i = 1; i <= rounds; i++) {
    enum CHAMPION c1 = createChampion();  // Decide champion for player 1
    enum CHAMPION c2 = createChampion();  // Decide champion for player 2
    int c1_points = getChampionPoints(c1);
    int c2_points = getChampionPoints(c2);

    printf("ROUND %d\n", i);
    printf("----------\n");
    playRound(&p1_total, &p2_total, c1, c1_points, c2, c2_points);
    printf("\n");
  }

  printf("GAME OVER!!\n");
  if (p1_total > p2_total) {
    printf("P1 Won\n\n");
  }
  else if (p1_total < p2_total) {
    printf("P2 Won\n\n");
  }
  else {
    printf("TIE\n\n");
  }

  return 0;
}