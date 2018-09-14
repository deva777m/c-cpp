#include<stdio.h>
int display(int *n);
int show(int **m);     
int main()
{
  int i;
  int a[10]={33,22,55,11,66,77};
  for(i=0;i<5;i++)
  display(&a[i]);
}
int show(int **m)
{
   printf("%d ",**m);
}

int display(int *n)
{
  show(&n);
}     

