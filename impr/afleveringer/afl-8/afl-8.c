/* Navn: Ane Søgaard Jørgensen
 * Dato: 30/10-2018
 * Beskrivelse: Opgave 1 side 490 (Afleveringsopgave 8).
 * Tager en kode af denne type ABC1234D56
 * Laver det til ABC 1234 D56
 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>

/* En maks længde på tekststrengen */
# define MAX_LENGTH 20

void identifier(const char *, int, char*, char*, char*);
void arrayFiller(char *, int);
void displayInfo(const char *, const char *, const char *);

int main(void) {

  /* Initialiserer arrays */
  char *code       = malloc(MAX_LENGTH * sizeof(*code));
  char *warehouse  = malloc(MAX_LENGTH * sizeof(*warehouse));
  char *id         = malloc(MAX_LENGTH * sizeof(*id));
  char *qualifiers = malloc(MAX_LENGTH * sizeof(*qualifiers));

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

  /* Frigiver hukommelse */
  free(code);
  free(warehouse);
  free(id);
  free(qualifiers);

  return 0;
}

/* Identificerer warehouse, id og qualifiers */
void identifier(const char *code, int str_len, char* warehouse, char* id, char* qualifiers) {

  int i = 0, o = 0;

  /* Flag til brug i while løkker */
  int WAREHOUSE = 0, ID = 0;

  /* Checker for warehouse, op til det næste tal */
  while (WAREHOUSE == 0) {

    /* Checker om code[i] er et stort bogstav */
    if (isupper(code[i])) {
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

    /* Checker om code[i] er et tal */
    if (isdigit(code[i])) {
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
void displayInfo(const char *warehouse, const char *id, const char *qualifiers) {

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
