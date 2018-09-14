#include<stdio.h>
int prime(int n);
int rev(int i);
int main()
{
int a,q,t,s;
printf("Enter a number\n");
scanf("%d",&a);
q=prime(a);
s=rev(a);
t=prime(s);
if(q!=0&&t!=0)
printf("%d is twisted prime\n",a);
else
printf("%d is not a twisted prime\n",a);
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
  
int rev(int i)
{
  int r,c;
  r=i%10;
  c=(r*10)+(i/10);
  return c;
}  
     
