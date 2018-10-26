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
int elementComp(double *, int, double);
void arrayPrinter(double *, int);
int mergeArrays(double *, double *, double *, int, int, int);
int qComparator(const void *a, const void *b);

int main(void) {

  /* Seeder random generatoren til brug i initialisering af arrays*/
  time_t t;
  srand((double) time(&t));

  /* Initialiserer de to arrays med et "tilfældigt" antal elementer */
  int n = (rand() % 12) + MINIMUM_SIZE;
  int m = (rand() % 12) + MINIMUM_SIZE;
  double x[n], y[m];

  /* Initialiserer et merged array, og størrelserne på de 3 arrays */
  double merged[n + m];
  int xsize, ysize, mergedsize;
  int duplicate = 0;

  printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
  printf("Dette program forener to sorterede arrays, til et samlet sorteret array\n");
  printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");

  /* Finder størrelsen af de tre arrays */
  xsize = sizeof(x) / sizeof(double);
  ysize = sizeof(y) / sizeof(double);
  mergedsize = sizeof(merged) / sizeof(double);

  /* Initialiserer de to arrays x og y, med "tilfældige" tal */
  arrayRandomizer(x, xsize);
  arrayRandomizer(y, ysize);

  /* Sorterer array x og y, fra mindst til størst.
   * qsort er lidt "ulovlig", men fordi der genereres tilfældige arrays,
   * i stedet for predefinerede arrays der allerede er sorterede manuelt,
   * mener jeg at dette er okay */
  qsort(x, xsize, sizeof(double), qComparator);
  qsort(y, ysize, sizeof(double), qComparator);

  /* Printer de sorterede arrays */
  printf("Sorterede arrays\n");
  printf("x[%d]: ", xsize);
  arrayPrinter(x, xsize);

  printf("y[%d]: ", ysize);
  arrayPrinter(y, ysize);
  printf("\n");

  /* Forener de to arrays, så elementerne er sorterede fra mindst til størst.
   * Hvis der forekommer flere af de samme værdier i de to arrays,
   * bliver antallet returneret til duplicate */
  duplicate = mergeArrays(x, y, merged, xsize, ysize, mergedsize);

  /* Printer det forenede array, og stopper tidligere end længden af mergedsize,
   * hvis der var duplicates mellem de to arrays */
  printf("Forenet array[%d]\n", mergedsize - duplicate);
  arrayPrinter(merged, mergedsize - duplicate);

  return 0;
}

/* Forener to sorterede arrays */
int mergeArrays(double *x, double *y, double *merged, int xsize, int ysize, int mergedsize) {

  int i = 0, j = 0, k = 0, duplicate = 0;
  int SENTINEL = 0;

  /* Forener de to arrays x[] og y[], i et samlet array merged[] */
  while (i < xsize && j < ysize) {

    if (x[i] == y[j]) {
      merged[k] = x[i];
      duplicate++;
      i++;
      j++;
    }

    else if (x[i] < y[j]) {

      /* Tester om værdien i x[i] allerede forekommer i det forenede array */
      //SENTINEL = elementComp(merged, mergedsize, x[i]);

      /* Hvis værdien af x[i] allerede eksisterer, springes x[i] over,
       * og duplicate tælles op med 1 */
      /*if (SENTINEL == 1) {
        duplicate++;
        i++;
        SENTINEL = 0;
        break;
      }*/
      merged[k] = x[i];
      i++;
    }

    else {

      /* Samme fremgangsmåde her, bare med y[j] i stedet for x[i] */
      /*SENTINEL = elementComp(merged, mergedsize, y[j]);

      if (SENTINEL == 1) {
        duplicate++;
        j++;
        SENTINEL = 0;
        break;
      }*/
      merged[k] = y[j];
      j++;
    }

    k++;
  }

  /* Kopierer de resterende elementer af x[] over i merged[], hvis der er flere tilbage.
   * Disse elementer må nødvendigvis være større end alle de foregående tal,
   * så de kan bare kopieres over */
  while (i < xsize) {
    merged[k] = x[i];
    i++;
    k++;
  }

  /* Gør det samme med elementer fra y[] */
  while (j < ysize) {
    merged[k] = y[j];
    j++;
    k++;
  }

  /* Returnerer antallet af duplicates til main funktionen, til brug i printf */
  return duplicate;
}

/* Tildeler tilfældige tal mellem -100 og 100 til alle subscripts i det givne array */
void arrayRandomizer(double *array, int size) {
  double x;
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

/* Sammenligner x med alle elementer i et array,
 * for at se om værdien af x forekommer allerede */
int elementComp(double *array, int size, double x) {
  for (int i = 0; i < size; i++) {
    /* Returnerer sand hvis der allerede er et tal */
    if (x == array[i]) {
      return 1;
    }
  }
  /* Returnerer falsk hvis værdien af x ikke allerede findes i arrayet */
  return 0;
}

/* Printer alle værdier i det givne array */
void arrayPrinter(double *array, int size) {
  for (int i = 0; i < size; i++) {
    printf("%2.1lf ", array[i]);
  }
  printf("\n");
}

/* Sammeligner de to værdier, og returnerer en værdi til qsort baseret på forholdet */
int qComparator(const void *a, const void *b) {
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
