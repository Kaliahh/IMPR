# include "opg-5.3.h"

/* Navn: Ane Søgaard Jørgensen
 * Dato: 12/10-2018
 * Beskrivelse: https://bit.ly/2CcZIjV
 */

# include <stdio.h>
# include <time.h>

int main(void) {

  //double time_spent;

  clock_t begin = clock();

  int result = 0;

  FILE * fP;

  fP = fopen("file.txt", "a");

  /* Finder 2 primtal som giver et lige heltal i, op til et tal*/
  for (int i = 100; i <= 20000; i += 2) {
    //printf("i: %d\n", i);

    /* Går fra i - 1 til 0 */
    for (int j = i - 1; j > 0; j -= 2) {
      //printf("j: %d\n", j);

      /* Hvis j rammer 1, er der sket en fejl */
      if (j == 1) {
        printf("Error\n");
        return 0;
      }

      /* Checker om steppet er et primtal */
      if (is_prime(j) == 1) {

        /* Går fra 0 til j */
        for (int k = 1; k <= j; k += 2) {
          //printf("k: %d\n", k);

          /* Det andet primtal behøver ikke være større end halvdelen af det første.
           * Dette tal kunne måske være større, men det virker i forvejen ikke så godt for små heltal.
           */
          if (k > j / 2) {
            break;
          }

          /* Checker om steppet er et primtal */
          if (is_prime(k) == 1) {

            /* Chekcer om de to primtals sum giver i, det originale tal */
            if (j + k == i) {
              /* Print resultatet hvis det gør */


              if ((j + k) % 1000 == 0) {
                fprintf(fP, "i: %6d, j: %6d, k: %6d\n", i, j, k);
              }

              //printf("i: %6d, j: %6d, k: %6d\n", i, j, k);

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
      /* Break tilbage til det første for-loop */
      if (result == 1) {
        break;
      }
    }
  /* En kontrol for at sikre at der ikke bliver fundet mere end 2 primtal per helttal */
  result = 0;
  }

  printf("You did it!\n");
  clock_t end = clock();

  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Time: %f\n", time_spent);

  return 0;
}
