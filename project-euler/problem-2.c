# include <stdio.h>

int main(void) {

  int a = 0, b = 1, sum, i;

  for (i = 0; a < 4000000; i++) { //S� l�nge a er mindre end, k�res koden

    a += b;  //I disse to linjer l�gges de to sidste udregninger sammen.
    b = a - b;

    if (a % 2 == 0) { //Her tjekker vi om a er et lige tal
      sum += a; //Hvis a er lige, l�gges det til summen
    }


    printf("a: %7d, b: %7d, sum: %7d\n", a, b, sum);
  }

  return 0;
}
