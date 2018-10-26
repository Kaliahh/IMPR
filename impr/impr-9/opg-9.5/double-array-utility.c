/* Navn: Ane Søgaard Jørgensen
 * Dato: 26/10-2018
 * Beskrivelse: En test driver til merge sort algoritmer
 */

# include "double-array-utility.h"

/*
int main(void) {
  return 0;
}
*/

void arrayRandomizerD(double *array, int size) {
  double x;
  int SENTINEL = 0;

  for (int i = 0; i < size; i++) {
    x = rand() % 100;

    /* Tester om x allerede findes i arrayet */
    SENTINEL = elementCompD(array, size, x);

    /* Hvis værdien for x allerede findes, lægges 1 til, indtil det er anderledes end alt andet */
    while (SENTINEL == 1) {
      ++x;
      SENTINEL = elementCompD(array, size, x);
    }

    /* Til sidst tildeles værdien x til array[i] */
    array[i] = x;

  }
}

int elementCompD(double *array, int size, int x) {
  for (int i = 0; i < size; i++) {
    /* Returnerer sand hvis der allerede er et tal */
    if (x == array[i]) {
      return 1;
    }
  }
  /* Returnerer falsk hvis værdien af x ikke allerede findes i arrayet */
  return 0;
}

void arrayPrinterD(double *array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%2.1lf ", array[i]);
  }
  printf("\n");
}
