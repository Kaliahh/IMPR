/* Navn: Ane Søgaard Jørgensen
 * Dato: 02/11-2018
 * Beskrivelse: Afleveringsopgave 9. Rekursiv og iterativ funktioner, der finder palindromer.
 */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>

# define MAX_LEN 30

int is_palindrome_rec(const char *, int, int);

int main(void) {

  int n = 0, size;
  char pal[] = "YAY";

  size = 3;

  n = is_palindrome_rec(pal, 0, size - 1);

  if (n == 1) {
    printf("Yay!\n");
  }

  else if (n == -1) {
    printf("Nay\n");
  }

  return 0;
}


int is_palindrome_rec(const char *array, int i, int j) {
  printf("i: %c\n", array[i]);
  printf("j: %c\n", array[j]);
  printf("\n");

  if (i > j) {
    return 1;
  }

  else if (array[i] == array[j]) {
    printf("Hey!\n");
    is_palindrome_rec(array, i + 1, j - 1);
  }

  else if (array[i] != array[j]) {
    return -1;
  }
}
