# include <stdio.h>

int main(void) {

 int i, j, k, l, max = 9;

 for (k = 0; k <= max - 1; k++) {
  for (l = 0; l <= k; l++) {
   printf("%d ", l);
  }
  printf("\n");
 }

 for (i = 0; i <= max; i++) {
  for (j = 0; j <= max - i; j++) {
   printf("%d ", j);
  }
  printf("\n");
 }

 return 0;
}
