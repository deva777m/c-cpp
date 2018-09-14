#include<stdio.h>
int fab(int n);
int main()
{
 int n,x;
 scanf("%d",&n);
 printf("0 1 ");
 x=fab(n);
 printf("%d",x);
}
int fab(int n)
{
   int i,a=0,b=1,c;
   for(i=0;i<=n-3;i++)
  {
     c=a+b;
     return (fab(n-2)+fab(n-1));
     a=b;
     b=c;
  
  }
    
 
}
