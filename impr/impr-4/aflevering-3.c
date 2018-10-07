/* 
 * Ane Søgaard Jørgensen
 * 05/10-2018
 * Afleveringsopgave i IMPR til den 12/10-2018 kl. 18:00
 * Link til opgave: https://bit.ly/2yijF5w
 */

# include <stdio.h>
# include <string.h>
# include <unistd.h>

int linear(int, int);
int euclid(int, int);


int main(void) {
  
  int a = 1, b = 1, GCD;
  char choice[1];

  printf("\n-------------------------------------------------------");
  printf("\nDette program finder GCD, den stoerste faelles devisor.\n");
  printf("-------------------------------------------------------\n\n");

  /* Prompter brugeren for to positive heltal */
  printf("Indtast to positive heltal: ");
  scanf(" %d%d", &a, &b);

  /* Checker om inputtet er negativt eller lig med 0 */
  if (a <= 0 || b <= 0) {
    printf("\n######## Tallene skal vaere heltal og positive ########\n");
    sleep(2);
    main();
  }

  /* Prompter brugeren til at vælge en logaritme, eller afslutte */
  printf("\nVil du bruge en linear search, euclids algoritme eller afslutte? (l/e/a) ");
  scanf(" %c", choice);

  if (strcmp(choice, "l") == 0)
    GCD = linear(a,b);

  else if (strcmp(choice, "e") == 0)
    GCD = euclid(a,b);

  else if (strcmp(choice, "q") == 0)
    return 0;

  /* Printer GCD */
  printf("\n\na: %7d| b: %7d| GCD = %7d|\n", a, b, GCD);

  /* Prompter brugeren for en beslutning */
  printf("\nVil du lave en ny beregning, eller afslutte? (b/a) ");
  scanf(" %c", choice);

  if (strcmp(choice, "b") == 0)
    main();

  else if (strcmp(choice, "b") != 0)
    return 0;

  return 0;
}


int linear(int a, int b) {

  int i, j, rem = 10000;
  
  /* Finder den største fælles divisor */
  for (i = 1; i <= a || i <= b; i++) {
      
    if (a % i == 0 && b % i == 0)
      rem = (i > rem) ? rem = i : printf("\n");

    /*Viser step og GCD */
    printf("i: %7d| GCD: %7d|\n", i, rem);

    /* GCD kan ikke være højere end det laveste input, så der breakes der*/
    /* Dette afhjælper regnetiden, hvis der gives et meget højt tal, og et meget lavt tal */
    if (a == i || b == i)
      break;
  }

  /* Hvis der ingen fælles devisor findes, er GCD 1 */
  if (rem == 0)
    rem = 1;

  
  return rem;
}


int euclid(int a, int b) {

  int stor, lille, rem;
    
  /* Sorterer de indtastede tal */
  lille = (a <= b) ? a : b;
  stor = (a <= b) ? b : a;

  /* Starter talkæden */
  printf("\n%d %d, ", stor, lille);
    
  /* Finder den største fælles devisor */
  while (lille > 0) {
    rem = stor % lille;
    stor = lille;
    lille = rem;

    /* Printer til talkæden */
    printf("%d, ", lille);
  }

  return stor;
}
