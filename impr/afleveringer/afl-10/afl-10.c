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
enum Values {Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace, Joker = 30};
enum Suits {Clubs, Diamonds, Hearts, Spades, Jokers};

/* Struct for et kort, typedeffed til card*/
typedef struct card {
  int value;
  int suit;
} card;

/* Prototyper til printning af et sæt */
void deckPrinter(const card *);
char * suitIdentifier(int suit);
char * valueIdentifier(int value);

/* Prototyper til blanding af kort */
void shuffleDeck(card *);
void swapSuit(card *, int, int);
void swapValue(card *, int, int);

/* Prototyper til sortering af et sæt */
void sortDeck(card *);
int suitComp(const void *a, const void *b);
int valueComp(const void *a, const void *b);

void pressEnter(void);
void deckFiller(card *);

int main(void) {
  card deck[DECK_SIZE];

  /* Seeder random generatoren til brug i blanding af et sæt kort */
  time_t t;
  srand((int) time(&t));

  /* Fylder et array af kort */
  deckFiller(deck);
  printf("Fill deck: \n");
  pressEnter();
  deckPrinter(deck);

  /* Blander et array af kort */
  shuffleDeck(deck);
  printf("Shuffle deck: \n");
  pressEnter();
  deckPrinter(deck);

  /* Sorterer et array af kort */
  sortDeck(deck);
  printf("Sort deck: \n");
  pressEnter();
  deckPrinter(deck);

  return 0;
}

/* Venter, indtil brugeren trykker Enter */
void pressEnter(void) {
  printf("Press Enter to continue...");
  while (getchar() != '\n');
  printf("\n");
}

/* Fylder et array af cards med kort */
void deckFiller(card *deck) {
  int sum = 0;

  /* Går igennem hver kulør, og igennem hver værdi */
  for (int i = 0; i < NUM_OF_SUITS; i++) {
    for (int j = 0; j < NUM_OF_CARDS_IN_SUIT; j++) {
      deck[sum + j].suit = i;
      deck[sum + j].value = j;
    }

    /* Startstedet for den næste tur gennem loopet,
     * så det ikke bare er de samme 13 pladser der bliver fyldt igen */
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
  char suit[10];
  char value[10];

  for (int i = 0; i < DECK_SIZE; i++) {

    /* Checker for specialtilfældet at det er en joker,
     * som jo ikke rigtig har en kulør */
    if (deck[i].value == Joker) {
      printf("%2d |      Joker\n", i + 1);
    }

    /* Ellers bliver kulør og værdi identificeret, og printet */
    else {
      strcpy(suit, suitIdentifier(deck[i].suit));
      strcpy(value, valueIdentifier(deck[i].value));
      printf("%2d | %5s of %-8s\n", i + 1, value, suit);
    }
  }

  /* Gør det lidt nemmere at læse output til terminalen */
  printf("\n= = = = = = = = = = = = = = = = =\n\n");
}

/* Returnerer en tekststreng med kuløreren for et kort */
char * suitIdentifier(int suit) {
  return (suit == Clubs)    ? "Clubs"    :
         (suit == Diamonds) ? "Diamonds" :
         (suit == Hearts)   ? "Hearts"   :
         (suit == Spades)   ? "Spades"   :
         (suit == Jokers)   ? "Jokers"   :
         "Suit error";
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
         (value == Joker) ? "Joker" :
         "Value error";
}

/* Blander kortene i et sæt */
void shuffleDeck(card *deck) {
  int ranNum_1, ranNum_2;

  /* Ombytter 2 "tilfældigt" udvalgte kort. Dette gøres 1000 gange */
  for (int i = 0; i < 1000; i++) {
    ranNum_1 = rand() % DECK_SIZE;
    ranNum_2 = rand() % DECK_SIZE;

    swapSuit(deck, ranNum_1, ranNum_2);
    swapValue(deck, ranNum_1, ranNum_2);
  }
}

/* Ombytter to korts kulør */
void swapSuit(card *deck, int a, int b) {
  card temp;

  temp.suit = deck[a].suit;
  deck[a].suit = deck[b].suit;
  deck[b].suit = temp.suit;
}

/* Ombytter to korts værdier */
void swapValue(card *deck, int a, int b) {
  card temp;

  temp.value = deck[a].value;
  deck[a].value = deck[b].value;
  deck[b].value = temp.value;
}

/* Sorterer et sæt af kort */
void sortDeck(card *deck) {

  /* Sorterer sættet efter kulør */
  qsort(deck, DECK_SIZE, sizeof(card), suitComp);

  /* Sorterer sættet efter værdi */
  for (int i = 0; i < 4; i++) {
    qsort(deck + NUM_OF_CARDS_IN_SUIT * i, NUM_OF_CARDS_IN_SUIT, sizeof(card), valueComp);
  }
}

/* Sammenligningsfunktion til qsort af kulør*/
int suitComp(const void *a, const void *b) {
  card *p1 = (card*)a;
  card *p2 = (card*)b;
  return ((p1->suit) - (p2->suit));
}

/* Sammenligningsfunktion til qsort af værdi*/
int valueComp(const void *a, const void *b) {
  card *p1 = (card*)a;
  card *p2 = (card*)b;
  return ((p1->value) - (p2->value));
}
