#ifndef CEL_H
#define CEL_H

#include"fah.h"
class Celsius {

private:
	double m_celsius;

public:

	Celsius(double celsius=0.0)
			:m_celsius(celsius){}

	
	operator Fahrenheit() {return Fahrenheit(m_celsius*9/5+32.0);}
   	operator double() {return m_celsius;}
};

#endif
