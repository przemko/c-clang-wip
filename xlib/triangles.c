// triangles.c
//
// Uwaga: wymaga zainstalowania pakietu libx11-dev

#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  Display *display = XOpenDisplay(NULL);
  int screen = DefaultScreen(display);
  Window window = XCreateSimpleWindow(
				      display, XRootWindow(display, screen),
				      20, 20, 400, 400, 1,
				      BlackPixel(display, screen),
				      WhitePixel(display, screen));
  XSelectInput(display, window, StructureNotifyMask);
  XMapWindow(display, window);

  for(;;) {
    XEvent e;
    XNextEvent(display, &e);
    if (e.type == MapNotify)
      break;
  }

  double a = 0.96;
  double b = 1.0 - a;
  double x1 = 0.0;
  double y1 = 0.0;
  double x2 = 200.0;
  double y2 = 400.0;
  double x3 = 400.0;
  double y3 = 0.0;
  
  for(;;)
    {
      XDrawLine(display, window, DefaultGC(display, screen),
		(int)x1, (int)y1, (int)x2, (int)y2);
      XDrawLine(display, window, DefaultGC(display, screen),
		(int)x2, (int)y2, (int)x3, (int)y3);
      XDrawLine(display, window, DefaultGC(display, screen),
		(int)x3, (int)y3, (int)x1, (int)y1);
      XFlush(display);
      double x4 = x1;
      double y4 = y1;
      x1 = a * x1 + b * x2;
      y1 = a * y1 + b * y2;
      x2 = a * x2 + b * x3;
      y2 = a * y2 + b * y3;
      x3 = a * x3 + b * x4;
      y3 = a * y3 + b * y4;
    }
}
