#include<stdio.h>
int main()
{
 int y,n,i=2;
 scanf("%d",&n);
 while(i<=2*n)
  {
   if(n%i==0)
       {
          y=n/i;
          printf("%d ",i);
          n=y;
          i=2;
          continue;
       }
  else if(n==1)
   {
   break;
   }  

   else if(n%i!=0)
    {
      i++;
      continue;
    }
 i++;
  }
}
 

