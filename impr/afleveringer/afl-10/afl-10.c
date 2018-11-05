/* Navn: Ane Søgaard Jørgensen
 * Dato: 05/11-2018
 * Beskrivelse: Afleveringsopgave 10. Et program der laver, og sorterer et spil kort, med 55 kort (3 jokere)
 */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define DECK_SIZE 55

/* Initialiserer en enumeration for alle kort, både værdi og farve */
enum card_type {NullType, Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace = 20, Joker = 30};
enum suit {NullSuite, Clubs, Diamonds, Hearts, Spades};

/* Typedeffer dem, så de er lettere at tilgå */
typedef enum card_type card_type;
typedef enum suit suit;

/* Struct for et kort */
struct card {
  card_type value;
  suit colour;
};

/* Typedeffer struct for kort, så det er nemmere at tilgå */
typedef struct card card;

void arrayFiller(card *);

int main(void) {

  card deck[DECK_SIZE];

  card ace_of_spades = {Ace, Spades};

  arrayFiller(deck);

  printf("%d\n", ace_of_spades.colour);

  return 0;
}


void arrayFiller(card *deck) {
  card zero = {NullType, NullSuite};
  for (int i = 0; i < DECK_SIZE; i++) {
    deck[i] = zero;
  }
}
