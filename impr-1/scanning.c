# include <stdio.h>

int main(void) {
  float a;

  printf("Input a number: ");
  scanf("%f", &a);
  printf("You number is: %1.1f\n", a);

  return(0);

}



/* 
Altid bare hold det første argument i scanf til placeholder,
rediger længden af decimaler og sådan i printf
*/
