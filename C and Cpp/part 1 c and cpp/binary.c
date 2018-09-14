#include<stdio.h>
int main()
{
 int x,y;
 scanf("%d",&x);
 do
 {
 y=x/2;
 printf("%d",x%2);
 x=y;
 }while(y>=1);
}
