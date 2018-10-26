/* En test driver til int merge sort funktionen */

# include "int-merge-sort.h"
# include "int-array-utility.h"

int main(void) {

    time_t t;

    srand((unsigned) time(&t));

    int n = (rand() % 12) + 2;
    int a[n];
    int a_size = sizeof(a) / sizeof(a[0]);

    arrayRandomizerI(a, a_size);

    printf("Usorteret array[%d]:  ", a_size);
    arrayPrinterI(a, a_size);

    /* Vi giver sorteringsfunktionen et array, et start sted (a[0]),
     * og et slut sted (a_size - 1, da a_size er størrelsen på arrayet,
     * og a_size - 1, er det sidste indeks)
     */
    mergeSortI(a, 0, a_size - 1);

    printf("Sorteret array[%d]:   ", a_size);
    arrayPrinterI(a, a_size);

  return 0;
}
