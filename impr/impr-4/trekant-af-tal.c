# include <stdio.h>

int main(void) {

  int i, j, k, l, max;

  /* Prompter brugerer for et input */
  printf("Input an integer: ");
  scanf("%d", &max);
  printf("\n");


  /* Beregner første halvdel af trekanten */
  for (k = 0; k <= max - 1; k++) {
    for (l = 0; l <= k; l++) {
      printf("%d ", l);
    }
    printf("\\");
    printf("\n");
  }

  /*Beregner anden halvdel af trekanten */
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
