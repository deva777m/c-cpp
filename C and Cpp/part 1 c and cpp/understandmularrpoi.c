#include<stdio.h>
int main()
{
  int s[4][2]={1,2,3,4,5,6,7,8};
  int (*p)[2];
  p=&s[0];
  printf("%d\n",s[0][0]);
  printf("%d\n",*s[0]);
  printf("%p\n",s);
  printf("%p\n",*s);
  printf("%d\n",*(*p));  
  printf("%p\n",s[0]);   
  printf("%p\n",&s[0]);
  printf("%p\n",p);      
  printf("%p\n",*p);     
  printf("%p\n",&p);     
  
return 0;
}   
       
  
  
