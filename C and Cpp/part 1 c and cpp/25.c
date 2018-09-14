#include<stdio.h>
int rec(int x);
int main()
{
  printf("%d\n",rec(1));  
}
int rec(int x)
{
 int f;
 if(x==25)
   return 25;
 else
   f=x+rec(x+1);
 return f;    
}
 
