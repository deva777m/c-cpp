#include<stdio.h>
int div(int n);
int main()
{
  int a,s;
  scanf("%d",&a);
  s=div(a);
  printf("%d",s);

}
int div(int n)
{
  int f;
  if(n/10==0)
  return n;
  else
  f=n%10+div(n/10);

  return f;
}
