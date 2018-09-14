#include<iostream>

class Base
{
public:
	int m_x{0};

private:
	int m_y{10};

protected:
	int m_z{0};	

protected:

	inline int getNum() { return m_y; }

};

class Derived : protected Base
{
public:
	int m_bx{0};

private:
	int m_by{0};

protected:
	int m_bz{0};	

public:
	void print() { std::cout<<"m_y is "<<getNum(); }

};

int main()
{
	Derived d;

	std::cout<<"m_y is "<<d.getNum()<<'\n';

return 0;
}
