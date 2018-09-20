#include <X11/Xlib.h>

int main(void)
{
  Display *display = XOpenDisplay(NULL);
  int screen = DefaultScreen(display);
  int depth = DefaultDepth(display, screen);
  Visual *visual = DefaultVisual(display, screen);
  XSetWindowAttributes attributes;
  attributes.background_pixel = XWhitePixel(display, screen);
  Window = XCreateWindow(display, XRootWindow(display, screen),
			 200, 200, 350, 200, 5, depth, InputOutput,
			 visual, CWBackPixel, &attributes);
  
  while(1);

}
