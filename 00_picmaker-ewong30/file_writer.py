
XRES = 500
YRES = 500
MAX_COLOR = 255

picfile = open("image.ppm", "w")

ppm_string = f'P3 %d %d %d\n'%(XRES, YRES, MAX_COLOR)

picfile.write(ppm_string)



picfile.close();
