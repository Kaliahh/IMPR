# include <stdio.h>
# include <unistd.h>

int main(void) {
  int a = 100000, i, j;
  
  for (i = 1; i <= a; i++){
    printf("|");
    sleep(1);
    printf("\r");
    printf("/");
    sleep(1);
    printf("\r");
    printf("--");
    sleep(1);
    printf("\r");
    printf("\\");
    sleep(1);
    printf("\r");
     
  }
  
  return 0;
}
