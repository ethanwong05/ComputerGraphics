import java.util.*;
import java.awt.*;

public class EdgeMatrix extends Matrix {

  public void addBox( double x, double y, double z,
                       double width, double height, double depth ) {
    double x0, y0, z0, x1, y1, z1;
    x0 = x;
    x1 = x+width;
    y0 = y;
    y1 = y-height;
    z0 = z;
    z1 = z-depth;

    //front
    addEdge(x0, y0, z0, x1, y0, z0);
    addEdge(x1, y0, z0, x1, y1, z0);
    addEdge(x1, y1, z0, x0, y1, z0);
    addEdge(x0, y1, z0, x0, y0, z0);

    //back
    addEdge(x0, y0, z1, x1, y0, z1);
    addEdge(x1, y0, z1, x1, y1, z1);
    addEdge(x1, y1, z1, x0, y1, z1);
    addEdge(x0, y1, z1, x0, y0, z1);

    //sides
    addEdge(x0, y0, z0, x0, y0, z1);
    addEdge(x1, y0, z0, x1, y0, z1);
    addEdge(x1, y1, z0, x1, y1, z1);
    addEdge(x0, y1, z0, x0, y1, z1);
  }//addBox

  public void addSphere( double cx, double cy, double cz,
                         double r, int step ) {

    Matrix points = generateSphere(cx, cy, cz, r, step);
    int index, lat, longt;
    int latStop, longStop, latStart, longStart;
    latStart = 0;
    latStop = step;
    longStart = 0;
    longStop = step;

    step++;
    for ( lat = latStart; lat < latStop; lat++ ) {
      for ( longt = longStart; longt <= longStop; longt++ ) {

        index = lat * (step) + longt;
        double[] point = points.get(index);

        addEdge( point[0], point[1], point[2],
                 point[0]+1, point[1]+1, point[2]+1);
      }
    }
  }//addSphere

  private Matrix generateSphere(double cx, double cy, double cz,
                                double r, int step ) {

    Matrix points = new Matrix();
    int circle, rotation, rot_start, rot_stop, circ_start, circ_stop;
    double x, y, z, rot, circ;

    rot_start = 0;
    rot_stop = step;
    circ_start = 0;
    circ_stop = step;

    for (rotation = rot_start; rotation < rot_stop; rotation++) {
      rot = (double)rotation / step;

      for(circle = circ_start; circle <= circ_stop; circle++){
        circ = (double)circle / step;

        x = r * Math.cos(Math.PI * circ) + cx;
        y = r * Math.sin(Math.PI * circ) *
          Math.cos(2*Math.PI * rot) + cy;
        z = r * Math.sin(Math.PI * circ) *
          Math.sin(2*Math.PI * rot) + cz;

        /* printf("rotation: %d\tcircle: %d\n", rotation, circle); */
        /* printf("rot: %lf\tcirc: %lf\n", rot, circ); */
        /* printf("sphere point: (%0.2f, %0.2f, %0.2f)\n\n", x, y, z); */
        points.addColumn(x, y, z);
      }
    }
    return points;
  }//generateSphere

  public void addTorus( double cx, double cy, double cz,
                        double r0, double r1, int step ) {

    Matrix points = generateTorus(cx, cy, cz, r0, r1, step);
    int index, lat, longt;
    int latStop, longStop, latStart, longStart;
    latStart = 0;
    latStop = step;
    longStart = 0;
    longStop = step;

    for ( lat = latStart; lat < latStop; lat++ ) {
      for ( longt = longStart; longt < longStop; longt++ ) {

        index = lat * (step) + longt;
        double[] point = points.get(index);

        addEdge( point[0], point[1], point[2],
                 point[0]+1, point[1]+1, point[2]+1);
      }
    }
  }//addTorus

  private Matrix generateTorus(double cx, double cy, double cz,
                               double r0, double r1, int step ) {

    Matrix points = new Matrix();
    int circle, rotation, rot_start, rot_stop, circ_start, circ_stop;
    double x, y, z, rot, circ;

    rot_start = 0;
    rot_stop = step;
    circ_start = 0;
    circ_stop = step;

    for (rotation = rot_start; rotation < rot_stop; rotation++) {
      rot = (double)rotation / step;

      for(circle = circ_start; circle < circ_stop; circle++){
        circ = (double)circle / step;

        x = Math.cos(2*Math.PI * rot) *
          (r0 * Math.cos(2*Math.PI * circ) + r1) + cx;
        y = r0 * Math.sin(2*Math.PI * circ) + cy;
        z = -1*Math.sin(2*Math.PI * rot) *
          (r0 * Math.cos(2*Math.PI * circ) + r1) + cz;

        /* printf("rotation: %d\tcircle: %d\n", rotation, circle); */
        /* printf("rot: %lf\tcirc: %lf\n", rot, circ); */
        /* printf("sphere point: (%0.2f, %0.2f, %0.2f)\n\n", x, y, z); */
        points.addColumn(x, y, z);
      }
    }
    return points;
  }//generateTorus

  public void addCricle(double cx, double cy, double cz,
                        double r, double step) {
    double x0, y0, x1, y1, t;

    x0 = r + cx;
    y0 = cy;
    for (t=step; t <= 1.00001; t+= step) {

      x1 = r * Math.cos(2 * Math.PI * t) + cx;
      y1 = r * Math.sin(2 * Math.PI * t) + cy;

      addEdge(x0, y0, cz, x1, y1, cz);
      x0 = x1;
      y0 = y1;
    }
  }//addCircle


  public void addCurve( double x0, double y0,
                         double x1, double y1,
                         double x2, double y2,
                         double x3, double y3,
                         double step, int curveType ) {

    double t, x, y;
    Matrix xcoefs = new Matrix(curveType, x0, x1, x2, x3);
    Matrix ycoefs = new Matrix(curveType, y0, y1, y2, y3);

    double[] xm = xcoefs.get(0);
    double[] ym = ycoefs.get(0);

    for (t=step; t <= 1.000001; t+= step) {

      x = xm[0]*t*t*t + xm[1]*t*t+ xm[2]*t + xm[3];
      y = ym[0]*t*t*t + ym[1]*t*t+ ym[2]*t + ym[3];
      addEdge(x0, y0, 0, x, y, 0);
      x0 = x;
      y0 = y;
    }
  }//addCurve

  public void addEdge(double x0, double y0, double z0,
                      double x1, double y1, double z1) {
    double[] col0 = {x0, y0, z0, 1};
    double[] col1 = {x1, y1, z1, 1};
    m.add(col0);
    m.add(col1);
  }//addColumn

  public void drawEdges(Screen s, Color c) {
    if ( m.size() < 2) {
      System.out.println("Need at least 2 edges to draw a line");
      return;
    }//not enough points

    for(int point=0; point<m.size()-1; point+=2) {
      double[] p0 = m.get(point);
      double[] p1 = m.get(point+1);
      s.drawLine((int)p0[0], (int)p0[1], (int)p1[0], (int)p1[1], c);
    }//draw lines
  }//drawEdges


}//class EdgeMatrix
