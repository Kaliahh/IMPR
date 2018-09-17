# include <stdio.h>
# include <unistd.h>

int main(void) {

  int t = 0, i = 0;

  printf("Indtast et antal sekunder: ");
  scanf("%d", &t);

  for (i = 0; i <= t; i++) {

    printf("%d\n", i);
    sleep(1);
  }

  
  return 0;
}
