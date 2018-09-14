#include<iostream>

class Base
{

public:
	
	int m_x;

public:

	Base(int x = 0) : m_x(x)
	{
		std::cout<<"Base constructor called.\n";
	}	

	virtual void function1() { std::cout<<"Fuction1() is called.\n"; }

	virtual void function2() { std::cout<<"Fuction2() is called.\n"; }

};


class D1 : public Base
{

public:
	
	int m_x;

	D1(int x = 0) : m_x(x)
	{
		std::cout<<"D1 constructor is called.\n";
	}
private:

	void function1() { std::cout<<"D1 Fuction1() is called.\n"; }

	void function2() { std::cout<<"D1 Fuction2() is called.\n"; }

};


int main()
{
	D1 d(5);
	
	Base *pb = &d;

	pb->function1();		

return 0;
}
