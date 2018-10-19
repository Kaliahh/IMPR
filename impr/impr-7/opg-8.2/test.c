// Diagonal lines

#include <stdlib.h>
#include <stdio.h>
#include "ppm.h"

int main(void) {

  ppm *img = make_image(50, 50,  make_pixel(255U, 0U, 255U));  // white
  int i;

  pixel black_pixel = make_pixel(0U, 0U, 0U);

  for (int i = 0; i < 25; i++) {
    set_pixel(img, image_width(img) / 2, i, black_pixel);
    set_pixel(img, image_height(img) / 2, i, black_pixel); 
  }

  write_image(img, "img2.pnm");

  return 0;
}
