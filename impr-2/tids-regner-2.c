# include <stdio.h>

int main(void) {

  int t = 0, sek = 0, min = 0, timer = 0, dage = 0, uger = 0;

  printf("Indtast et antal sekunder: ");
  scanf("%d", &t);

  for (i = 1; i <= t; i++) {
    if (t / 60 >= 1) {
      
    }
  }

  sek = t % 60;

  printf("%2d uge(r), %2d dag(e), %2d time(r), %2d minut(ter) og %2d sekund(er)\n",
	 uger,
	 dage,
	 timer,
	 min,
	 sek);
  
  return 0;
}
