/* Navn: Ane Søgaard Jørgensen
 * Dato: 05/11-2018
 * Beskrivelse: Afleveringsopgave 10. Et program der laver, blander, og sorterer et spil kort, med 55 kort (3 jokere)
 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# define DECK_SIZE 55
# define NUM_OF_CARDS_IN_SUIT 13
# define NUM_OF_SUITS 4
# define NUM_OF_JOKERS 3

/* Initialiserer en enumeration for alle kort, både værdi og farve */
enum Values {Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace, Joker};
enum Suits {Clubs, Diamonds, Hearts, Spades, Jokers};

/* Struct for et kort, typedeffed til card */
typedef struct card {
  int value;
  int suit;
} card;

/* Funktioner til printning af et sæt */
void deckPrinter(const card *);
char * suitIdentifier(int);
char * valueIdentifier(int);

/* Funktioner til blanding af kort */
void shuffleDeck(card *);
void swap(card *, int, int);

/* Utility funktioner */
void pressEnter(const char *);
void deckFiller(card *);
int qComp(const void *, const void *);

int main(void) {
  card deck[DECK_SIZE];

  /* Seeder random generatoren til brug i blanding af et sæt kort */
  time_t t;
  srand((int) time(&t));

  /* Fylder et array af kort */
  pressEnter("fill deck");
  deckFiller(deck);
  deckPrinter(deck);

  /* Blander et array af kort */
  pressEnter("shuffle deck");
  shuffleDeck(deck);
  deckPrinter(deck);

  /* Sorterer et array af kort */
  pressEnter("sort deck");
  qsort(deck, DECK_SIZE, sizeof(card), qComp);
  deckPrinter(deck);

  return 0;
}

/* Venter, indtil brugeren trykker Enter */
void pressEnter(const char *command) {
  printf("Press Enter to %s...", command);
  while (getchar() != '\n');
  printf("\n");
}

/* Fylder et array af cards med kort */
void deckFiller(card *deck) {
  int sum = 0;

  for (int i = 0; i < NUM_OF_SUITS; i++) {
    for (int j = 0; j < NUM_OF_CARDS_IN_SUIT; j++) {
      deck[sum + j].suit = i;
      deck[sum + j].value = j;
    }

    /* Startstedet for den næste tur gennem loopet sættes op med 13,
     * så det ikke bare er de samme pladser der bliver fyldt igen */
    sum += NUM_OF_CARDS_IN_SUIT;
  }

  /* Fylder de sidste 3 pladser i sættet med jokere */
  for (int k = 0; k < NUM_OF_JOKERS; k++) {
    deck[sum + k].suit = Jokers;
    deck[sum + k].value = Joker;
  }
}

/* Printer alle kort i sættet */
void deckPrinter(const card *deck) {
  for (int i = 0; i < DECK_SIZE; i++) {

    /* Checker for specialtilfældet at kortet er en joker,
     * som jo ikke rigtig har en kulør */
    if (deck[i].value == Joker) {
      printf("%2d |      Joker\n", i + 1);
    }

    /* Ellers bliver kulør og værdi identificeret, og printet */
    else {
      printf("%2d | %5s of %-8s\n", i + 1, valueIdentifier(deck[i].value), suitIdentifier(deck[i].suit));
    }
  }

  printf("\n");
}

/* Returnerer en tekststreng med kuløreren for et kort */
char * suitIdentifier(int suit) {
  return (suit == Clubs)    ? "Clubs"    :
         (suit == Diamonds) ? "Diamonds" :
         (suit == Hearts)   ? "Hearts"   :
         (suit == Spades)   ? "Spades"   :
         "SUIT ERROR";
}

/* Returnerer tekststreng med værdien for et kort */
char * valueIdentifier(int value) {
  return (value == Two)   ? "Two"   :
         (value == Three) ? "Three" :
         (value == Four)  ? "Four"  :
         (value == Five)  ? "Five"  :
         (value == Six)   ? "Six"   :
         (value == Seven) ? "Seven" :
         (value == Eight) ? "Eight" :
         (value == Nine)  ? "Nine"  :
         (value == Ten)   ? "Ten"   :
         (value == Jack)  ? "Jack"  :
         (value == Queen) ? "Queen" :
         (value == King)  ? "King"  :
         (value == Ace)   ? "Ace"   :
         "VALUE ERROR";
}

/* Blander kortene i et sæt */
void shuffleDeck(card *deck) {

  /* Ombytter 2 "tilfældigt" udvalgte kort. Dette gøres 10000 gange */
  for (int i = 0; i < 10000; i++) {
    swap(deck, rand() % DECK_SIZE, rand() % DECK_SIZE);
  }
}

/* Ombytter to korts værdi og kulør */
void swap(card *deck, int a, int b) {
  card temp;

  temp.suit = deck[a].suit;
  deck[a].suit = deck[b].suit;
  deck[b].suit = temp.suit;

  temp.value = deck[a].value;
  deck[a].value = deck[b].value;
  deck[b].value = temp.value;
}

/* Sammenligningsfunktion til qsort */
int qComp(const void *a, const void *b) {
  card *p1 = (card*)a;
  card *p2 = (card*)b;

  if (p1->suit - p2->suit < 0) {
    return -1;
  }

  else if (p1->suit - p2->suit > 0) {
    return 1;
  }

  /* Hvis kuløren er den samme, bliver der sorteret efter værdi */
  else {
    return p1->value - p2->value;
  }
}
