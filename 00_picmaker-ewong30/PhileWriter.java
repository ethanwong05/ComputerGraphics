import java.io.*;

public class PhileWriter {
    public static void main(String[] args) {

	int XRES = 500;
	int YRES = 500;
	int MAX_COLOR = 255;

  int R = 0;
  int G = 0;
  int B = 0;

	String ppmFile = "P3\n";
	ppmFile+= XRES + " ";
	ppmFile+= YRES + "\n";
	ppmFile+= MAX_COLOR + "\n";

	try {
	    FileWriter ppmWriter = new FileWriter("image.ppm");
	    ppmWriter.write(ppmFile);
      for(int i = 0; i < YRES; i++) {
        for(int j = 0; j < XRES; j++) {
          R = (int)(0.7 * (Math.pow(i, 2)) + (0.8 * Math.pow(j, 2))) % 255;
          G = (int)(0.5 * (Math.pow(i, 2)) + (0.9 * Math.pow(j, 2))) % 255;
          B = ((int)(Math.pow(i, 2) + Math.pow(j, 2)) % 255);
          ppmFile = "" + R + " " + B + " " + G + "\n";
          ppmWriter.write(ppmFile);
         }
      }
      ppmWriter.close();
	}
	catch(IOException e) {
	    System.out.println("Unable to write to file");
	    e.printStackTrace();
	}
    }//main
}//PhileWriter
