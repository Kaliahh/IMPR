/* Navn: Ane Søgaard Jørgensen
 * Dato: 05/11-2018
 * Beskrivelse: Afleveringsopgave 10. Et program der laver, og sorterer et spil kort, med 55 kort (3 jokere)
 */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define DECK_SIZE 55

/* Initialiserer en enumeration for alle kort, både værdi og farve */
enum card_type {Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace = 20, Joker = 30};
enum suit {Clubs, Diamonds, Hearts, Spades};

/* Typedeffer enumerationerne, så de er lettere at tilgå */
typedef enum card_type card_type;
typedef enum suit suit;

/* Struct for et kort */
struct card {
  int value;
  int colour;
};

/* Typedeffer struct for kort, så det er nemmere at tilgå */
typedef struct card card;

void arrayFiller(card *);

int main(void) {

  card deck[DECK_SIZE];

  card ace_of_spades = {Four, Spades};

  arrayFiller(deck);

  printf("%d\n", deck[30].value);

  return 0;
}


void arrayFiller(card *deck) {
  for (int i = 0; i < DECK_SIZE; i++) {
    deck[i].colour = 0;
    deck[i].value = 0;
  }
}
