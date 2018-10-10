#include <stdio.h>

int main(void) {
 int i, n = 2784, sum = 0;

 for (i = 1; i <= n; i++) {
  sum += i;
 }

 printf("Sum: %d\n", sum);

 if (sum == ((n * (n + 1)) / 2)) {
  printf("Noget\n");
 }

 else
  printf("Noget andet\n");


 return 0;
}
