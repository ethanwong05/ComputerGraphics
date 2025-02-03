run: Main.class
	java Main script

Main.class: Main.java Screen.class Matrix.class EdgeMatrix.class
	javac Main.java

Matrix.class: Matrix.java
	javac Matrix.java

EdgeMatrix.class: EdgeMatrix.java Matrix.java Screen.class
	javac EdgeMatrix.java

Screen.class: Screen.java
	javac Screen.java

clean:
	rm *.class
