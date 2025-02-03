#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>


int main() {

  int XRES = 500;
  int YRES = 500;
  int MAX_COLOR = 255;
  
  int fd;
  char line[20];


  fd = open("image.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644);
  snprintf(line,  sizeof(line), "P3 %d %d %d\n", XRES, YRES, MAX_COLOR);
  write(fd, line, strlen(line));


  close(fd);
}
