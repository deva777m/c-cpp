#include<stdio.h>
int main()
{
 int i,y,n;
 scanf("%d",&n);
 for(i=2;i<=n;i++)
  {
   if(n%i==0)
       {
          y=n/i;
          printf("%d ",i);
          n=y;
          continue;
       }
  else if(n==1)
   {
   break;
   }  

   else if(n%i!=0)
    {
      continue;
    }
 i++;
  }
}
