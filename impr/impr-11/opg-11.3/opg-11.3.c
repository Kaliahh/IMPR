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

  n = scanForDM();

  if (n == 1) {
    q = quotient(dend, dsor);
    printf("q: %d\n", q);
  }

  else if (n == 2) {
    m = modulus(dend, dsor);
    printf("m: %d\n", m);
  }

  return 0;
}

int quotient(int dividend, int divisor) {
  int rest = 0;
  int i = 1;

  if (dividend - divisor > 0) {
    rest = dividend - divisor;
    i = i + quotient(rest, divisor);
  }

  else if (dividend - divisor < 0) {
    return i;
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

int scanForDM(void) {

  char c;
  printf("Vil du dividere eller finde modulus? (d/m) ");
  scanf(" %c", &c);

  if (c == 'd') {
    return 1;
  }

  else if (c == 'm') {
    return 2;
  }

  else {
    return -1;
  }
}
