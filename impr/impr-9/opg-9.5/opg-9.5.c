/* Navn: Ane Søgaard Jørgensen
 * Dato: 26/10-2018
 * Beskrivelse: Opg 9.5, http://people.cs.aau.dk/~normark/impr-c/arrays-opgaver-slide-exercise-3.html
 */

# include <stdio.h>
# include <stdlib.h>
# include "double-array-utility.h"

int qComparator(const void *, const void *);

int main(void) {

  time_t t;

  srand((double) time(&t));

  int n = 100;
  double *a = malloc(n * sizeof(*a));

  if (a == NULL) {
    printf("Kunne ikke allokere nok hukommelse. Farvel\n");
    exit(EXIT_FAILURE);
  }

  arrayRandomizerD(a, n);

  for (int i = 0; i < n; i++) {
    a[i] *= 0.9;
  }

  printf("Usorteret array[%d]: ", n);
  arrayPrinterD(a, n);
  printf("\n");

  qsort(a, n, sizeof(double), qComparator);

  printf("Sorteret array[%d]: ", n);
  arrayPrinterD(a, n);

  return 0;
}

int qComparator(const void *a, const void *b) {
  double *tp1 = (double*)a, *tp2 = (double*)b;

  return *tp1 - *tp2;
}
