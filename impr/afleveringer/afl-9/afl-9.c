/* Navn: Ane Søgaard Jørgensen
 * Dato: 02/11-2018
 * Beskrivelse: Afleveringsopgave 9. Rekursiv og iterativ funktioner, der finder palindromer.
 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAX_LEN 30

char *is_palindrome_iter(const char *);
char *is_palindrome_rec(const char *);

int main(void) {

  char str[MAX_LEN];

  /* Prompter brugeren for et ord */
  printf("Input et ord[MAX %d]: ", MAX_LEN);
  scanf("%s", str);
  printf("\n");

  /* Kalder funktionerne */
  printf("Rekursivt: %s\n", is_palindrome_rec(str));
  printf("Iterativt: %s\n", is_palindrome_iter(str));

  return 0;
}

/* Checker om en tekststreng er et palindrom, iterativt */
char *is_palindrome_iter(const char *array) {
  int SENTINEL = 0;
  int j = strlen(array) - 1;
  int i = 0;

  /* Bliver ved, indtil array[i] og array[j] ikke er det samme,
   * eller hvis i bliver større end j */
  while (SENTINEL == 0) {

    if (i > j) {
      return "Ja!";
    }

    else if (array[i] != array[j]) {
      return "Nej";
      SENTINEL = 1;
    }

    else {
      i++; j--;
    }
  }
}

/* Checker om en tekststreng er et palindrom, rekursivt */
char *is_palindrome_rec(const char *array) {
  int j = strlen(array) - 1;
  int i = 0;
  char *temp = malloc(strlen(array) * sizeof(*temp));

  /* Ved lige antal bogstaver i palindromet, bliver j -1.
   * Ved ulige antal bogstaver i palindromet, bliver j 0.
   * i vil blive 0 hver gang (hvis tekstrengen er et palindom) */
  if (i >= j) {
    return "Ja!";
  }

  else if (array[i] != array[j]) {
    return "Nej";
  }

  else if (array[i] == array[j]) {
    /* Kopierer tekstrengen fra array, over i temp, uden det første og det sidste bogstav */
    strncpy(temp, array + 1, j - 1);
    temp[j] = '\0';
    return is_palindrome_rec(temp);
  }
}
