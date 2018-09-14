#include<stdio.h>
int main()
{
  int a[]={0,1,2,3,4};
  int *p[]={a,a+1,a+2,a+3,a+4};
  int **j[]={p,p+1,p+2,p+3,p+4};
  printf("%p %p %p %p %p\n",(void*)p,(void*)(p+1),(void*)(p+2),(void*)(p+3),(void*)(p+4));  
  printf("%p %p %p %p %p\n",*j,*(j+1),*(j+2),*(j+3),*(j+4));
  printf("%lu\n",sizeof(void*));
}


