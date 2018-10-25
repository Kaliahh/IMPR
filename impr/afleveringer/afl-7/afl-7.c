/* Navn: Ane Søgaard Jørgensen
 * Dato: 25/10-2018
 * Beskrivelse: Afleveringsopgave 7, side 471-472 opgave 11
 */

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <assert.h>

# define MINIMUM_SIZE 2

void arrayRandomizer(double *, int);
void arrayPrinter(double *, int);
void mergeArrays(double *, double *, double *, int, int, int);
void merger(double *, double *, double *, int, int);
int comparator(const void *a, const void *b);

int main(void) {

  /* Seeder random generatoren */
  time_t t;
  srand((double) time(&t));

  /* Initialiserer de to arrays med et tilfældigt antal subscripts */
  int n = (rand() % 12) + MINIMUM_SIZE;
  int m = (rand() % 12) + MINIMUM_SIZE;
  double x[n], y[m];

  /* Initialiserer et tomt array, og størrelserne på de 3 arrays */
  double merged[n + m];
  int xsize, ysize, mergedsize;

  printf("\nDette program forener to sortede arrays, til et samlet sorteret array\n\n");

  /* Finder størrelsen af de to arrays */
  xsize = sizeof(x) / sizeof(double);
  ysize = sizeof(y) / sizeof(double);
  mergedsize = sizeof(merged) / sizeof(double);

  /* Initialiserer de to arrays, med tilfældige tal */
  arrayRandomizer(x, xsize);
  arrayRandomizer(y, ysize);

  /* Sorterer array x og y, fra mindst til størst */
  qsort(x, xsize, sizeof(double), comparator);
  qsort(y, ysize, sizeof(double), comparator);

  /* Printer de sorterede arrays */
  printf("Sorterede arrays\n");
  printf("x: ");
  arrayPrinter(x, xsize);

  printf("y: ");
  arrayPrinter(y, ysize);
  printf("\n");

  /* Forener de to arrays, så elementerne er sorterede fra mindst til størst */
  mergeArrays(x, y, merged, xsize, ysize, mergedsize);

  printf("Forenet array\n");
  arrayPrinter(merged, mergedsize);

  return 0;
}

/* Tildeler tilfældige tal til alle subscripts i det givne array */
void arrayRandomizer(double *array, int size) {
  for (int i = 0; i < size; i++) {
    array[i] = rand() % 100;
  }
}

/* Printer alle værdier i det givne array */
void arrayPrinter(double *array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%.0lf ", array[i]);
  }
  printf("\n");
}

/* Forener to sorterede arrays */
void mergeArrays(double *x, double *y, double *merged, int xsize, int ysize, int mergedsize) {

  /* Asserterer om de givne arrays er sorterede */
  assert(x[0] < x[xsize - 1]);
  //assert(x[xsize - 1] > x[xsize - 2]);
  assert(y[0] < y[ysize - 1]);
  //assert(y[ysize - 1] > y[ysize - 2]);

  int decider = (xsize > ysize) ? 1 : (xsize == ysize) ? 0 : -1;

  if (decider == 1) {
    merger(x, y, merged, xsize, mergedsize);
  }
  else if (decider == -1) {
    merger(y, x, merged, ysize, mergedsize);
  }
  else {
    merger(x, y, merged, xsize, mergedsize);
  }
}

/* Forener de sorterede arrays */
void merger(double *a, double *b, double *merged, int size, int mergedsize) {

  for (int i = 0; i < mergedsize; i++) {
    merged[i] = a[i];
    merged[i + size] = b[i];
    printf("size: %lf\n", merged[i + size]);
  }
  
}

/* Sammeligner de to værdier, og returnerer en værdi til qsort baseret på forholdet */
int comparator(const void *a, const void *b) {
  double *tp1 = (double*)a,
         *tp2 = (double*)b;

  if (*tp1 < *tp2) {
    return -1;
  }

  else if (*tp1 > *tp2) {
    return 1;
  }

  else {
    return 0;
  }
}
