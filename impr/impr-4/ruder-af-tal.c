# include <stdio.h>

int spaces(int);
int sekskant(int);
int kvadrat_a(int);
int kvadrat_b(int);

int main(void) {
  int i, j, a = 0, input;

  /* Prompter brugeren for input */
  printf("Input an integer: ");
  scanf("%d", &input);

  /* Beregner øverste halvdel af romben */
  for (i = 1; i <= input; i++) {
    spaces(input - a);

    for (j = 1; j <= a; j++) {
      printf("0   ");
    }
    a++;

    //sekskant(input);
    //kvadrat_a(input);

    printf("\n");
  }

  /* Beregner nederste halvdel af romben */
  for (i = 1; i <= input; i++) {
    spaces(input - a);

    for (j = 1; j <= a; j++) {
      printf("0   ");
    }
    a--;

    //sekskant(input);
    //kvadrat_b(input);

    printf("\n");
  }
  printf("\n");

  return 0;
}

/* Laver et bestemt antal mellemrum */
int spaces(int a) {
  int i;

  for (i = 1; i <= a; i++) {
    printf(" ");
  }
}

/* Sekskant illusion */
int sekskant(int a) {
  int i;

  for (i = 1; i <= a; i++) {
    printf("0 ");
  }
}

/* Firkant illusion */
int kvadrat_a(int a) {
  int i;

  for (i = 1; i <= a + a / 4; i++) {
    printf(" _");
  }
}

int kvadrat_b(int a) {
  int i;

  for (i = 1; i <= a + a / 4; i++) {
    printf(" /");
  }
}
