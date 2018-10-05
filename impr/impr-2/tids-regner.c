/* Ane Søgaard Jørgensen
 * 09/09-2018
 * Afleveringsopgave i IMPR til den 17/09-2018 12:00
 * Underviser: Kurt Nørmark
 * Link til opgave: https://goo.gl/68PJhj
 *
 * Konverterer et input i sekunder til uger, dage, timer, minutter og sekunder.
 */

# include <stdio.h>

# define SEK_I_MINUT 60
# define SEK_I_TIME 3600
# define SEK_I_DAG 86400
# define SEK_I_UGE 604800

int main(void) {

  /* Initialiserer variablerne */
  int t = 0,
    sek = 0,
    min = 0,
    timer = 0,
    dage = 0,
    uger = 0;

  
  /* Prompter brugeren til at indtaste et antal sekunder */
  printf("Indtast et antal sekunder: ");
  scanf("%d", &t); 

  
  /* Konverterer input til uger, dage, timer, minutter og sekunder. Forklaring efter main funktion */
  sek = t % 60;
  min = (t % SEK_I_TIME) / SEK_I_MINUT;
  timer = (t % SEK_I_DAG) / SEK_I_TIME;
  dage = (t % SEK_I_UGE) / SEK_I_DAG;
  uger = t / SEK_I_UGE;

  
  /* Udskriver det konverterede input til terminalen */
  printf("%d uge(r), %2d dag(e), %2d time(r), %2d minut(ter) og %2d sekund(er)\n",
	 uger,
	 dage,
	 timer,
	 min,
	 sek);
  
  
  return 0;
}





/*   Forklaring til konvertering:

     Den første er sekunder. Man kan teste det ved at sige 61 % 60 = 1, og 59 % 60 = 59.

     Den næste er minutter. Der er 3600 sekunder i én time. 3600 / 60 = 60 minutter.
     Så hvis t = 60. 60 % 3600 = 60. 60 / 60 = 1.
     Det samme gælder t = 61. 61 % 3600 = 61. 61 / 60 = 1.
     Nu kan vi se på nogle grænseværdier:
     t = 3599. 3599 % 3600 = 3599. 3599 / 60 = 59.
     t = 3600. 3600 % 3600 = 0. 0 / 60 = 0.
     t = 3660. 3660 % 3600 = 60. 60 / 60 = 1.
     osv.

     For både timer og dage, gælder det samme princip. For timer er det bare i forhold til dage,
     og for dage er det i forhold til uger, med 23 timer og 6 dage som det højeste de kan vise.

     Uger er lidt speciel, fordi den skal ikke resettes (medmindre man gerne vil have år på).
     Den tæller bare op som den skal. 
*/
