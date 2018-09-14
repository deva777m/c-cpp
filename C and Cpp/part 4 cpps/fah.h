#ifndef FAH_H
#define FAH_H

class Celsius;

class Fahrenheit {

private:
	double m_fahrenheit;

public:

	Fahrenheit(double fahrenheit=32.0)
			  :m_fahrenheit(fahrenheit){}

	operator Celsius() {return Celsius((m_fahrenheit-32.0)*5/9);}
	operator double() {return m_fahrenheit;}
};

#endif
