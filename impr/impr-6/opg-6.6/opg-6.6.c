# include "opg-6.6.h"

/* Navn: Ane Søgaard Jørgensen
 * Dato: 17/10-2018
 * Beskrivelse: Valutaomregner
 */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>

void exchange(int, double *, double *, double *, double *);

/* 1 dollar = 0.89 euro = 6.66 kroner = 66.43 rubler = 119.9 yen */

int main(void) {
  double e, k, r, y;

  for (int i = 1; i <= 100; i++) {
    exchange(i, &e, &k, &r, &y);
    printf("%3d dollar(s) | %7.2f euro| %7.2f krone(r)| %7.2f ruble(r)| %7.2f yen\n",
    i, e, k, r, y);
  }

  return 0;
}

void exchange (int dollar, double *pe, double *pk, double *pr, double *py) {

  *pe = dollar * 0.89;
  *pk = dollar * 6.66;
  *pr = dollar * 66.43;
  *py = dollar * 119.9;

}
