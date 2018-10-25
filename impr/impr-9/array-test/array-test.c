/* Navn: Ane Søgaard Jørgensen
 * Dato: 25/10-2018
 * Beskrivelse: Jeg prøver at finde ud af hvordan arrays fungerer
 */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>
# include <time.h>

int main(void) {

  int x[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  //int x[] = {};
  time_t t;

  srand((unsigned) time(&t));

  /*
  for (int j = 0; j <= 7; j++) {
    x[j] = 0;
  }
  */

  /* Iterativ kontrolstruktur (for loop), der kører op til mængden af elementer i array x, - 1 */
  for (int h = 0; h <= (sizeof(x) / sizeof(int)) - 1; h++) {
    x[h] = h;
  }

  for (int k = 0; k <= 7; k++) {
    printf("x: %d\n", x[k]);
  }

  return 0;
}
