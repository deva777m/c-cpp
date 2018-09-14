#include<iostream>

int count(int a)
{
	int counter = 0;	

	while(a)
	{
		a /= 10;
	
		++counter;
	}

return counter;
}

int power(int number, int base)
{
	int pow = 1;

	for(int i = 0; i < base; ++i)
	{
		pow *= number;
	}

return pow;
}

int main()
{
	int a,b,c,d,num = 0;;

	std::cout << "Enter number : - ";
	std::cin >> a;

	int x = count(a);

	while(x--)
	{
		b = a/10;
		d = a % 10;
		a = b;
		num += d * power(10,x);		
	}
	
	std::cout << num << '\n';
}
