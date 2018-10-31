/* Navn: Ane Søgaard Jørgensen
 * Dato: 31/10-2018
 * Beskrivelse: Opg 10.3 http://people.cs.aau.dk/~normark/impr-c/strings-extra-opgaver-slide-exercise-1.html
 */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>

# define MAX_INPUT 20
# define MAX_OUTPUT 25

void arrayFiller(char *, int);
char *pluralizer(char *, int, char *, int);
void stringPrinter(char *, int);

int main(void) {

  char *noun = (char *)malloc(MAX_INPUT * sizeof(char));
  char *p_noun = (char *)malloc(MAX_OUTPUT * sizeof(char));

  /* Fylder arrayet med \0 */
  arrayFiller(noun, MAX_INPUT);

  fgets(noun, MAX_INPUT, stdin);

  p_noun = pluralizer(noun, strlen(noun), p_noun, MAX_OUTPUT);

  /* Printer stringen */
  stringPrinter(noun, MAX_INPUT);

  printf("The plural of %s is %s\n", noun, p_noun);

  return 0;
}

/* Fylder et array med \0 */
void arrayFiller(char *array, int n) {
  for (int i = 0; i < n; i++) {
    array[i] = '\0';
  }
}

char *pluralizer(char *noun, int n, char *p_noun, int m) {

  int i = n - 2;

  strcpy(p_noun, noun);

  if (noun[i] == 'y') {
    strcpy(p_noun + i - 2, "ies");
  }

  else if(noun[i] == 's' ||
          noun[i - 1] == 'c' && noun[i] == 'h' ||
          noun[i - 1] == 's' && noun[i] == 'h') {
    strcpy(p_noun + i + 1, "es");
  }

  else {

  }

  return p_noun;
}

/* Printer et array */
void stringPrinter(char *array, int n) {
  for (int i = 0; i < n; i++) {
    printf("%c", array[i]);
  }
  //printf("\n");
}
