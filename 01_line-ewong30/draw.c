#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  int holdX;
  int holdY;
  if(x1 < x0) {
    holdX = x0;
    holdY = y0;
    x0 = x1;
    y0 = y1;
    x1 = holdX;
    y1 = holdY;
  }
  int A = y1 - y0;
  int B = -(x1 - x0);
  int x = x0;
  int y = y0;
  if((A <= -B) && (A > 0)) {
    int d = (2 * A) + B;
    while(x <= x1) {
      plot(s, c, x, y);
      if(d >= 0) {
        y++;
        d+=B;
      }
      x++;
      d+=A;
    }
  }
  else if((A > -B) && (A > 0)) {
    int d = (2 * B) + A;
    while(y <= y1) {
      plot(s, c, x, y);
      if(d < 0) {
        x++;
        d+=A;
      }
      y++;
      d+=B;
    }
  }
  else if((-A <= -B) && (A < 0)) {
    int d = (2 * -A) + B;
    while(x <= x1) {
      plot(s, c, x, y);
      if(d >= 0) {
        y--;
        d+=B;
      }
      x++;
      d-=A;
    }
  }
  else if((-A > -B) && (A < 0)) {
    int d = (2 * B) - A;
    while(y >= y1) {
      plot(s, c, x, y);
      if(d < 0) {
        x++;
        d-=A;
      }
      y--;
      d+=B;
    }
  }
  else if(B == 0) {
    if(y < y1) {
      while(y <= y1) {
        plot(s, c, x, y);
        y++;
      }
    }
    else {
      while(y >= y1) {
        plot(s, c, x, y);
        y--;
      }
    }
  }
  else if(A == 0) {
    while(x <= x1) {
      plot(s, c, x, y);
      x++;
    }
  }
}
