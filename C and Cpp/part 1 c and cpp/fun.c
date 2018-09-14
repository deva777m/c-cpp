#include<stdio.h>
extern int i;
int fun()
{
  i++; 
  printf("%d\n",i);
}
