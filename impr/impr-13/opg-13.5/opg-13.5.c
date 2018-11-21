/* Navn: Ane Søgaard Jørgensen
 * Dato: 21/11-2018
 * Beskrivelse: Læsning af personkartotek i komma-separeret tekstfil
 */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>

# define MAX_NAME_LEN 50
# define MAX_ADDRESS_LEN 200
# define NUMBER_OF_ADRESS 11

typedef struct {
  char fornavn[MAX_NAME_LEN];
  char efternavn[MAX_NAME_LEN];
  char vejnavn[MAX_NAME_LEN];
  int vejnummer;
  int postnummer;
  char bynavn[MAX_NAME_LEN];
} person;

person *fillArray(person *);
void printArray(person *);
int qComp(const void *, const void *);

int main(void) {

  person people[NUMBER_OF_ADRESS];

  fillArray(people);

  printArray(people);

  qsort(people, NUMBER_OF_ADRESS, sizeof(person), qComp);

  printf("\n");
  printArray(people);

  return 0;
}

/* Fylder et array af structs med ting */
person *fillArray(person *people) {

  FILE * fP;
  char dump[2];

  fP = fopen("tekstfil.txt", "r");

  /* Checker om filen blev åbnet */
  if (fP == NULL) {
     perror("Error opening file");
     return people;
  }

  /* Tager forskellige ting fra filen, ved hjælp af nogle kriterier */
  for (int j = 0; j < NUMBER_OF_ADRESS; j++) {
    fscanf(fP, " %[a-zA-Z]" " %[a-zA-Z]" " %[,]" " %[a-zA-Z ]" " %d" "%[,]" " %d" " %[a-zA-Z]" "%s",
          people[j].fornavn, people[j].efternavn,
          dump,
          people[j].vejnavn, &people[j].vejnummer,
          dump,
          &people[j].postnummer, people[j].bynavn,
          dump);

    /* Fjerner det sidste mellemrum efter vejnavn (Virker af en eller anden grund ikke altid) */
    for (int i = MAX_NAME_LEN - 1; i > 0; i--) {
      if (people[j].vejnavn[i] == ' ') {
        people[j].vejnavn[i] = '\0';
        break;
      }
    }
  }

  fclose(fP);

  return people;
}

/* Printer et array af structs */
void printArray(person *people) {
  for (int j = 0; j < NUMBER_OF_ADRESS; j++) {
    printf("%2d | %s %s, %s %d, %d %s\n",
          j,
          people[j].fornavn, people[j].efternavn,
          people[j].vejnavn, people[j].vejnummer,
          people[j].postnummer, people[j].bynavn);
  }
}

/* Sammenligningsfunktion til qsort */
int qComp(const void *a, const void *b) {
  person *p1 = (person*)a;
  person *p2 = (person*)b;

  return strcmp(p1->efternavn, p2->efternavn);
}
