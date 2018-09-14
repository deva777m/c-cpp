#include<iostream>

int lcm(int b, int s, int temp)
{
	if(b % s == 0)
	{
		return b;
	}

	lcm(b + temp, s, temp);
}

int main()
{
	int x,y,T;

	std::cin >> T;

	while(T--)
	{
		std::cin >> x >> y;

		std::cout << lcm(x,y,x) << '\n';
	}

return 0;	
}
