/* En test driver til double merge sort funktionen */

# include "double-merge-sort.h"
# include "double-array-utility.h"

int main(void) {

    time_t t;

    srand((unsigned) time(&t));

    int n = (rand() % 12) + 2;
    double a[n];
    int a_size = sizeof(a) / sizeof(a[0]);

    arrayRandomizerD(a, a_size);

    printf("Usorteret array[%d]:  ", a_size);
    arrayPrinterD(a, a_size);

    /* Vi giver sorteringsfunktionen et array, et start sted (a[0]),
     * og et slut sted (a_size - 1, da a_size er størrelsen på arrayet,
     * og a_size - 1, er det sidste indeks)
     */
    mergeSortD(a, 0, a_size - 1);

    printf("Sorteret array[%d]:   ", a_size);
    arrayPrinterD(a, a_size);

  return 0;
}
