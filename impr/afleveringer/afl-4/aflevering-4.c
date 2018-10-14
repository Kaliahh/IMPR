/* Navn: Ane Søgaard Jørgensen
 * Dato: 14/10-2018
 * Beskrivelse: https://bit.ly/2yzucJG
 */

# include <stdio.h>
# include <math.h>
# include <string.h>

/* Prototyper */
void solveQuadraticEquation(double, double, double);
double solveDiscriminant(double, double, double);
void findOneRoot(double, double);
void findTwoRoots(double, double, double);

int main(void) {

  double a = 1, b = 1, c = 1;
  char choice[2];

  /* Denne løkke sørger for at programmet kan køres igen og igen, uden at skulle lukke det */
  while (a != 0 || b != 0 || c != 0) {

    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("Dette program finder roedderne til en andengradsligning\n");
    printf("- - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");

    /* Prompter brugeren for 3 tal */
    printf("Indtast 3 tal, a, b og c: ");
    scanf("%lf%lf%lf", &a, &b, &c);

    /* Checker om alle inputs er lig med 0, og stopper løkken hvis det er */
    if (a == 0 && b == 0 && c == 0) {
      printf("Ugyldigt indput\n");
      return 0;
    }

    /* Finder rødderne, hvis der er nogen */
    solveQuadraticEquation(a, b, c);

    /* Prompter brugeren til at fortsætte eller afslutte */
    printf("Vil du foretage en ny beregning? (y/n) ");
    scanf("%s", choice);

    /* Hvis brugeren skriver n, stopper løkken */
    if (strcmp(choice, "n") == 0) {
      return 0;
    }
  }
  return 0;
}

/* Finder rødderne for en andengradsligning */
void solveQuadraticEquation (double a, double b, double c) {

  double discriminant;

  /* Beregner diskriminanten */
  discriminant = solveDiscriminant(a, b, c);

  /* Checker om der ingen rødder er */
  if (discriminant < 0) {
    printf("Ingen roedder\n\n");
  }

  /* Hvis diskriminanten er lig 0, er der 1 rod */
  else if (discriminant == 0) {
    findOneRoot(a, b);
  }

  /* Hvis diskriminanten er større end 0, er der 2 rødder */
  else {
    findTwoRoots(a, b, discriminant);
  }
}

/* Finder diskriminanten for de tre tal */
double solveDiscriminant(double a, double b, double c) {

  double discriminant;

  /* Beregner diskriminanten */
  discriminant = b * b - 4 * a * c;

  return discriminant;
}

/* Finder rodden, hvis diskriminanten er lig 0 */
void findOneRoot(double a, double b) {
  printf("Der er 1 rod: %f\n\n", -b / (2 * a));
}

/* Finder rødderne, hvis diskriminanten er større end 0 */
void findTwoRoots(double a, double b, double discriminant) {
  printf("Der er 2 roedder: %f og %f\n\n",
  (-b + sqrt(discriminant)) / (2 * a),
  (-b - sqrt(discriminant)) / (2 * a));
}
