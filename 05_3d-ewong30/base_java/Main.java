import java.util.*;
import java.io.*;
import java.awt.*;

public class Main {
  public static void main(String[] args) {

    Color c = Color.GREEN;
    Screen s = new Screen();
    EdgeMatrix edges = new EdgeMatrix();
    Matrix transform = new Matrix();

    if (args.length == 1) {
      //System.out.println(args[0]);
      try {
        gfxParse(new Scanner(new File(args[0])), edges, transform, s, c);
      }
      catch(FileNotFoundException e) {}
    }
    else {
      System.out.println("using system.in");
      gfxParse(new Scanner(System.in), edges, transform, s, c);
    }

  }//main

  public static void gfxParse(Scanner input, EdgeMatrix edges, Matrix transform, Screen s, Color c) {

    String command = "";
    double[] xvals = new double[4];
    double[] yvals = new double[4];
    double[] zvals = new double[4];
    double theta, r0, r1;
    char axis;
    Matrix tmp;
    int curveType;
    int step2d = 10;
    int step3d = 20;

    while (input.hasNext()) {
      command = input.next();
      System.out.println(command);

      if (command.equals("line")) {
        xvals[0] = input.nextDouble();
        yvals[0] = input.nextDouble();
        zvals[0] = input.nextDouble();
        xvals[1] = input.nextDouble();
        yvals[1] = input.nextDouble();
        zvals[1] = input.nextDouble();

        edges.addEdge(xvals[0], yvals[0], zvals[0],
                      xvals[1], yvals[1], zvals[1]);
      }//line


      else if (command.equals("circle")) {
        xvals[0] = input.nextDouble();
        yvals[0] = input.nextDouble();
        zvals[0] = input.nextDouble();
        r0 = input.nextDouble();
        edges.addCricle(xvals[0], yvals[0], zvals[0], r0, step2d);
      }//circle

      else if (command.equals("bezier") || command.equals("hermite")) {
        if (command.equals("bezier"))
          curveType = Matrix.BEZIER;
        else
          curveType = Matrix.HERMITE;
        xvals[0] = input.nextDouble();
        yvals[0] = input.nextDouble();
        xvals[1] = input.nextDouble();
        yvals[1] = input.nextDouble();
        xvals[2] = input.nextDouble();
        yvals[2] = input.nextDouble();
        xvals[3] = input.nextDouble();
        yvals[3] = input.nextDouble();

        edges.addCurve(xvals[0], yvals[0], xvals[1], yvals[1],
                       xvals[2], yvals[2], xvals[3], yvals[3], step2d, curveType);

      }//curve

      else if (command.equals("scale")) {
        xvals[0] = input.nextDouble();
        yvals[0] = input.nextDouble();
        zvals[0] = input.nextDouble();
        tmp = new Matrix(Matrix.SCALE, xvals[0], yvals[0], zvals[0]);
        transform.mult(tmp);
      }//scale

      else if (command.equals("move")) {
        xvals[0] = input.nextDouble();
        yvals[0] = input.nextDouble();
        zvals[0] = input.nextDouble();
        tmp = new Matrix(Matrix.TRANSLATE, xvals[0], yvals[0], zvals[0]);
        transform.mult(tmp);
      }//move

      else if (command.equals("rotate")) {
        axis = input.next().toUpperCase().charAt(0);
        theta = Math.toRadians(input.nextDouble());
        tmp = new Matrix(Matrix.ROTATE, theta, axis);
        transform.mult(tmp);
      }//rotate

      else if (command.equals("ident")) {
        transform.ident();
      }//ident

      else if (command.equals("apply")) {
        edges.mult(transform);
      }//apply

      else if (command.equals("clear")) {
        edges = new EdgeMatrix();
      }//clear edge matrix

      else if (command.equals("display")) {
        s.clearScreen();
        edges.drawEdges(s, c);
        s.display();
      }

      else if (command.equals("save")) {
        command = input.next();
        s.clearScreen();
        edges.drawEdges(s, c);
        s.saveExtension(command);
      }//save

      else if (command.charAt(0) == '#') {
        //comment, ignore
        input.nextLine();
      }
      else {
        System.out.println("invalid command: " + command);
      }
    }//read loop
  }//gfxParse

}
