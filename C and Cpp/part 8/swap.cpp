#include<iostream>

void swap(int *x, int *y)
{
	std::cout << *x << " " << *y << '\n';

	int temp;
	
	temp = *x;
	*x = *y;
	*y = temp;

	std::cout << *x << " " << *y << '\n';

}

int main()
{
	int x = 3;
	int y = 4;

	std::cout << x << " " << y << '\n';

	swap(&x,&y);

	std::cout << x << " " << y << '\n';

}
