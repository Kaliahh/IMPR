/* Navn: Ane Søgaard Jørgensen
 * Dato: 17/10-2018
 * Beskrivelse: En simpel lommeregner
 */

# include <stdio.h>
# include <string.h>
# include <math.h>

void calc(double *, double, char *);

int main(void) {

  char operator;
  double operant = 0.0, acc = 0.0;

  while (strcmp(&operator, "q") != 0) {

    /* Prompts the user to input an operator and operant */
    printf("Input an operator and an operant: ");
    scanf(" %c%lf", &operator, &operant);

    /* Checks if the operator is q, and quits if it is */
    if (strcmp(&operator, "q") == 0) {
      return 0;
    }

    /* Calculates stuff */
    calc(&acc, operant, &operator);

    printf("Result so far: %lf\n\n", acc);

  }

  return 0;
}

void calc(double *pacc, double operant, char *operator) {

  if (*operator == '+') {
    *pacc += operant;
  }

  else if (*operator == '-') {
    *pacc -= operant;
  }

  else if (*operator == '*') {
    *pacc *= operant;
  }

  else if (*operator == '/') {
    *pacc /= operant;
  }

  else if (*operator == '^') {
    *pacc += pow(*pacc, operant);
  }
}
