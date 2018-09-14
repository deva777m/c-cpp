#include<stdio.h>
int main()
{
 int a,b,temp;
 scanf("%d%d",&a,&b);
 if(a>b)
  {
    temp=a;
    b=a;
    b=temp;
  }
printf("%d%d",a,b);
}

    
