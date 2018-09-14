#include<stdio.h>
int main()
{
   int a[3][3]={1,2,3,4,5,6,7,8,9};
   printf("%p %p\n",a,&a+1);
}
