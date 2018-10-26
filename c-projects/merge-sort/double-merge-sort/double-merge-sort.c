/* Navn: Ane Søgaard Jørgensen
 * Dato: 25/10-2018
 * Beskrivelse: Mit tag på en merge sort algoritme
 */

# include "double-merge-sort.h"

/* Sorterer arrayet */
void mergeSortD(double *a, int f, int l) {

  /* Hvis det første indeks er mindre end det sidste i arrayet eller subarrayet */
  if (f < l) {
    /* Find midten */
    int m = f + ((l - f) / 2);
    //printf("m: %d\n", m);

    /* Kalder mergeSortD (Recursive) på den første halvdel og den næste halvdel */
    mergeSortD(a, f, m);
    mergeSortD(a, m + 1, l);

    /* Forener delene, indtil der ikke er flere */
    mergeD(a, f, m, l);
  }
}

/* Forener halvdelene af arrayet */
void mergeD(double *a, int f, int m, int l) {

  int i, j, k;

  /* Initierer to mængder, til de to midlertidige arrays.
   * Den første mængde er fra det første indeks til det midterste.
   * Den anden mængde er fra midten til det sidste indeks */
  int n = (m - f) + 1;
  int h = l - m;

  /* Initialiserer de to midlertidige arrays, med de respektive mængder */
  int F[n], L[h];

  /* Kopierer elementerne fra det originale array a[], opdelt, over i de to midlertidige arrays T1[] og T2[] */
  for (i = 0; i < n; i++) {
    F[i] = a[f + i];
  }
  for (j = 0; j < h; j++) {
    L[j] = a[m + 1 + j];
  }

  /* Forener de to subarrays til et forenet array */
  i = 0; /* Første indeks i det første midlertidige array */
  j = 0; /* Første indeks i det andet midlertidige array */
  k = f; /* Det indeks i det forenede vi er kommet til */

  while (i < n && j < h) {
    if (F[i] <= L[j]) {
      a[k] = F[i];
      i++;
    }

    else {
      a[k] = L[j];
      j++;
    }
    k++;
  }

  /* Kopierer de resterende elementer af F[] over i a[],
   * hvis der er flere tilbage. Disse må nødvendigvis være sorterede */
  while (i < n) {
    a[k] = F[i];
    i++;
    k++;
  }

  /* Gør det samme med elementer fra L[] */
  while (j < h) {
    a[k] = L[j];
    j++;
    k++;
  }
}
