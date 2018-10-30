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

void identifier(char *, char*, char*, char*);
void display(char *, char *, char *);

int main(void) {

  char code[] = "ABC1234D56", *warehouse, *id, *qualifers;



  identifier(code, warehouse, id, qualifers);


  return 0;
}


void identifier(char *code, char* warehouse, char* id, char* qualifers) {

  int i = 0;

  while (SENTINEL == 0) {
    if (isdigit(code[i]) == )
  }

  display(warehouse, id, qualifers);
}

/* Printer resultatet til terminalen */
void display(char *warehouse, char *id, char *qualifers) {

  printf("Warehouse: %s\n", warehouse);
  printf("Product ID: %s\n", id);
  printf("Qualifers: %s\n", qualifers);

}
