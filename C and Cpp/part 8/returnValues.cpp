#include<iostream>

int fooVal()
{
	int x = 3;

return x;
}

int* fooPoi(int a , int *b)
{
	int x = 3;
	
	// return &x;    // Execution of both of this statements will give us warning since we are returning the address of a local 
	// return &a;    // variable which will be destroyed after the function block. So we should avoid this

return b;
}

int main()
{
	int x = 2;

	fooPoi(&x);
}
