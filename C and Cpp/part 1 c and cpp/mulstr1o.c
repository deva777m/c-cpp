#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
  char *p[6];
  printf("%p %p %p",p,(p+1),(p+2));
}
