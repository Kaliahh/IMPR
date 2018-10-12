# include "opg-5.7.2.h"

/* Navn: Ane Søgaard Jørgensen
 * Dato: 12/10-2018
 * Beskrivelse: https://bit.ly/2NF8CsV
 */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int population_projection(int, double, int);

int main(void) {

  double ann_growth = 1.1;
  int population = 9870, limit = 300000, years;

  years = population_projection(population, ann_growth, limit);

  printf("Number of years: %d\n", years);

  return 0;
}

int population_projection(int population, double ann_growth, int limit) {

  int i;

  for (i = 1; population < limit; i++) {
    population *= ann_growth;
    printf("%d\n", population);
  }
  return i;
}
