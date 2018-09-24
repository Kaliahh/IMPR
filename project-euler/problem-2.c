# include <stdio.h>

int main(void) {

  int a = 0, b = 1, sum, i;

  for (i = 0; a < 1e9; i++) { //Så længe a er mindre end, køres koden

    a = a + b;  //I disse to linjer lægges de to sidste udregninger sammen.
    b = a - b; 

    if (a % 2 == 0) { //Her tjekker vi om a er et lige tal
      sum += a; //Hvis a er lige, lægges det til summen
    }

    
    printf("a: %7d, b: %7d, sum: %7d\n", a, b, sum);
  }

  return 0;
}



