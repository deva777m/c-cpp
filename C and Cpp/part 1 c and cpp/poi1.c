#include<stdio.h>
int main()
{
  int i,a[5]={1,2,3};
  int (*q)[3];
  for(i=0;i<=2;i++)
  {
  q=(a+i);
  printf("%u\n",q);
  printf("%u\n",*(&q));
  printf("%u\n",*q);
  printf("%u\n",q[0]);
  printf("%d\n",*(a+i));
  }
}
