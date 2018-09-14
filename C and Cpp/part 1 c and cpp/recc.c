#include<stdio.h>
int main()
//12345
{
  int c=0,t=10000,x,y,i,z;
  scanf("%d",&x);
  for(i=0;i<5;i++)
  {
  y=x/t;
  c=c+y;
  z=x%t;
  x=z;    
  t=t/10;
  }
printf("%d\n",c);
   
}
