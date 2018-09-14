#include<stdio.h>
int main()
{
 int x,y,i,q[20],d,c=0;
 scanf("%d",&x);
 for(i=0;;i++)
 {
	if(x>=1)
	{
	y=x/2;
 	printf("%d",x%2);
	d=x%2;
	q[i]=d;
 	x=y;
	c++;
	}
	else
	break;
 }
printf("\n");
for(i=0;i<c;i++)
{
printf("%d",q[c-i-1]);
}
return 0;
}
