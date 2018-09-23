# include <stdio.h>

int main(void) {

  int watts = 0;
  int lumens = 0;

  printf("Input watts: ");
  scanf("%d", &watts);


  if (watts == 15)
    lumens = 125;
  else if (watts == 25)
    lumens = 215;
  else if (watts == 40)
    lumens = 400;
  else if (watts == 60)
    lumens =  880;
  else if (watts == 75)
    lumens = 1000;
  else if (watts = 100)
    lumens = 1675;
  else
    lumens = 0;

  printf("%d lumens\n", lumens);


  
  return 0;
}
