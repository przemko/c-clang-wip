// julia.c
//
// Uwaga: wymaga zainstalowania pakietu libx11-dev

#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
  Display *display = XOpenDisplay(NULL);
  int screen = DefaultScreen(display);
  Window window = XCreateSimpleWindow(
				      display, XRootWindow(display, screen),
				      20, 20, 640, 480, 1,
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
  
  double c_re = -0.512511498387847167;
  double c_im =  0.521295573094847167;
  double dbound = 300.0;
  int maxdepth  = 100;
  
  struct Item {
    double z_re;
    double z_im;
    int label;
    double deriv;
    struct Item* next;
  };

  struct Item* top = malloc(sizeof(struct Item));
  top->z_re = 0.0;
  top->z_im = 0.0;
  top->label = 0;
  top->deriv = 1.0;
  top->next = NULL;
 
  int counter = 0; 
  while(top != NULL)
    {
      double re = top->z_re;
      double im = top->z_im;
      int label = top->label;
      double deriv = top->deriv;
      struct Item* temp = top->next;
      free(top);
      top = temp;
      int x = (int) (640.0 * (re + 1.5) / 3.0);
      int y = (int) (480.0 * (1.0 - im) / 2.0);
      if(x >= 0 && x < 640 && y >= 0 && y < 480)
	{
	  counter++;
	  XDrawPoint(display, window, DefaultGC(display, screen), x, y);
	  XFlush(display);
	}
      if(label < maxdepth && deriv < dbound)
	{
	  //(re,im) = sqrt ((re,im) - c);
	  re = re - c_re;
	  im = im - c_im;
	  double r = sqrt(re*re + im*im);
	  double re1 = sqrt((r + re) / 2.0);
	  if(im >= 0.0)
	    im = sqrt((r - re) / 2.0);
	  else
	    im = -sqrt((r - re) / 2.0);
	  re = re1;
	  
	  label++;
	  deriv = 2.0 * deriv * sqrt(re*re + im*im);
	  temp = top;
	  top = malloc(sizeof(struct Item));
	  top->z_re = re;
	  top->z_im = im;
	  top->label = label;
	  top->deriv = deriv;
	  top->next = malloc(sizeof(struct Item));
	  top->next->z_re = -re;
	  top->next->z_im = -im;
	  top->next->label = label;
	  top->next->deriv = deriv;
	  top->next->next = temp;
	}
    }
  printf("liczba punktów = %d\n", counter);
  printf("naciśnij Ctrl-c\n"); 
  for(;;);
}
