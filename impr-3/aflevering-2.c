/*
 * Ane S�gaard J�rgensen
 * 12/09-2018
 * Afleveringsopgave i IMPR til den 28/09-2018 16:00
 * Link til opgave: https://bit.ly/2PSykeE
 */

# include <stdio.h>
# include <string.h>

# define SEK_I_MINUT 60
# define SEK_I_TIME 3600

int main(void) {

  int t = 0, sek = 0, min = 0, timer = 0;

  char timer_enhed[10] = "", min_enhed[10] = "", sek_enhed[10] = "";
  
  /* Prompter brugeren for et antal sekunder */
  printf("Input antal sekunder: ");
  scanf("%d", &t);

  /* Udregner sekunder, minutter og timer fra inputtet */
  sek = t % SEK_I_MINUT;
  min = (t % SEK_I_TIME) / SEK_I_MINUT;
  timer = t / SEK_I_TIME;

  /* Finder enhederne for antal timer, minutter og sekunder */
  (timer == 1) ? strcpy(timer_enhed, "time") : strcpy(timer_enhed, "timer");
  (min == 1) ? strcpy(min_enhed, "minut") : strcpy(min_enhed, "minutter");
  (sek == 1) ? strcpy(sek_enhed, "sekund") : strcpy(sek_enhed, "sekunder");
  
  /* Printer resultatet, baseret p� kombinationen af sek, min og timer */
  if (sek != 0 && min != 0 && timer != 0)
    printf("%d %s, %d %s og %d %s\n", timer, timer_enhed, min, min_enhed, sek, sek_enhed);
  
  else if (sek == 0 && min != 0 && timer != 0)
    printf("%d %s og %d %s\n", timer, timer_enhed, min, min_enhed);
  
  else if (sek != 0 && min == 0 && timer != 0)
    printf("%d %s og %d %s\n", timer, timer_enhed, sek, sek_enhed);
  
  else if (sek != 0 && min != 0 && timer == 0)
    printf("%d %s og %d %s\n", min, min_enhed, sek, sek_enhed);

  else if (sek != 0 && min == 0 && timer == 0)
    printf("%d %s\n", sek, sek_enhed);

  else if (sek == 0 && min != 0 && timer == 0)
    printf("%d %s\n", min, min_enhed);

  else if (sek == 0 && min == 0 && timer != 0)
    printf("%d %s\n", timer, timer_enhed);

  else
    printf("Invalid input\n");
    
  return 0;
}
