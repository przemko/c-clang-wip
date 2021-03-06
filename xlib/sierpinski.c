// sierpinski.c
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
  
  double x = 0.0;
  double y = 400.0;
  
  for(;;)
    {
      switch(rand() % 3)
	{
	case 0:
	  x = x / 2.0;
	  y = (y + 400)/ 2.0;
	  break;
	case 1:
	  x = (x + 200.0) / 2.0;
	  y = y / 2.0;
	  break;
	case 2:
	  x = (x + 400.0) / 2.0;
	  y = (y + 400.0) / 2.0;
	}
      XDrawPoint(display, window, DefaultGC(display, screen), (int)x, (int)y);
      XFlush(display);
    }
}
