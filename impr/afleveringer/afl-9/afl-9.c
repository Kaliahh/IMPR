/* Navn: Ane Søgaard Jørgensen
 * Dato: 02/11-2018
 * Beskrivelse: Afleveringsopgave 9. Rekursiv og iterativ funktioner, der finder palindromer.
 */

# include <stdio.h>
# include <string.h>

# define MAX_LEN 30

char *is_palindrome_iter(const char*);
char *is_palindrome_rec(const char *, int, int);

int main(void) {

  int n;
  char str[MAX_LEN];

  /* Prompter brugeren for et ord */
  printf("Input et ord: ");
  fgets(str, MAX_LEN, stdin);
  printf("\n");

  /* "- 2", er fordi \0 ikke skal tælles med */
  n = strlen(str) - 2;

  /* Kalder funktionerne */
  printf("Rekursivt: %s\n", is_palindrome_rec(str, 0, n));
  printf("Iterativt: %s\n", is_palindrome_iter(str));

  return 0;
}

/* Checker om en tekststreng er et palindrom, iterativt */
char *is_palindrome_iter(const char *array) {
  int SENTINEL = 0;
  int j = strlen(array) - 2;
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
char *is_palindrome_rec(const char *array, int i, int j) {
  //j = strlen(array) - 2;
  //i = 0;

  /* Bliver ved på samme måde som den iterative */
  if (i > j) {
    return "Ja!";
  }

  else if (array[i] != array[j]) {
    return "Nej";
  }

  /* Kalder sig selv, hvis de to bogstaver er ens,
   * med indekser der er flyttet et hak tættere på midten af tekststrengen */
  else if (array[i] == array[j]) {
    is_palindrome_rec(array, ++i, --j);
  }
}
