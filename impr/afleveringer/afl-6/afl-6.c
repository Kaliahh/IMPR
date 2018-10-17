/* Navn: Ane Søgaard Jørgensen
 * Dato: 17/10-2018
 * Beskrivelse: Opg. 17 side 334. Find arealet under en kurve.
 */

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>

/* y = f(x)
 * x = a
 * x = b
 *
 * T = (h / 2) * (f(a) + f(b) + 2 * (for (i = 1; i <= n - 1; i++) SUM af f(x_i))
 *
 * h = (b - a) / n
 *
 * g(x) = x^2 sin(x), (a = 0, b = pi)
 *
 * h(c) = sqrt(4 - x^2), (a = -2, b = 2)
 */

int main(void) {

  double a, b;

  printf("Input 2 numbers, a and b, for the limits of the area: ");
  scanf("%lf%lf", &a, &b);

  printf("\nInput subintervals ")



  return 0;
}

int trap(double a, double b, int n, int f) {

  

}
