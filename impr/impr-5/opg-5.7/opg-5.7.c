/* Navn: Ane Søgaard Jørgensen
 * Dato: 12/10-2018
 * Beskrivelse: https://bit.ly/2NF8CsV
 */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "opg-5.7.h"

int main(void) {

  printf("Summen af tallene 1 til 100: %d\n", sum_iter(100));
  printf("Sum formula = %d\n", sum_formula(100));

  return 0;
}
