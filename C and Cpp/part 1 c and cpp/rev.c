#include<stdio.h>
int main()
{
  int i,r,c;
  scanf("%d",&i);
  r=i%10;
  c=(r*10)+(i/10);
  printf("%d",c);
}  

