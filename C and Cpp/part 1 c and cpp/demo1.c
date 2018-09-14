#include<stdio.h>
void print(int x);
int main()
{
  int m=1,y=2;
  printf("m=%d, y=%d\n",m,y);
  print(m);
  printf("m=%d, y=%d\n",m,y);
}

void print(int x)
{
   int y=4;
   printf("x=%d, y=%d\n",x,y);
   x=3;
   printf("x=%d, y=%d\n",x,y);
}
