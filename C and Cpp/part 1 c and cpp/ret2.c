#include<stdio.h>
void areaperi(int r,int a,int p);
int main()
{
 int r,area,peri;
 scanf("%d",&r);
 areaperi(r,area,peri);
 printf("%d\n",area);
 printf("%d\n",peri);
}

void areaperi(int r,int a,int p)
{
 a=3.14*r*r;
 p=6.28*r;
}

