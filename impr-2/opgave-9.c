# include <stdio.h>
# include <stdlib.h>

# define FOOT 0.6096


int main(void) {

  double g_len = 0.0, g_wid = 0.0, g_area = 0.0;
  double h_len = 0.0, h_wid = 0.0, h_area = 0.0;
  double netto_area = 0.0;
  double time = 0.0;
  double speed = 0.0;

  printf("Input lawn length and width: ");
  scanf("%lf%lf", &g_len, &g_wid);

  printf("Input house length and width: ");
  scanf("%lf%lf", &h_len, &h_wid);

  g_area = g_len * g_wid;
  h_area = h_len * h_wid;

  if (h_area > g_area) {
    printf("Don't\n");
    return 0;

  }

  netto_area = g_area - h_area;

  time = netto_area;

  printf("\nLawn area: %.2f\nHouse area: %.2f\nNetto area: %.2f\n", g_area, h_area, netto_area);
  printf("Time to cut (At the speed of 1 m^2 per second): %.2f\n", time);


  /* 1 m^2 per sekund */
  
  return 0;
}
