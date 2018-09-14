#include<stdio.h>
int fib();
int main()
//0  1  1  2  3  5  8  13  21
{
  int a=0,b=1,c,i,n; 
  scanf("%d",&n);
  printf("0 1 ");
  for(i=0;i<=n-3;i++)
  {
     c=a+b;
     printf("%d ",c);
     a=b;
     b=c;
  
  }
}
