#include<stdio.h>
void rec(int x);
int main()
{
  int a;
  scanf("%d",&a);
  rec(a);

}
void rec(int x)
{
    int y;
        y=x/2;
 	printf("%d",x%2);
        x=y;
        if(y>0) 
        rec(x);
       
}
   
  
