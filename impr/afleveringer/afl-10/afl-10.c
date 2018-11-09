/* Navn: Ane Søgaard Jørgensen
 * Dato: 05/11-2018
 * Beskrivelse: Afleveringsopgave 10. Et program der laver, og sorterer et spil kort, med 55 kort (3 jokere)
 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# define DECK_SIZE 55
# define SUIT_SIZE 13
# define NUM_OF_SUITS 4
# define NUM_OF_JOKERS 3

/* Initialiserer en enumeration for alle kort, både værdi og farve */
enum card_type {Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace, Joker = 30};
enum suit {Clubs, Diamonds, Hearts, Spades, Jokers};

/* Typedeffer enumerationerne, så de er lettere at tilgå */
typedef enum card_type card_type;
typedef enum suit suit;

/* Struct for et kort */
struct card {
  int value;
  int colour;
};

/* Typedeffer struct for kort, så det er nemmere at arbejde med */
typedef struct card card;

void deckFiller(card *);
void deckPrinter(card *);
void shuffleDeck(card *);
void swap(int *, int *);
int qComparator(const void *a, const void *b);

int main(void) {

  card deck[DECK_SIZE];

  /* Seeder random generatoren til brug i initialisering af arrays*/
  time_t t;
  srand((int) time(&t));

  deckFiller(deck);

  // deckPrinter(deck);

  shuffleDeck(deck);

  deckPrinter(deck);

  // qsort(deck, DECK_SIZE, sizeof(struct card), qComparator);

  // deckPrinter(deck);

  return 0;
}

/* Fylder et array af cards med "kort" */
void deckFiller(card *deck) {

  int sum = 0;

  for (int i = 0; i < NUM_OF_SUITS; i++) {
    for (int j = 0; j < SUIT_SIZE; j++) {

      deck[j + sum].colour = i;
      deck[j + sum].value = j;
    }
    sum += SUIT_SIZE;
  }

  for (int k = 0; k < NUM_OF_JOKERS; k++) {
    deck[sum + k].colour = Jokers;
    deck[sum + k].value = Joker;
  }
}

/* Printer alle "kort" i et array */
void deckPrinter(card *deck) {
  for (int i = 0; i < DECK_SIZE; i++) {
    printf("Colour: %d, value: %d\n", deck[i].colour, deck[i].value);
  }
}

/* Blander kortene */
void shuffleDeck(card *deck) {
  int ranColour_1, ranColour_2, ranValue_1, ranValue_2;
  for (int i = 0; i < 1000; i++) {
    ranColour_1 = rand() % 3;
    ranColour_2 = rand() % 3;
    swap(deck[ranColour_1].colour, deck[ranColour_2].colour);

    ranValue_1 = rand() % 54;
    ranValue_2 = rand() % 54;
    swap(deck[ranValue_1].value, deck[ranValue_2].value);
  }
}

void swap(int *a, int *b) {
  int temp = b;
  b = a;
  a = temp;
}

/* Sammenligningsfunktion til qsort */
int qComparator(const void *a, const void *b) {

}
