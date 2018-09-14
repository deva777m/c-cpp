#define PRINT
#include<stdio.h>
#include"f.h"
int main()
{
  #ifdef PRINT
  printf("This is lord Z\n"); 
  printf("d\n");
  #endif
  
  int m,n,z;
  scanf("%d%d",&m,&n);
  z=calsum(m,n);
  printf("%d",z);
}
  
