# include <stdio.h>
# include <math.h>


int main(void) {
  int a = 0, b = 0, c = 0, i = 1;

  for (i = 1; i <= 100; i++) {
    for (a = 1; a <= i; a++) {
      b += a;
      printf("a: %7d, b: %7d, c: %7d\n", a, b, c);
      
    }
    c += b;
    b = 0;
    printf("\n");
    //printf("c: %7d\n", c);
    
  }

  return 0;
}
