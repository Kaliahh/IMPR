# include <stdio.h>

int main(void) {

  int i, j, k, l, max;

  printf("Input an integer: ");
  scanf("%d", &max);
  printf("\n");

  for (k = 0; k <= max - 1; k++) {
    for (l = 0; l <= k; l++) {
      printf("%d ", l);
    }
    printf("\\");
    printf("\n");
  }

  for (i = 0; i <= max; i++) {
    for (j = 0; j <= max - i; j++) {
      printf("%d ", j);
      if (j == max)
        printf(">");
    }
    if (j != max + 1)
      printf("/");
    printf("\n");
  }

  printf("\n");

  return 0;
}
