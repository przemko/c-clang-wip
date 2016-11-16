#include <stdio.h>
#include <math.h>

struct punkt
{
  double x;
  double y;
};

struct kolo
{
  struct punkt srodek;
  double promien;
};

double odleglosc(struct punkt p1, struct punkt p2)
{
  return sqrt(pow(p1.x-p2.x, 2) + pow(p1.y-p2.y, 2));
}

int main(void)
{
  struct punkt p1 = {0.0, 0.0};
  struct punkt p2 = {1.0, 1.0};
  struct kolo k1 = {p1, 0.5};
  struct kolo k2 = {p2, 0.9};

  if(k1.promien + k2.promien < odleglosc(k1.srodek, k2.srodek))
    printf("rozlaczne\n");
  else
    printf("maja czesc wspolna\n");
  return 0;
}
