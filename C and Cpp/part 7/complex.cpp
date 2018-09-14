#include<iostream>

class Complex
{
private:

	double x;
	double y;

public:

	Complex(double real = 0.0, double img = 0.0)
		: x(real), y(img)
	{
	}


	inline double getReal() { return x;}

	inline double getImg() { return y;}


	friend std::ostream& operator<<(std::ostream &out, const Complex &z);
	
	friend std::istream& operator>>(std::istream &in, Complex &z);	

	friend Complex operator+(const Complex z1, const Complex z2);
};


std::ostream& operator<<(std::ostream &out, const Complex &z)
{
	out << z.x << '+' << z.y << 'i' << '\n';

return out;
}


std::istream& operator>>(std::istream &in, Complex &z)
{
	in >> z.x; 
	in >> z.y;	

return in;
}


Complex operator+(const Complex z1, const Complex z2)
{
	return Complex(z1.x + z2.x , z1.y + z2.y);	
}


int main()
{
	Complex Z(1,1);
	Complex Z1;

	std::cin >> Z1;

	std::cout << Z + Z1;

return 0;
}
