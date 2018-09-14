#include<stdio.h>
int main()
{
  int a,i,*j,*k;
  a=2;
  i=3;
  j=&i;
  k=&a;
  printf("value of i before assigning to a is %d\n",i); //3
  printf("value of a before assigning to a is %d\n",a); //2
  printf("address of i before assigning to a is %p\n",&i);
  printf("address of i before assigning to a is %p\n",j);//x
  printf("address of a before assigning is %p\n",&a); 
  printf("address of a before assigning is %p\n",k);     //y
  a=i;
  printf("value of i after assigning to a is %d\n",i);  //2
  printf("value of a after assigning to a is %d\n",a); //2
  printf("address of i after assigning to a is %p\n",&i);
  printf("address of i after assigning to a is %p\n",j); //y
  printf("address of a before assigning to a is %p\n",&a);
  printf("address of a after assigning is %p\n",k);      //y
  printf("%d\n",*j);
  printf("%d\n",*k);
}  
  
  
