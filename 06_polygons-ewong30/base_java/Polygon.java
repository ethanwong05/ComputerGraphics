import java.util.*;
import java.io.*;
import java.awt.*;

public class Polygon {

  private double[] p0;
  private double[] p1;
  private double[] p2;

  private double[] normal;
  private Color c;

  public Polygon(double[] pt0, double[] pt1, double[] pt2, Color co) {
    p0 = Arrays.copyOf(pt0, 3);
    p1 = Arrays.copyOf(pt1, 3);
    p2 = Arrays.copyOf(pt2, 3);
    normal = new double[3];
    calculateNormal();
    c = co;
  }//constructor

  public double[] getNormal() {
    return normal;
  }//getNormal

  private void calculateNormal() {
    double[] A = new double[3];
    double[] B = new double[3];

    A[0] = p1[0] - p0[0];
    A[1] = p1[1] - p0[1];
    A[2] = p1[2] - p0[2];

    B[0] = p2[0] - p0[0];
    B[1] = p2[1] - p0[1];
    B[2] = p2[2] - p0[2];

    normal[0] = A[1] * B[2] - A[2] * B[1];
    normal[1] = A[2] * B[0] - A[0] * B[2];
    normal[2] = A[0] * B[1] - A[1] * B[0];

  }//calculateNormal

}//class Polygon
