/* Navn: Ane Søgaard Jørgensen
 * Dato: 18/10-2018
 * Beskrivelse: Opgave 15, side 332 i "Problem Solving and Program Design in C, eight edition"
 */

# include <stdio.h>

int main(void) {

  int it = 0;
  double pos_sum = 0, neg_sum = 0, tot_sum = 0;

  /* Prompter brugeren for et antal iterationer programmet skal køre igennem */
  printf("How many iterations?: ");
  scanf("%d", &it);

  /* Udregner den negative del af pi's estimering */
  for (double j = 3.0; j <= it; j += 4.0) {
    neg_sum += -1.0 * (1.0 / j);
  }

  /* Udregner den positive del af pi's estimering */
  for (double i = 5.0; i <= it; i += 4.0) {
    pos_sum += (1.0 / i);
  }

  /* Udregner den totale sum */
  /* Formlen er: pi = 4 * (1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 + 1/13 - 1/15 + ...) */
  tot_sum = 4 * (1 + neg_sum + pos_sum);

  printf("Pi is approximated to: %.8lf\n", tot_sum);

  return 0;
}
