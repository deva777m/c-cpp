#include<stdio.h>
int f(int n, int i);
int main()
{
   int r,x,p;
   scanf("%d",&x);
   scanf("%d",&p);
   r=f(x,p);
   printf("%d",r);
}
int f(int n,int i)
{
  
 int y;
  while(i<=50)
  {
   if(n%i==0)
       {
          y=n/i;
          printf("%d ",i);
          n=y;
          i++; 
          f(n,i);
       }
  else if(n==1)
   {
   return 0;
   }  

   else if(n%i!=0)
    {
      i++;
      f(n,i); 
    }
 i++;
  }
}

