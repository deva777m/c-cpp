#include<stdio.h>
int main()
{
  int a[2][2]={ 
                {1,2},
                {3,4}
              };
  int *s[]={a[0],a[1]};
  int **q[]={s,(s+1)};
  printf("%p %p\n",a[0],(a[0]+1));
  printf("%p %p\n",q,(q+1));
}
  
