#include <iostream>
 
template <class T, class S>
class Pair
{
private:
	T m_x;
	S m_y;
 
public:
	Pair(const T& x, const S& y)
		: m_x(x), m_y(y)
	{
	}
 
	T& first() { return m_x; }
	const T& first() const { return m_x; }
	S& second() { return m_y; }
	const S& second() const { return m_y; }
};

template <class T>
 
class StringValuePair: public Pair<std::string, T>
{
public:
	StringValuePair(std::string s, const T &x ) : Pair<std::string, T> (s , x) 
	{
	}
};

int main()
{
	StringValuePair<int> svp("Hello", 5);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
 
	return 0;
}
