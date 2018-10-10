# include <stdio.h>

int main(void) {

 int m, n, k, i, sum = 0;

 printf("Input 2 heltal: ");
 scanf("%d %d", &m, &n);

 printf("Input et andet heltal: ");
 scanf("%d", &k);

 for (i = m; i <= n; i++) {
  if (i % k == 0) {
   sum += i;
  }
 }

 printf("Sum: %d\n", sum);

 return 0;
}
