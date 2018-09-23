#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DEVIATION 0.8

int main (void) {

  double r = 0, x = 0, y = 0, len_from_origin = 0;

  printf("This program checks if a point is in, outside, \n");
  printf("or on the peripheral of a circle\n\n");

  printf("Input a radius: ");
  scanf("%lf", &r);
  
  printf("\nInput a point (x,y): ");
  scanf(" (%lf , %lf)", &x, &y);

  len_from_origin = sqrt(x * x + y * y);

  printf("The point (%.2lf,%.2lf) is %s of the circle\n", x, y,
	 ((len_from_origin >= r - DEVIATION) && (len_from_origin <= r + DEVIATION)) ?
	 "on the peripheral" :
	 (len_from_origin > r + DEVIATION) ? "outside" : "inside");
	 

  return 0;
}
