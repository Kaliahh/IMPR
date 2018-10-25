/* Navn: Ane Søgaard Jørgensen
 * Dato: 25/10-2018
 * Beskrivelse: Mit tag på en merge sort algoritme
 */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <time.h>

void mergeSort(int *, int, int);
void merge(void);
void arrayRandomizer(int *, int);
int elementComp(int *, int, int);
void arrayPrinter(int *, int);

int main(void) {

    time_t t;

    srand((unsigned) time(&t));

    int n = (rand() % 12) + 2;
    int a[n];
    int a_size = sizeof(a) / sizeof(a[0]);

    arrayRandomizer(a, a_size);

    printf("Usorteret array: ");
    arrayPrinter(a, a_size);

    /* Vi giver sorteringsfunktionen et array, et start sted (a[0]),
     * og et slut sted (a_size - 1, da a_size er størrelsen på arrayet,
     * og a_size - 1, er det sidste indeks)
     */
    mergeSort(a, 0, a_size - 1);

    printf("Sorteret array: ");
    arrayPrinter(a, a_size);

  return 0;
}

/* Sorterer arrayet */
void mergeSort(int *a, int v, int h) {

  if (v < h) {
    int m = v + ((h - 1) / 2);

    mergeSort(a, v, m);
    mergeSort(a, m + 1, h);

    merge(a, l, m, r);
  }
}

void merge(void) {

  int i, j, k;
  int

}


/* Funktioner herunder er bare til at teste med */
void arrayRandomizer(int *array, int size) {
  int x;
  int SENTINEL = 0;

  for (int i = 0; i < size; i++) {
    x = (rand() % 200) - 100;

    /* Tester om x allerede findes i arrayet */
    SENTINEL = elementComp(array, size, x);

    /* Hvis værdien for x allerede findes, lægges 1 til, indtil det er anderledes end alt andet */
    while (SENTINEL == 1) {
      ++x;
      SENTINEL = elementComp(array, size, x);
    }

    /* Til sidst tildeles værdien x til array[i] */
    array[i] = x;

  }
}

int elementComp(int *array, int size, int x) {
  for (int i = 0; i < size; i++) {
    /* Returnerer sand hvis der allerede er et tal */
    if (x == array[i]) {
      return 1;
    }
  }
  /* Returnerer falsk hvis værdien af x ikke allerede findes i arrayet */
  return 0;
}

void arrayPrinter(int *array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%2d ", array[i]);
  }
  printf("\n");
}
