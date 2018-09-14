#include<iostream>

class foo
{
public:

	static int m_x;

	static void fuckoff();
	
	
};

int foo::m_x = 1;

void foo::fuckoff()
{
	std::cout << "Told you to fuckoff\n";
}

int main()
{
	foo::m_x = 2;

	foo::fuckoff();
}
