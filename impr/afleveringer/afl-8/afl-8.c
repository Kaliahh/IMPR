/* Navn: Ane Søgaard Jørgensen
 * Dato: 30/10-2018
 * Beskrivelse: Opgave 1 side 490 (Afleveringsopgave 8).
 * Tager en kode af denne type ABC1234D56
 * Laver det til ABC 1234 D56
 */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>
# include <ctype.h>

void identifier(char *, int, char*, char*, char*);
void displayInfo(char *, char *, char *);
void scanCode(char *, int);

int main(void) {

  char code[50] = "ABC1234D56", warehouse[50], *id, *qualifers;
  int n = strlen(code);

  identifier(code, n, warehouse, id, qualifers);

  return 0;
}


void identifier(char *code, int n, char* warehouse, char* id, char* qualifers) {

  int i = 0;

  for (int i = 0; i < n; i++) {

    if (isdigit(i) == 1) {

      for (int j = 0; j <= i; j++) {
        warehouse[j] = code[j];
      }
    }

  }

  displayInfo(warehouse, id, qualifers);
}

/* Printer resultatet til terminalen */
void displayInfo(char *warehouse, char *id, char *qualifers) {

  printf("Warehouse: %s\n", warehouse);
  printf("Product ID: %s\n", id);
  printf("Qualifers: %s\n", qualifers);
}

/*
void scanCode(char *code, int n) {

  for (int i = 0; i <= n; i++) {
    scanf("%c", &code[i]);
  }
}
*/
