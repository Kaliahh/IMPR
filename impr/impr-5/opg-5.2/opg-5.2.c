# include "opg-5.2.h"

/* Navn: Ane Søgaard Jørgensen
 * Dato: 12/10-2018
 * Beskrivelse: https://bit.ly/2Om8UKo
 */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int main(void) {
  int result, i = 1, j = 1;

  for (i = 1; j <= 100; i++) {
    result = is_prime(i);
    //printf("%d: ", i);
    if (result == 1) {
      printf("Primtal %d: %d\n", j, i);
      j++;
    }

  }


  return 0;
}
