# include <stdio.h>


int rombe(int);
int spaces(int);
int sekskant(int);
int kvadrat_a(int);
int kvadrat_b(int);

int main(void) {
  int input;

  /* Prompter brugeren for input */
  printf("Input an integer: ");
  scanf("%d", &input);

  rombe(input);

  return 0;
}

int rombe(int input) {

  int a = 0;

  /* Beregner øverste halvdel af romben */
  for (int i = 1; i <= input; i++) {
    spaces(input - a);

    for (int j = 1; j <= a; j++) {
      printf("0 ");
    }
    a++;

    //sekskant(input);
    //kvadrat_a(input);

    printf("\n");
  }

  /* Beregner nederste halvdel af romben */
  for (int i = 1; i <= input; i++) {
    spaces(input - a);

    for (int j = 1; j <= a; j++) {
      printf("0 ");
    }
    a--;

    //sekskant(input);
    //kvadrat_b(input);

    printf("\n");
  }
  printf("\n");

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
