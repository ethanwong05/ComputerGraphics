#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  color c;
  c.red = 0;
  c.green = 255;
  c.blue = 0;
  struct matrix *edges;
  struct matrix *m1;
  struct matrix *m2;
  struct matrix *porygon;
  struct matrix *porygon_r;
  struct matrix *porygon_w;

  edges = new_matrix(4, 4);
  m1 = new_matrix(4, 4);
  m2 = new_matrix(4, 4);
  porygon = new_matrix(4, 4);
  porygon_r = new_matrix(4,4);
  porygon_w = new_matrix(4,4);

  printf("\nTesting add_edge. Adding (1, 2, 3), (4, 5, 6) m2 =");
  add_edge(m2, 1, 2, 3, 4, 5, 6);
  print_matrix( m2 );

  printf("Testing ident. m1 = ");
  ident(m1);
  print_matrix( m1 );

  printf("\nTesting matrix_mult. m1 * m2 =");
  matrix_mult(m1, m2);
  print_matrix(m2);

  m1 = new_matrix(4, 4);
  add_edge(m1, 1, 2, 3, 4, 5, 6);
  add_edge(m1, 7, 8, 9, 10, 11, 12);
  printf("\nTesting Matrix mult. m1 =");
  print_matrix(m1);
  printf("\nTesting Matrix mult. m1 * m2 =");
  matrix_mult(m1, m2);
  print_matrix(m2);

  add_edge(edges, 50, 450, 0, 100, 450, 0);
  add_edge(edges, 50, 450, 0, 50, 400, 0);
  add_edge(edges, 100, 450, 0, 100, 400, 0);
  add_edge(edges, 100, 400, 0, 50, 400, 0);

  add_edge(edges, 200, 450, 0, 250, 450, 0);
  add_edge(edges, 200, 450, 0, 200, 400, 0);
  add_edge(edges, 250, 450, 0, 250, 400, 0);
  add_edge(edges, 250, 400, 0, 200, 400, 0);

  add_edge(edges, 150, 400, 0, 130, 360, 0);
  add_edge(edges, 150, 400, 0, 170, 360, 0);
  add_edge(edges, 130, 360, 0, 170, 360, 0);

  add_edge(edges, 100, 340, 0, 200, 340, 0);
  add_edge(edges, 100, 320, 0, 200, 320, 0);
  add_edge(edges, 100, 340, 0, 100, 320, 0);
  add_edge(edges, 200, 340, 0, 200, 320, 0);

  draw_lines(edges, s, c);
  save_extension(s, "bob.png");

  // c.red = 61;
  // c.green = 120;
  // c.blue = 183;
  // add_edge(porygon, 25, 419, 0, 75, 606, 0); //a to b
  // add_edge(porygon, 263, 563, 0, 75, 606, 0); //c to b
  // add_edge(porygon, 25, 419, 0, 125, 388, 0); //a to d
  // add_edge(porygon, 263, 563, 0, 125, 388, 0);//c to d
  // add_edge(porygon, 263, 563, 0, 275, 538, 0);//c to e
  // add_edge(porygon, 125, 388, 0, 275, 538, 0);//d to e
  // add_edge(porygon, 300, 450, 0, 275, 538, 0);// f to e
  // add_edge(porygon, 125, 388, 0, 300, 450, 0);//d to f
  //
  // add_edge(porygon, 319, 463, 0, 263, 300, 0);//g to h
  // add_edge(porygon, 550, 250, 0, 263, 300, 0);//i to h
  // add_edge(porygon, 550, 250, 0, 488, 544, 0);//i to j
  // add_edge(porygon, 263, 300, 0, 470, 181, 0);//h to k
  // add_edge(porygon, 613, 138, 0, 470, 181, 0);//l to k
  // add_edge(porygon, 300, 213, 0, 310, 270, 0);//n to m
  // add_edge(porygon, 300, 213, 0, 325, 200, 0);//n to p
  // add_edge(porygon, 300, 213, 0, 200, 256, 0);//n to q
  // add_edge(porygon, 222, 420, 0, 200, 256, 0);//r to q
  // add_edge(porygon, 356, 248, 0, 325, 200, 0);//o to p
  //
  // add_edge(porygon, 641, 94, 0, 700, 433, 0);//s to t
  // add_edge(porygon, 875, 358, 0, 700, 433, 0);//u to t
  // add_edge(porygon, 813, 475, 0, 700, 433, 0);//v to t
  // add_edge(porygon, 813, 475, 0, 969, 413, 0);//v to w
  // add_edge(porygon, 875, 358, 0, 969, 413, 0);//u to w
  // add_edge(porygon, 963, 319, 0, 969, 413, 0);//x to w
  // add_edge(porygon, 963, 319, 0, 813, 6, 0);//x to y
  // add_edge(porygon, 790, 44, 0, 813, 6, 0);//z to y
  // add_edge(porygon, 790, 44, 0, 875, 358, 0);//z to u
  // add_edge(porygon, 790, 44, 0, 641, 94, 0);//z to s
  // add_edge(porygon, 813, 6, 0, 656, 63, 0);//y to a0
  // add_edge(porygon, 656, 63, 0, 641, 94, 0);//a0 to s
  //
  // add_edge(porygon, 800, 513, 0, 816, 516, 0);//b0 to c0
  // add_edge(porygon, 850, 950, 0, 816, 513, 0);//d0 to c0
  // add_edge(porygon, 850, 950, 0, 831, 988, 0);//d0 to e0
  // add_edge(porygon, 753, 588, 0, 831, 988, 0);//f0 to e0
  // add_edge(porygon, 803, 994, 0, 831, 988, 0);//h0 to e0
  // add_edge(porygon, 803, 994, 0, 688, 613, 0);//h0 to e0
  //
  // draw_lines( porygon, s, c );
  //
  // c.red = 205;
  // c.green = 99;
  // c.blue = 96;
  //
  // add_edge(porygon_r, 225, 838, 0, 75, 606, 0);
  // add_edge(porygon_r, 225, 838, 0, 425, 788, 0);
  // add_edge(porygon_r, 225, 838, 0, 356, 925, 0);
  // add_edge(porygon_r, 478, 900, 0, 356, 925, 0);
  // add_edge(porygon_r, 478, 900, 0, 588, 775, 0);
  // add_edge(porygon_r, 475, 738, 0, 588, 775, 0);
  // add_edge(porygon_r, 478, 900, 0, 425, 788, 0);
  // add_edge(porygon_r, 475, 738, 0, 425, 788, 0);
  // add_edge(porygon_r, 555, 638, 0, 588, 775, 0);
  // add_edge(porygon_r, 555, 638, 0, 413, 500, 0);
  // add_edge(porygon_r, 300, 450, 0, 413, 500, 0);
  // add_edge(porygon_r, 478, 738, 0, 456, 638, 0);
  // add_edge(porygon_r, 350, 611, 0, 456, 638, 0);
  // add_edge(porygon_r, 350, 611, 0, 275, 538, 0);
  // add_edge(porygon_r, 350, 611, 0, 300, 663, 0);
  // add_edge(porygon_r, 263, 563, 0, 300, 663, 0);
  // add_edge(porygon_r, 263, 563, 0, 338, 775, 0);
  // add_edge(porygon_r, 338, 775, 0, 425, 788, 0);
  //
  // add_edge(porygon_r, 475, 563, 0, 488, 550, 0);
  // add_edge(porygon_r, 719, 619, 0, 488, 550, 0);
  // add_edge(porygon_r, 719, 619, 0, 513, 599, 0);
  // add_edge(porygon_r, 719, 619, 0, 800, 550, 0);
  // add_edge(porygon_r, 808, 469, 0, 800, 550, 0);
  // add_edge(porygon_r, 475, 563, 0, 594, 428, 0);
  // add_edge(porygon_r, 550, 250, 0, 594, 428, 0);
  // add_edge(porygon_r, 550, 250, 0, 613, 138, 0);
  // add_edge(porygon_r, 656, 200, 0, 613, 138, 0);
  // add_edge(porygon_r, 550, 250, 0, 800, 550, 0);
  //
  // // draw_lines( porygon_r, s, c );
  //
  // c.red = 255;
  // c.green = 255;
  // c.blue = 255;
  //
  // int x = 388;
  // int y = 710;
  //
  // for(int i = 0; i < 500; i++) {
  //
  //   add_edge(porygon_w, 388, 700, 0, x, y, 0);
  //   if((x < 398 && x >= 388) && (y >= 700 && y <= 710)) {
  //     x+=2;
  //     y-=2;
  //   }
  //   else if((x <= 398 && x > 388) && (y <= 700 && y > 690)) {
  //     x-=2;
  //     y-=2;
  //   }
  //   else if((x <= 388 && x > 378) && (y < 700 && y >= 690)) {
  //     x-=2;
  //     y+=2;
  //   }
  //   else if((x < 388 && x >= 378) && (y >= 700 && y < 710)) {
  //     x+=2;
  //     y+=2;
  //   }
  // }
  //
  // draw_lines( porygon_w, s, c );





  save_extension(s, "bob.png");
  // display(s);
}
