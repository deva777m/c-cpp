#include<stdio.h>
int main()
{
  char *p[]=  {
                    "",
                    "a",
                    "simiran",
                    "nigga"
              };
 printf("%p %p\n",p[2],p[3]);
 printf("%p %p\n",p,(p+1));
}     
