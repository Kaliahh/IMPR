/* Navn: Ane Søgaard Jørgensen
 * Dato: 02/11-2018
 * Beskrivelse: Opg 11.3. Heltalsdivision og restudragning med rekursive funktioner
 */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>

void scanForDD(int *, int *);
int scanForDM(void);
int quotient(int dividend, int divisor);
int modulus(int dividend, int divisor);

int main(void) {

  int q, m, n;
  int dsor = 0, dend = 0;

  scanForDD(&dend, &dsor);

  printf("%d / %d = %d\n", dend, dsor, quotient(dend, dsor));
  printf("%d modulus %d = %d\n", dend, dsor, modulus(dend, dsor));

  return 0;
}

int quotient(int dividend, int divisor) {
  //int rest = 0;
  int n = 1;

  printf("dividend: %d\n", dividend);

  if (dividend - divisor > 0) {
    //rest = dividend - divisor;
    dividend = dividend - divisor;
    n = quotient(dividend, divisor);
    printf("n: %d\n", n);
  }

  else if (dividend - divisor < 0) {
    return n;
  }
}

int modulus(int dividend, int divisor) {
  int rest = 0;

  if (dividend - divisor > 0) {
    rest = dividend - divisor;
    modulus(rest, divisor);
  }

  else if (dividend - divisor < 0) {
    return dividend;
  }
}

void scanForDD(int *dend, int *dsor) {

  printf("Indtast dividend og divisor: ");
  scanf(" %d%d", dend, dsor);
}
