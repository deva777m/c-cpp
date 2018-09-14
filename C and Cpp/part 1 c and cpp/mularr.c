/*
 The value at address s[2][1] can be represented as *(s[2]+1) or *(*(s+2)+1)  
*/
#include<stdio.h>
int main()
{
  int s[4][2]={1,2,3,4,5,6,7,8};
  int (*p)[2];
  int i,j;
  for(i=0;i<=3;i++)
    {
      p=&s[i];
      printf("\n");
      for(j=0;j<=1;j++)
        printf("%d ",*(*p+j));
    }
   return 0;
}   
       
