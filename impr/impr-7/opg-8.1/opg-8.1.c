/* Navn: Ane Søgaard Jørgensen
 * Dato: 19/10-2018
 * Beskrivelse: https://bit.ly/2pYCwia. Lav et menukort
 */

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

/* Definerer enumeration typerne */
enum forret {guacamole, tarteletter, lakserulle, graeskarsuppe};
enum hovedret {gyldenkaal, hakkeboef, gullash, forloren_hare};
enum dessert {pandekager_med_is, gulerodskage, choklademousse, citronfromage};

/* Prototyper */
void maaltid(void);
int tilf(void);
void forret(void);
void hovedret(void);
void dessert(void);

int main(void) {

  /* Laegger klokkeslaettet over i t */
  time_t t;

  /* Seeder random generatoren */
  srand((unsigned) time(&t));

  /* Printer menuerne */
  maaltid();

  return 0;
}

/* Printer menuerne */
void maaltid(void) {

  /* Printer 25 "tilfaeldige" menuer */
  for (int i = 1; i <= 25; i++) {
    printf("Menu %2d\n", i);
    forret();
    hovedret();
    dessert();
    printf("\n");
  }
}

/* Returnerer et "tilfaeldigt" heltal mellem 0 og 3 */
int tilf(void) {
  return rand() % 4;
}

/* Printer forretten */
void forret(void) {

  printf("Forret: ");

  /* Switcher på det tilfaeldige tal */
  switch (tilf()) {
    case guacamole:
      printf("guacamole.\n");
      break;

    case tarteletter:
      printf("tarteletter.\n");
      break;

    case lakserulle:
      printf("lakserulle.\n");
      break;

    case graeskarsuppe:
      printf("græskarsuppe.\n");
  }
}

/* Printer hovedretten */
void hovedret(void) {

  printf("Hovedret: ");

  switch (tilf()) {
    case gyldenkaal:
      printf("gyldenkål.\n");
      break;

    case hakkeboef:
      printf("hakkebøf.\n");
      break;

    case gullash:
      printf("gullash.\n");
      break;

    case forloren_hare:
      printf("forloren hare.\n");
      break;
  }
}

/* Printer desserten */
void dessert(void) {

  printf("Dessert: ");

  switch (tilf()) {
    case pandekager_med_is:
      printf("panderkager med is.\n");
      break;

    case gulerodskage:
      printf("gulerodskage.\n");
      break;

    case choklademousse:
      printf("choklademousse.\n");
      break;

    case citronfromage:
      printf("citronfromage.\n");
      break;
  }

}
