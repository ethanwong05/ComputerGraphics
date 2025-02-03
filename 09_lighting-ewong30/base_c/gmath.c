
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gmath.h"
#include "matrix.h"
#include "ml6.h"


/*============================================
  IMPORANT NOTE

  Ambient light is represeneted by a color value

  Point light sources are 2D arrays of doubles.
       - The fist index (LOCATION) represents the vector to the light.
       - The second index (COLOR) represents the color.

  Reflection constants (ka, kd, ks) are represened as arrays of
  doubles (red, green, blue)
  ============================================*/


//lighting functions
color get_lighting( double *normal, double *view, color alight, double light[2][3], double *areflect, double *dreflect, double *sreflect) {
  color i;
  color a, d, s;

  a = calculate_ambient(alight, areflect);
  d = calculate_diffuse(light, dreflect, normal);
  s = calculate_specular(light, sreflect, view, normal);

  unsigned short ir = 0;
  unsigned short ig = 0;
  unsigned short ib = 0;

  ir += a.red;
  ir += d.red;
  ir += s.red;
  ig += a.green;
  ig += d.green;
  ig += s.green;
  ib += a.blue;
  ib += d.blue;
  ib += s.blue;

  if(ir < 0){
    ir = 0;
  }
  if(ir > 255){
    ir = 255;
  }
  if(ig < 0){
    ig = 0;
  }
  if(ig > 255){
    ig = 255;
  }
  if(ib < 0){
    ib = 0;
  }
  if(ib > 255){
    ib = 255;
  }

  i.red = (unsigned char) ir;
  i.green = (unsigned char) ig;
  i.blue = (unsigned char) ib;
  return i;
}

color calculate_ambient(color alight, double *areflect ) {
  color a;
  a.red = alight.red * areflect[0];
  a.green = alight.green * areflect[1];
  a.blue = alight.blue * areflect[2];
  return a;
}

color calculate_diffuse(double light[2][3], double *dreflect, double *normal ) {
  color d;
  double dotp;
  normalize(light[0]);
  normalize(normal);
  dotp = dot_product(light[0], normal);

  if(dotp < 0) {
    dotp = 0;
  }

  unsigned short dr = 0;
  unsigned short dg = 0;
  unsigned short db = 0;

  dr = light[1][0] * (dreflect[0] * dotp);
  dg = light[1][1] * (dreflect[1] * dotp);
  db = light[1][2] * (dreflect[2] * dotp);

  if(dr < 0){
    dr = 0;
  }
  if(dr > 255){
    dr = 255;
  }
  if(dg < 0){
    dg = 0;
  }
  if(dg > 255){
    dg = 255;
  }
  if(db < 0){
    db = 0;
  }
  if(db > 255){
    db = 255;
  }

  d.red = (unsigned char)dr;
  d.green = (unsigned char)dg;
  d.blue = (unsigned char)db;

  return d;
}

color calculate_specular(double light[2][3], double *sreflect, double *view, double *normal ) {
  color s;
  double dotp, dotp2;
  normalize(light[0]);
  normalize(normal);
  dotp = dot_product(light[0], normal);

  if(dotp < 0) {
    dotp = 0;
  }

  unsigned short sr = 0;
  unsigned short sg = 0;
  unsigned short sb = 0;

  double Nhold[3];

  Nhold[0] = 2 * dotp * normal[0] - light[0][0];
  Nhold[1] = 2 * dotp * normal[1] - light[0][1];
  Nhold[2] = 2 * dotp * normal[2] - light[0][2];

  dotp2 = dot_product(Nhold, view);

  if(dotp2 < 0) {
    dotp2 = 0;
  }

  sr = light[1][0] * (sreflect[0] * dotp2);
  sg = light[1][1] * (sreflect[1] * dotp2);
  sb = light[1][2] * (sreflect[2] * dotp2);

  sr = pow(sr, 2);
  sg = pow(sg, 2);
  sb = pow(sb, 2);

  if(sr < 0){
    sr = 0;
  }
  if(sr > 255){
    sr = 255;
  }
  if(sg < 0){
    sg = 0;
  }
  if(sg > 255){
    sg = 255;
  }
  if(sb < 0){
    sb = 0;
  }
  if(sb > 255){
    sb = 255;
  }

  s.red = (unsigned char)sr;
  s.green = (unsigned char)sg;
  s.blue = (unsigned char)sb;

  return s;
}

//limit each component of c to a max of 255
void limit_color( color * c ) {
}

//vector functions
//normalize vetor, should modify the parameter
void normalize( double *vector ) {
  double magnitude;
  magnitude = sqrt( vector[0] * vector[0] +
                    vector[1] * vector[1] +
                    vector[2] * vector[2] );
  int i;
  for (i=0; i<3; i++) {
    vector[i] = vector[i] / magnitude;
  }
}

//Return the dot porduct of a . b
double dot_product( double *a, double *b ) {
  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}


//Calculate the surface normal for the triangle whose first
//point is located at index i in polygons
double *calculate_normal(struct matrix *polygons, int i) {

  double A[3];
  double B[3];
  double *N = (double *)malloc(3 * sizeof(double));

  A[0] = polygons->m[0][i+1] - polygons->m[0][i];
  A[1] = polygons->m[1][i+1] - polygons->m[1][i];
  A[2] = polygons->m[2][i+1] - polygons->m[2][i];

  B[0] = polygons->m[0][i+2] - polygons->m[0][i];
  B[1] = polygons->m[1][i+2] - polygons->m[1][i];
  B[2] = polygons->m[2][i+2] - polygons->m[2][i];

  N[0] = A[1] * B[2] - A[2] * B[1];
  N[1] = A[2] * B[0] - A[0] * B[2];
  N[2] = A[0] * B[1] - A[1] * B[0];

  return N;
}
