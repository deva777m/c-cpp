#include<stdio.h>
int prime(int n);
int main()
{
int a,q;   
printf("Enter a number\n");
scanf("%d",&a);
q=prime(a);
printf("%d",q);
}

int prime(int n)
{
  int i;
for(i=3;i<=n;i++)
   {
    if(n%(i-1)==0)
     {
       return 0;
      break;
     }
    else if(n==i)  
     {
       return n;
     }
 
    }
 if(n==2)
     {
       printf("prime\n");
     }
   
}


