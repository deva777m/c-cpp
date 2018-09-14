#include<stdio.h>
int sum(int x,int y);
int main()
{
int a,b,s;
scanf("%d%d",&a,&b);
s=sum(a,b);
printf("%d",s);
}

int sum(int x, int y)
{
 int d;
 d=x+y;
  return d;
}
