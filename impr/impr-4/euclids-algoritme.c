# include <stdio.h>


int main(void) {

  int i, j, small, large, rem;

  printf("Enter two non-negative intergers: ");
  scanf("%d %d", &i, &j);

  small = (i <= j) ? i : j;
  large = (i <= j) ? j : i;

  printf("%d %d | ", large, small);

  while (small > 0) {
    rem = large % small;
    large = small;
    small = rem;
    printf("%d ", small);
  }

  printf("\n\nGreatest common divider (GCD) of %d and %d is %d\n\n",
	 i, j, large);
  
  return 0;
}
