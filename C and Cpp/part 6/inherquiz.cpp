#include<iostream>

class Fruit
{
private:

	std::string m_name;
	std::string m_color;
public:

	Fruit(std::string name, std::string color)
	     : m_name(name), m_color(color) {}


	std::string getName() const {return m_name;}


	std::string getColor() const {return m_color;}
};


class Apple : public Fruit
{
private:

	double m_fibre;
public:

	Apple(std::string name, std::string color, double fibre)
	     : m_fibre(fibre), Fruit(name,color) {}


	double getFibre() {return m_fibre;}


	friend std::ostream& operator<<(std::ostream &out, const Apple &apple)
	{
		std::cout<<"Apple("<<apple.getName()<<","<<apple.getColor()<<","<<apple.m_fibre<<")\n";
	return out;
	}

};


class Banana : public Fruit
{
public:

	Banana(std::string name, std::string color)
	      : Fruit(name,color) {}

	friend std::ostream& operator<<(std::ostream &out, const Banana &kela)
	{
		std::cout<<"Banana("<<kela.getName()<<","<<kela.getColor()<<")\n";
	return out;
	}
};


int main()
{
	const Apple a("Red delicious", "red", 4.2);
	std::cout << a;
 
	const Banana b("Cavendish", "yellow");
	std::cout << b;
 
	return 0;
}
