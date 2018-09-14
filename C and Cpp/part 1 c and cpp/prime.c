#include<stdio.h>
int main()
{
 int x,i,n;
 scanf("%d",&n);
  for(i=3;i<=n;i++)
   {
    if(n%(i-1)==0)
     {
       printf("not prime\n");
      break;
     }
    else if(n==i)  
     {
       printf("prime");
     }
 
    }
 if(n==2)
     {
       printf("prime\n");
     }
   
}

 
