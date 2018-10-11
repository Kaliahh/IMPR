# include <stdio.h>

int spaces(int);
int top(int);
int bottom(int);

int main(void) {

  int max;

  printf("Input an integer: ");
  scanf("%d", &max);
  printf("\n");

  top(max);
  bottom(max);

  printf("\n");


  spaces(max);

  return 0;
}


int spaces(int a) {

  int i;

  for (i = 1; i <= a; i++) {
    printf(" ");
  }
}


int top(int max) {

  int k, l;

  for (k = 0; k <= max - 1; k++) {
    for (l = 0; l <= k; l++) {
      printf("%d ", l);
    }
    printf("\\");
    printf("\n");
  }
}

int bottom(int max) {

  int i, j;

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
}
