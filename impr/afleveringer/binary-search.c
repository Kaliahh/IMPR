/* Navn: Ane Søgaard Jørgensen
 * Dato: 25/10-2018
 * Beskrivelse: En binary search, der kan bruges i andre programmer
 */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>
# include <time.h>

void bsearch(int *);

int main(void) {
  int x[10];

  time_t t;

  srand((unsigned) time(&t));

  /* Sætter arrayet op */
  for (int i = 0; i < sizeof(x) / sizeof(int); i++) {
    x[i] = rand % 100;
  }

  bsearch(&x);

}

void bsearch(int *x) {

  int bottom = 0, top = sizeof(x) / sizeof(int);
  int found = 0, middle;

  while (bottom < top && found == 0) {
    middle = x[(sizeof(x) / sizeof(int)) / 2];

    if (x[middle] )
  }



  return 0;
}
