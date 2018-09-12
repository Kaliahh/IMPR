// Ane Søgaard Jørgensen
// 12/09-2018
// Afleveringsopgave i IMPR til den ??/??-2018 ??:??
// Link til opgave: ??

# include <stdio.h>

int main(void) {

  int t = 0, sek = 0, min = 0, timer = 0, sek_ental = 0, min_ental = 0, timer_ental = 0;

  printf("Input antal sekunder: ");
  scanf("%d", &t);

  sek = t % 60;
  min = (t % 3600) / 60;
  timer = t / 3600;

  if (t % 60 > 0) {
    sek_ental = sek == 1 ? 1 : 0;
  }

  if (t >= 60 && t > 3600) {
      
    }

  if (t >= 3600) {

    }


  if (

  
  return 0;
}
