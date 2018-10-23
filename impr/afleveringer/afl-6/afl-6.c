/* Navn: Ane Soegaard Joergensen
 * Dato: 17/10-2018
 * Beskrivelse: Opg. 17 side 334. Find arealet under en kurve.
 */

# include <stdio.h>
# include <math.h>

/* Prototyper */
double trap(double, double, int, double(*f)(double));
double sub_height(double, double, int);
double sum(double, double, double, double(*f)(double));
double g(double);
double h(double);


int main(void) {

  double a, b, area;
  int n, SENTINEL = 0;
  char choice;

  /* Initierer pointer til en funktion */
  double (*fP)(double);


  /* Her starter loopet, saa programmet ikke stopper efter hver beregning af arealet */
  while(SENTINEL != 1) {

    /* Prompter brugeren for hvilken funktion de vil koere */
    printf("Which function do you want to run? (g/h): ");
    scanf(" %c", &choice);

    /* Checker hvilken funktion brugeren vil koere, og saetter pointeren til den funktion */
    if (choice == 'g') {
      printf("(Try a = 0, b = 3.14159)\n");
      fP = &g;
    }

    else if (choice == 'h') {
      printf("(Try a = -2, b = 2)\n");
      fP = &h;
    }

    /* Hvis brugeren ikke inputter g eller h, er det en fejl */
    else if (choice != 'g' || choice != 'h') {
      printf("Invalid input\n");
      return 0;
    }

    /* Prompter brugeren for 2 tal, a og b, som er graenserne for integralet */
    printf("\nInput 2 numbers, a and b, for the limits of the area: ");
    scanf(" %lf%lf", &a, &b);

    /* Prompter brugeren for hvor mange subintervals der skal regnes med */
    printf("\nInput subintervals (Higher inputs = more precise results): ");
    scanf(" %d", &n);

    /* Beregner arealet */
    area = trap(a, b, n, *fP);

    /* Printer arealet */
    printf("Area: %lf\n\n", area);

    /* Beder brugeren vaelge mellem at afslutte, eller fortsaette */
    printf("Do you want to quit? (y/n): ");
    scanf(" %c", &choice);

    if (choice != 'n') {
      printf("- - - - - - - - - - - - - - - - - - -\n");
      SENTINEL = 1;
    }
  }

  return 0;
}

/* Udregner arealet */
/* A = (h / 2) * (f(a) + f(b) + 2 * (SUM f(x_i))) */
double trap(double a, double b, int n, double (*f)(double)) {

  double h, area;

  /* Beregner hoejden af subintervallerne med sub_height funktionen */
  h = sub_height(a, b, n);

  /* Beregner arealet */
  area = (h / 2) * ((*f)(a) + (*f)(b) + 2 * sum(a, b, h, *f));

  return area;
}

/* Beregner hoejden af subintervallerne */
double sub_height(double a, double b, int n) {

  return (b - a) / n;
}

/* Beregner summen */
double sum(double a, double b, double h, double (*f)(double)) {

  double sum = 0;

  /* Beregner summen fra den nedre graense til den oevre, og gaar h op for hver gennemgang */
  for (double i = a; i < b; i += h) {
    sum += (*f)(i);
  }

  return sum;
}

/* Foerste funktion, med forskriften g(x) = x^2 * sin(x) */
double g(double x) {

  return (x * x) * sin(x);
}

/* Anden funktion, med forskriften h(x) = sqrt(4 - x^2) */
double h(double x) {

  //return sqrt(4 - (x * x));
  return 2 * x;
}
