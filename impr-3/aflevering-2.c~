// Ane Søgaard Jørgensen
// 12/09-2018
// Afleveringsopgave i IMPR til den ??/??-2018 ??:??
// Link til opgave: ??

# include <stdio.h>
# include <string.h>

# define SEK_I_MINUT 60
# define SEK_I_TIME 3600

int main(void) {

  int t = 0, sek = 0, min = 0, timer = 0;

  char timer_enhed[10] = "", min_enhed[10] = "", sek_enhed[10] = "";

  /* char timer_str[10] = "", min_str[10] = "", sek_str[10] = ""; */

  printf("Input antal sekunder: ");
  scanf("%d", &t);

  /* Udregner sekunder, minutter og timer fra inputtet */
  sek = t % 60;
  min = (t % 3600) / 60;
  timer = t / 3600;


  /* Finder enhederne for antal timer, minutter og sekunder */
  if (timer == 1) {
    strcpy(timer_enhed, "time");
  }

  else if (timer > 1) {
    strcpy(timer_enhed, "timer");
  }

  if (min == 1) {
    strcpy(min_enhed, "minut");
  }

  else if (min > 1 || t > SEK_I_MINUT) {
    strcpy(min_enhed, "minutter");
  }

  if (sek == 1) {
    strcpy(sek_enhed, "sekund");
  }

  else if (sek > 1 || t > 1) {
    strcpy(sek_enhed, "sekunder");
  }

  /* Printer resultatet alt efter antallet af de forskellige tal */

  if (t == 0) {
    printf("Programmet har brug for input for at virke!\n");
  }

  if (t > 0) {
    if (t >= SEK_I_MINUT) {
      if (t >= SEK_I_TIME) {
	printf("%d %s, %d %s, %d %s\n", timer, timer_enhed, min, min_enhed, sek, sek_enhed);
      }
      else if (t < SEK_I_TIME) {
	printf("%d %s, %d %s\n", min, min_enhed, sek, sek_enhed);
      }
    }
    else if (t < SEK_I_MINUT) {
      printf("%d %s\n", sek, sek_enhed);
    }
  }
  
  
  return 0;
}
