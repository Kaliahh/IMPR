# include "opg-5.3.h"

/* Navn: Ane Søgaard Jørgensen
 * Dato: 12/10-2018
 * Beskrivelse: https://bit.ly/2CcZIjV
 */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int main(void) {

  int result = 0;

  /* Finder 2 primtal som giver et lige heltal i, op til et tal*/
  for (int i = 6; i <= 2000000; i++) {

    /* En kontrol for at sikre at der ikke bliver fundet mere end 2 primtal per helttal */
    result = 0;

    /* Checker om det step programmet er kommet til er lige */
    if (is_even(i) == 1) {

      /* Går fra i til 0 */
      for (int j = i - 1; j > 0; j--) {

        /* Break tilbage til det første for-loop */
        if (result == 1) {
          break;
        }

        /* Checker om steppet er et primtal */
        if (is_prime(j) == 1) {

          /* Går fra 0 til j */
          for (int k = 1; k <= j; k++) {

            /* Breaker tilbage til det første for-loop */
            if (result == 1) {
              break;
            }

            /* Checker om steppet er et primtal */
            if (is_prime(k) == 1) {

              /* Chekcer om de to primtals sum giver i, det originale tal */
              if (j + k == i) {
                /* Print resultatet hvis det gør */
                printf("i: %5d, j: %5d, k: %5d\n", i, j, k);
                /* Nu er der blevet fundet 2 primtal for heltallet, så nu kan programmet gå videre til næste i */
                result = 1;
              }

              /* Breaker tilbage til det første for-loop */
              if (result == 1) {
                break;
              }
            }
          }
        }
      }
    }
  }
  return 0;
}

/* Udregner om et tal er lige eller ulige */
int is_even(int a) {

  if (a % 2 == 0) {
    return 1;
  }

  else {
    return 0;
  }
}
