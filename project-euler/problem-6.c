# include <stdio.h>

int main(void) {
  int a = 0, b = 0, c = 0, d = 0, i;

  for (i = 1; i <= 100; i++) {
    a += i * i;
    b += i;

    printf("i: %5d, a: %5d, b: %5d\n", i, a, b);

  }

  c = b * b;
  printf("c: %d\n", c);

  d = c - a;
  printf("sum: %d\n", d);

  return 0;
}

