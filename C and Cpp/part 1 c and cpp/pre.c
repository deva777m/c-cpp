#include<stdio.h>
#define PI 3.14
#define AREA(x) (PI*x*x)
int main()
{
  float a,r;
  scanf("%f",&r);
  a=AREA(r);
  printf("Area is %f\n",a);
}
