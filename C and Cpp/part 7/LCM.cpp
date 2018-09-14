#include<iostream>

int lcm(int b, int s)
{
	int temp;

	while(true)
	{
		temp += b;

		if(temp % s == 0)
		{
			return temp;
		}
	}
}

int main()
{
	int x,y,T;

	std::cin >> T;

	while(T--)
	{
		std::cin >> x >> y;

		std::cout << lcm(x,y) << '\n';
	}

return 0;	
}
