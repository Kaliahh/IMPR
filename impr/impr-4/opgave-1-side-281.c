# include <stdio.h>

int main(void) {
 int people = 10, i;

 while (people < 30000) {
  people *= 1.1;
  printf("Folk: %d\n", people);
  i += 1;
 }

 printf("Antal år: %d\n", i);

 return 0;
}
