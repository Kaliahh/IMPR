# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int main(void) {


  float t = 0, sek = 0, min = 0, timer = 0, dage = 0, uger = 0;
  char u[100];


  
  printf("Du kan indtaste sek, min, timer, dage, uger som enhed\n");
  printf("Du kan skrive exit for at afslutte\n");
  printf("Indtast antal og enhed: ");
  scanf("%f %s", &t, u);
  printf("\n");


  if (strcmp(u, "sek") == 0) {

    sek = t;
    min = t / 60;
    timer = t / 3600;
    dage = t / 86400;
    uger = t / 604800;

    printf("Uger: %.3f\nDage: %.3f\nTimer: %.3f\nMinutter: %.3f\nSekunder: %.3f\n\n",
	   uger,
	   dage,
	   timer,
	   min,
	   sek);

  }

  else if (strcmp(u, "min") == 0) {

    sek = t * 60;
    min = t;
    timer = t / 60;
    dage = t / 3600;
    uger = t / 86400;

    printf("Uger: %.3f\nDage: %.3f\nTimer: %.3f\nMinutter: %.3f\nSekunder: %.3f\n\n",
	   uger,
	   dage,
	   timer,
	   min,
	   sek);
    
  }

  else if (strcmp(u, "timer") == 0) {

    sek = t * 3600;
    min = t * 60;
    timer = t;
    dage = t / 24;
    uger = t / 168;

    printf("Uger: %.3f\nDage: %.3f\nTimer: %.3f\nMinutter: %.3f\nSekunder: %.3f\n\n",
	   uger,
	   dage,
	   timer,
	   min,
	   sek);


  }

  else if (strcmp(u, "dage") == 0) {

    sek = t * 86400;
    min = t * 3600;
    timer = t * 24;
    dage = t;
    uger = t / 7;

    printf("Uger: %.3f\nDage: %.3f\nTimer: %.3f\nMinutter: %.3f\nSekunder: %.3f\n\n",
	   uger,
	   dage,
	   timer,
	   min,
	   sek);

  }

  else if (strcmp(u, "uger") == 0) {

    sek = t * 604800;
    min = t * 10080;
    timer = t * 168;
    dage = t * 7;
    uger = t;

    printf("Uger: %.3f\nDage: %.3f\nTimer: %.3f\nMinutter: %.3f\nSekunder: %.3f\n\n",
	   uger,
	   dage,
	   timer,
	   min,
	   sek);

    
  }

  else if (strcmp(u, "exit") == 0) {
    return 0;

  }
  
  return 0;
 

}
