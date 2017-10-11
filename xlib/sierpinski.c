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
				      20, 20, 200, 200, 1,
				      BlackPixel(display, screen),
				      WhitePixel(display, screen));
  XSelectInput(display, window, ExposureMask | KeyPressMask);
  
  XMapWindow(display, window);
  
  int n = 20000;
  double x[n];
  double y[n];
  x[0] = 0.0;
  y[0] = 0.0;
  for(int i = 1; i < n; i++)
    switch(rand() % 3)
      {
      case 0:
	x[i] = x[i-1] / 2.0;
	y[i] = (y[i-1] + 200)/ 2.0;
	break;
      case 1:
	x[i] = (x[i-1] + 100.0) / 2.0;
	y[i] = y[i-1] / 2.0;
	break;
      case 2:
	x[i] = (x[i-1] + 200.0) / 2.0;
	y[i] = (y[i-1] + 200.0) / 2.0;
      }
  
  XEvent event;
  while(1)
    {
      XNextEvent(display, &event);
      
      switch(event.type)
	{
    	case Expose:
	  for(int i = 0; i < n; i++)
	    XDrawPoint(display, window, DefaultGC(display, screen),
		       (int)x[i], (int)y[i]);
	  break;
    	case KeyPress:
	  XDestroyWindow(display, window);
	  XCloseDisplay(display);
	  exit(0);
	}
    }
}
