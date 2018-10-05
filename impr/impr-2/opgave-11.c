# include <stdio.h>
# include <stdlib.h>


int main(void) {

  int m = 0, n = 0;
  int side1 = 0, side2 = 0, hypothenuse = 0;


  /* Takes an input to m and n */
  printf("Input m and n (m > n): ");
  scanf("%d %d", &m, &n);

  
  /* Computes the sides and hypothenuse */
  side1 = m * m - n * n;
  side2 = 2 * m * n;
  hypothenuse = m * m + n * n;

  /* Prints the results */
  printf("\nSide 1: %d\nSide 2: %d\nHypothenuse: %d\n\n",
	 side1,
	 side2,
	 hypothenuse);
  
  return 0;

}
