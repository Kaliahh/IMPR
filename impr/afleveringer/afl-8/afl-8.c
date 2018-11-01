/* Navn: Ane Søgaard Jørgensen
 * Dato: 30/10-2018
 * Beskrivelse: Opgave 1 side 490 (Afleveringsopgave 8).
 * Tager en kode af denne type ABC1234D56
 * Laver det til ABC 1234 D56
 */

# include <stdio.h>
# include <string.h>
# include <ctype.h>

/* En maks længde på tekststrengen */
# define MAX_LENGTH 20

void identifier(char *, int, char*, char*, char*);
void arrayFiller(char *, int);
void displayInfo(char *, char *, char *);
void scanCode(char *, int);

int main(void) {

  char code[MAX_LENGTH], warehouse[MAX_LENGTH], id[MAX_LENGTH], qualifiers[MAX_LENGTH];

  /* Prompter brugeren for en tekststreng */
  printf("Input code [CAPS][Max %d]: ", MAX_LENGTH);
  fgets(code, MAX_LENGTH, stdin);
  printf("\n");

  /* Fylder de 3 arrays med \0 tegn */
  arrayFiller(warehouse, MAX_LENGTH);
  arrayFiller(id, MAX_LENGTH);
  arrayFiller(qualifiers, MAX_LENGTH);

  /* Identificerer warehouse, id og qualifiers */
  identifier(code, strlen(code), warehouse, id, qualifiers);

  /* Printer warehouse, id og qualifiers */
  displayInfo(warehouse, id, qualifiers);

  return 0;
}

/* Identificerer warehouse, id og qualifiers */
void identifier(char *code, int str_len, char* warehouse, char* id, char* qualifiers) {

  int WAREHOUSE = 0, ID = 0;
  int i = 0, o = 0;

  /* Checker for warehouse, op til det næste tal */
  while (WAREHOUSE == 0) {

    /* Checker om den (int) typecastede værdi af code[i] er mellem 65 og 90 (Store bogstaver, ASCII) */
    if ((int) code[i] >= 65 && (int) code[i] <= 90) {
      warehouse[i] = code[i];
      i++;
    }

    /* WAREHOUSE flag sættes til 1, så det næste loop sættes i gang.
     * o sættes til i, til brug af indeks senere */
    else {
      WAREHOUSE = 1;
      o = i;
    }
  }

  /* Checker for id, op til det næste bogstav */
  while (WAREHOUSE == 1 && ID == 0) {

    /* Checker om den (int) typecastede værdi af code[i] er mellem 48 og 57 (Tal, ASCII) */
    if ((int) code[i] >= 48  && (int) code[i] <= 57) {
      /* i - o, er for at starte ved id[0] */
      id[i - o] = code[i];
      i++;
    }

    else {
      ID = 1;
      o = i;
    }
  }

  /* Checker for qualifiers, op til længden af code tekststrengen */
  while (WAREHOUSE == 1 && ID == 1 && i != str_len) {
    qualifiers[i - o] = code[i];
    i++;
  }
}

/* Printer resultatet til terminalen */
void displayInfo(char *warehouse, char *id, char *qualifiers) {

  printf("Warehouse: %s\n", warehouse);
  printf("Product ID: %s\n", id);
  printf("Qualifers: %s\n", qualifiers);
}

/* Fylder et char array med et givent tegn */
void arrayFiller(char *array, int n) {
  for (int i = 0; i <= n; i++) {
    array[i] = '\0';
  }
}
