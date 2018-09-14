#include<stdio.h>
int main()
{
  int i=4,*j,*p;
  j=&i;
  p=j+1;
  printf("%u %u ",j,p);
  printf("%d\n",i);
}
