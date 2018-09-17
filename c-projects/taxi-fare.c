# include <stdio.h>

int main(void) {

  double begin = 0.0, end = 0.0, fare = 0.0, distance = 0.0, total = 0.0;

  printf("\nTAXI FARE CALCULATOR\n\n");
  
  printf("Enter beginning odometer reading: ");
  scanf("%lf", &begin);
  
  printf("Enter ending odometer reading: ");
  scanf("%lf", &end);

  distance = end - begin;

  printf("\nYou traveled a distance of %.2f km\n", distance);

  printf("\nEnter the taxi fare per kilometer: ");
  scanf("%lf", &fare);

  total = fare * distance;
  
  printf("\nYou total is %.2f kroner\n", total);

  return 0;
}
