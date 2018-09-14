#include<stdio.h>
int main(void)
{
  int a=20;
  int *j;
  j=&a;
  *j=10; 
  printf("%d",a);
}
  
