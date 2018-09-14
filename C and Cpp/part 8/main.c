#include<stdio.h>

int add(int *a, int *b);


int main()
{
	int x = 2,y = 8;

	//scanf("%d,%d",&x,&y);

	printf("x is %d and y is %d\n",x,y);
	

	add(&x,&y);

	printf("x is %d and y is %d\n",x,y);
}

int add(int *a, int *b)
{
	*a = 3;

	*b = 4;
}

