#include<iostream>

int main()  // 0 1 1 2 3 5 
{
	int a = 0,b = 1;
	
	long long int c = 0, sum = 0;

	while(true)
	{
		
		c = a + b;
		a = b;
		b = c;
		
		if(c % 2 ==0)
		{
			sum += c;
		}
		
		if(c > 4'000'000)
		{
			break;
		}
	}

	std::cout << sum << '\n';

return 0;
}
