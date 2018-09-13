// Ane Søgaard Jørgensen
// 09/09-2018
// Afleveringsopgave i IMPR til den 17/09-2018 12:00
// Link til opgave: https://goo.gl/68PJhj


# include <stdio.h>

int main(void) {

  int t = 0, sek = 0, min = 0, timer = 0, dage = 0, uger = 0;

  printf("Indtast et antal sekunder: ");
  scanf("%d", &t); // Input må ikke være højere end 2,147,483,647


  /* I de næste 5 linjer kode regnes de forskellige tidsenheder ud.x
     Den første er sekunder. Man kan teste det ved, ved at sige 61 % 60 = 1 og 59 % 60 = 59.

     Den næste er minutter. Der er 3600 sekunder i én time. 3600 / 60 = 60 minutter.
     Så hvis t = 60. 60 % 3600 = 60. 60 / 60 = 1.
     Det samme gælder t = 61. 61 % 3600 = 61. 61 / 60 = 1.
     Nu kan vi se på nogle grænseværdier:
     t = 3599. 3599 % 3600 = 3599. 3599 / 60 = 59.
     t = 3600. 3600 % 3600 = 0. 0 / 60 = 0.
     t = 3660. 3660 % 3600 = 60. 60 / 60 = 1.
     osv.

     For både timer og dage, gælder det samme princip. For timer er det bare i forhold til dage,
     og for dage er det i forhold til uger, og selvfølgelig med 23 timer og 6 dage som det højeste de kan vise.

     Uger er lidt speciel, fordi den skal ikke resettes (medmindre man gerne vil have år på).
     Den tælder bare op som den skal. */
  
  sek = t % 60;
  min = (t % 3600) / 60;
  timer = (t % 86400) / 3600;
  dage = (t % 604800) / 86400;
  uger = t / 604800;
  
  
  printf("%d uge(r), %2d dag(e), %2d time(r), %2d minut(ter) og %2d sekund(er)\n",
	 uger,
	 dage,
	 timer,
	 min,
	 sek); // Her printes tiden ud, i det ønskede format
  
  return 0;
}
