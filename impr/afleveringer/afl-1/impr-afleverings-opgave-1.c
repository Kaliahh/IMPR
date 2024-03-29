// Ane S�gaard J�rgensen
// 09/09-2018
// Afleveringsopgave i IMPR til den 17/09-2018 12:00
// Underviser: Kurt N�rmark
// Link til opgave: https://goo.gl/68PJhj

// Konverterer et input i sekunder til uger, dage, timer, minutter og sekunder.


# include <stdio.h>

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
  min = (t % 3600) / 60;
  timer = (t % 86400) / 3600;
  dage = (t % 604800) / 86400;
  uger = t / 604800;

  
  /* Udskriver det konverterede input til terminalen */  
   printf("%d uge%s, %2d dag%s, %2d time%s, %2d minut%s og %2d sekund%s\n",
   uger, 
   (uger == 1) ? "" : "r",
   dage,
   (dage == 1) ? "" : "e",
   timer,
   (timer == 1) ? "" : "r",
   min,
   (min == 1) ? "" : "ter",
   sek,
   (sek == 1) ? "" : "er");
  
  
  return 0;
}





/*   Forklaring til konvertering:

     Den f�rste er sekunder. Man kan teste det ved at sige 61 % 60 = 1, og 59 % 60 = 59.

     Den n�ste er minutter. Der er 3600 sekunder i �n time. 3600 / 60 = 60 minutter.
     S� hvis t = 60. 60 % 3600 = 60. 60 / 60 = 1.
     Det samme g�lder t = 61. 61 % 3600 = 61. 61 / 60 = 1.
     Nu kan vi se p� nogle gr�nsev�rdier:
     t = 3599. 3599 % 3600 = 3599. 3599 / 60 = 59.
     t = 3600. 3600 % 3600 = 0. 0 / 60 = 0.
     t = 3660. 3660 % 3600 = 60. 60 / 60 = 1.
     osv.

     For b�de timer og dage, g�lder det samme princip. For timer er det bare i forhold til dage,
     og for dage er det i forhold til uger, med 23 timer og 6 dage som det h�jeste de kan vise.

     Uger er lidt speciel, fordi den skal ikke resettes (medmindre man gerne vil have �r p�).
     Den t�ller bare op som den skal. 
*/
