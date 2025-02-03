#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;
  clear_screen(s);

  //for graphics submission
  // int cX = ((XRES - 1) / 2) - 60;
  // int cY = ((YRES - 1) / 2) - 60;
  // int xP = 0;
  // int yP = 0;
  // for(int i = 0; i < 1500; i++) {
  //   c.red = rand() % 256;
  //   c.green = rand() % 50;
  //   c.blue = rand() % 256;
  //   if(i == 0) {
  //     xP = ((XRES - 1) / 2) + 60;
  //     yP = ((YRES - 1) / 2) - 60;
  //   }
  //   if(i == 500) {
  //     cX = ((XRES - 1) / 2) + 60;
  //     cY = ((YRES - 1) / 2) - 60;
  //     xP = ((XRES - 1) / 2);
  //     yP = ((YRES - 1) / 2) + 60;
  //   }
  //   if(i == 1000) {
  //     cX = ((XRES - 1) / 2);
  //     cY = ((YRES - 1) / 2) + 60;
  //     xP = ((XRES - 1) / 2) - 60;
  //     yP = ((YRES - 1) / 2) - 60;
  //   }
  //   draw_line(cX, cY, xP, yP, s, c);
  //   xP -= 5;
  //   yP -= 2;
  // }
  // for(int i = 0; i < 1500; i++) {
  //   c.red = rand() % 50;
  //   c.green = rand() % 256;
  //   c.blue = rand() % 256;
  //   if(i == 0) {
  //     xP = ((XRES - 1) / 2) + 60;
  //     yP = ((YRES - 1) / 2) - 60;
  //   }
  //   if(i == 500) {
  //     cX = ((XRES - 1) / 2) + 60;
  //     cY = ((YRES - 1) / 2) - 60;
  //     xP = ((XRES - 1) / 2);
  //     yP = ((YRES - 1) / 2) + 60;
  //   }
  //   if(i == 1000) {
  //     cX = ((XRES - 1) / 2);
  //     cY = ((YRES - 1) / 2) + 60;
  //     xP = ((XRES - 1) / 2) - 60;
  //     yP = ((YRES - 1) / 2) - 60;
  //   }
  //   draw_line(cX, cY, xP, yP, s, c);
  //   xP += 2;
  //   yP += 5;
  // }
  // for(int i = 0; i < 1500; i++) {
  //   c.red = rand() % 256;
  //   c.green = rand() % 256;
  //   c.blue = rand() % 50;
  //   if(i == 0) {
  //     xP = ((XRES - 1) / 2) + 60;
  //     yP = ((YRES - 1) / 2) - 60;
  //   }
  //   if(i == 500) {
  //     cX = ((XRES - 1) / 2) + 60;
  //     cY = ((YRES - 1) / 2) - 60;
  //     xP = ((XRES - 1) / 2);
  //     yP = ((YRES - 1) / 2) + 60;
  //   }
  //   if(i == 1000) {
  //     cX = ((XRES - 1) / 2);
  //     cY = ((YRES - 1) / 2) + 60;
  //     xP = ((XRES - 1) / 2) - 60;
  //     yP = ((YRES - 1) / 2) - 60;
  //   }
  //   draw_line(cX, cY, xP, yP, s, c);
  //   xP += 5;
  //   yP += 2;
  // }
  // for(int i = 0; i < 1500; i++) {
  //   c.red = rand() % 50 + 200;
  //   c.green = rand() % 50 + 100;
  //   c.blue = rand() % 100 + 50;
  //   if(i == 0) {
  //     xP = ((XRES - 1) / 2) + 60;
  //     yP = ((YRES - 1) / 2) - 60;
  //   }
  //   if(i == 500) {
  //     cX = ((XRES - 1) / 2) + 60;
  //     cY = ((YRES - 1) / 2) - 60;
  //     xP = ((XRES - 1) / 2);
  //     yP = ((YRES - 1) / 2) + 60;
  //   }
  //   if(i == 1000) {
  //     cX = ((XRES - 1) / 2);
  //     cY = ((YRES - 1) / 2) + 60;
  //     xP = ((XRES - 1) / 2) - 60;
  //     yP = ((YRES - 1) / 2) - 60;
  //   }
  //   draw_line(cX, cY, xP, yP, s, c);
  //   xP -= 2;
  //   yP -= 5;
  // }

  //octants 1 and 5
  c.green = 255;
  draw_line(0, 0, XRES-1, YRES-1, s, c);
  draw_line(0, 0, XRES-1, YRES / 2, s, c);

  draw_line(XRES-1, YRES-1, 0, YRES / 2, s, c);


  // octants 8 and 4
  c.blue = 255;
  draw_line(0, YRES-1, XRES-1, 0, s, c);
  draw_line(0, YRES-1, XRES-1, YRES/2, s, c);
  draw_line(XRES-1, 0, 0, YRES/2, s, c);

  //octants 2 and 6
  c.red = 255;
  c.green = 0;
  c.blue = 0;
  draw_line(0, 0, XRES/2, YRES-1, s, c);
  draw_line(XRES-1, YRES-1, XRES/2, 0, s, c);

  //octants 7 and 3
  c.blue = 255;
  draw_line(0, YRES-1, XRES/2, 0, s, c);
  draw_line(XRES-1, 0, XRES/2, YRES-1, s, c);

  //horizontal and vertical
  c.blue = 0;
  c.green = 255;
  draw_line(0, YRES/2, XRES-1, YRES/2, s, c);
  draw_line(XRES/2, 0, XRES/2, YRES-1, s, c);

  // display(s);
  save_extension(s, "lines.png");
  save_ppm(s, "binary.ppm");
  save_ppm_ascii(s, "ascii.ppm");
}
