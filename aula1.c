#define PI 3.14159265359

#include <stdio.h>
#include <stdlib.h>

void  calc_esfera  (float  r,  float* area, float* volume);

int main ()
{
  float r = 2;
  float *a, *v;

  printf("Digite r: \n");
  scanf("%f", &r);
  printf("area: %f volume: %f", *a, *v);
  calc_esfera(r, a, v);

  printf("area: %f volume: %f", *a, *v);

  system ("read -p 'Press Enter to continue...' var");
  return 0;
}

void  calc_esfera  (float  r,  float* area, float* volume)
{
    float ar, vol;
    ar = 4*PI*r*r;
    area = &ar;
    vol = ar*r/3;
    volume = &vol;
}
