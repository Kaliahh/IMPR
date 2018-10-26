/* Navn: Ane Søgaard Jørgensen
 * Dato: 26/10-2018
 * Beskrivelse: Dette program er en test, for at scanne tal ind i et array
 */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>

int main(void) {

  int n;

  printf("Input size of array: ");
  scanf(" %d", &n);

  int a[n];

  printf("Input %d numbers: ", n);
  for (int i = 0; i < sizeof(a) / sizeof(int); i++) {
    scanf(" %d", &a[i]);
  }

  for (int j = 0; j < sizeof(a) / sizeof(int); j++) {
    printf("%d: %d\n", j, a[j]);
  }

  return 0;
}
