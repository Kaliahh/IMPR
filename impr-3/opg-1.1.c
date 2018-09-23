#include <stdio.h>


int main(void) {

  int watts;

  printf("Input watts: ");
  scanf("%d", &watts);

  switch(watts) {

  case 15:
    printf("125 lumens\n");
    break;

  case 25:
    printf("215 lumens\n");
    break;

  case 40:
    printf("500 lumens\n");
    break;

  case 60:
    printf("880 lumens\n");
    break;

  case 75:
    printf("1000 lumens\n");
    break;
    
  case 100:
    printf("1675 lumens\n");
    break;

  default:
    printf("-1 lumens\n");
    
  }


  return 0;
}
