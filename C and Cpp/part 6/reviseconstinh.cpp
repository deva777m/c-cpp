#include<iostream>

class A
{
private:
	int m_a;

public:

	A(int a=0) : m_a(a)
	{
		std::cout<<"Constructor A is called.\n";
	}
};

class B : A
{
private:
	int m_b;

public:

	B(int b=0): m_b(b)
	{
		std::cout<<"Constructor B is called.\n";
	}
};

class C : B
{
private:
	int m_c;

public:

	C(int c=0): m_c(c)
	{
		std::cout<<"Constructor C is called.\n";
	}
};

class D : C
{
private:
	int m_d;

public:

	D(int d=0): m_d(d), A(d)
	{
		std::cout<<"Constructor D is called.\n";
	}
};


int main()
{
 class D d(5);

}
