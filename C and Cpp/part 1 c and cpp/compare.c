#include<stdio.h>
int main()
{
  int a[100],i,j,temp;
  printf("enter 6 numbers\n");
  for(i=0;i<6;i++)
   {
     scanf("%d",&a[i]);
   }
  
for(j=0;j<6;j++)
 {
  for(i=0;i<6;i++)
  {
    if(a[i]>a[i+1])
     {
       temp=a[i];
       a[i]=a[i+1];
       a[i+1]=temp;
     }
   }
 }
for(i=0;i<6;i++)
  {
   printf("%d",a[i]);
  }
  
}  //6,3,4,2,1,8
   //3,6,4,2,1,8
   //3,4,6,2,1,8
   //3,4,2,6,1,8
   //3,4,2,1,6,8
   
   
   
