#include<iostream>

class Polynomial
{

private :
	
	int m_terms;
	int *m_index;
	int *m_coeff;

public :
	
	Polynomial(int terms = 0) : m_terms(terms)
	{
		m_index = new int[m_terms];
		m_coeff = new int[m_terms];
	}


	Polynomial(const Polynomial &f)
	{
		if(f.m_index && f.m_coeff)
		{
			m_terms = f.m_terms;

			m_index = new int[m_terms];
			m_coeff = new int[m_terms];
	
			for(int i = 0; i < m_terms; ++i)
			{
				m_index[i] = f.m_index[i];
				m_coeff[i] = f.m_coeff[i];
			}
		}
	
		else
		{
			m_index = nullptr;
			m_coeff = nullptr;
		}
	}


	Polynomial& operator=(const Polynomial &f)
	{
		if(this == &f)
		{
			return *this;
		}
		
		this->erase();

		m_terms = f.m_terms;

		m_index = new int[m_terms];
		m_coeff = new int[m_terms];
	
		for(int i = 0; i < m_terms; ++i)
		{
			m_index[i] = f.m_index[i];
			m_coeff[i] = f.m_coeff[i];
		}
	}

	friend std::istream& operator>>(std::istream &in, Polynomial &f);
	
	friend std::ostream& operator<<(std::ostream &out, const Polynomial &f);

	friend Polynomial operator+(const Polynomial &f1, const Polynomial &f2);

	friend Polynomial operator-(const Polynomial &f1, const Polynomial &f2);

	friend Polynomial operator*(const Polynomial &f1,const Polynomial &f2);


	Polynomial& operator-()
	{
		for(int i = 0; i < m_terms; ++i)
		{
			m_coeff[i] = -m_coeff[i];
		}
	
	return *this;
	}

	void erase()
	{
		m_terms = 0;	
		m_index = nullptr;
		m_coeff = nullptr;
	}


	void renew()
	{
		int count = 0, x1 = 0, x2 = 0;
		
		for(int i = 0; i < m_terms; ++i)
		{
			for(int j = i + 1; j < m_terms ; ++j)
			{
				if(m_index[i] == m_index[j])
				{
					m_coeff[i] += m_coeff[j];
					m_coeff[j] = 0;
					++count;
				}
			}
		}

		Polynomial renewed(m_terms - count);
		
		for(int i = 0; i < m_terms; ++i)
		{
			if(m_coeff[i] == 0)
			{
				continue;
			}

			else
			{
				renewed.m_index[x1++] = m_index[i];
				renewed.m_coeff[x2++] = m_coeff[i];			
			}
		}

		this->erase();
		
		m_terms = renewed.m_terms;
		m_index = new int[m_terms];
		m_coeff = new int[m_terms];

		for(int i = 0; i < m_terms; ++i)
		{
			m_index[i] = renewed.m_index[i];
			m_coeff[i] = renewed.m_coeff[i];
		}
	}
};


std::istream& operator>>(std::istream &in, Polynomial &f)
{
	for(int i = 0; i < f.m_terms; ++i)
	{
		std::cout << "Enter Degree :- ";
		std::cin >> f.m_index[i];
		
		std::cout << "Enter Coefficient :- ";
		std::cin >> f.m_coeff[i];
	}

	f.renew();

return in;
}


std::ostream& operator<<(std::ostream &out, const Polynomial &f)
{
	for(int i = 0; i < f.m_terms - 1; ++i)
	{
		if(f.m_coeff[i] == 1 && f.m_index[i] == 1)
		{
			std::cout << "x" << " + ";
		}
		
		else if(f.m_coeff[i] == 1)
		{
			if(f.m_index[i] == 0)
			{
				std::cout << f.m_coeff[i] << " + ";
			}

			else
			{
				std::cout << "x^" << f.m_index[i] << " + ";
			}
		}

		else if(f.m_index[i] == 1)
		{
			std::cout << f.m_coeff[i] << "x" << " + "; 
		}	

		else
		{
			std::cout << f.m_coeff[i] << "x^" << f.m_index[i] << " + ";
		}	
	}
	
	if(f.m_coeff[f.m_terms - 1] == 1 && f.m_index[f.m_terms - 1] == 1)
	{
		std::cout << "x";
	}

	else if(f.m_coeff[f.m_terms - 1] == 1)
	{
		if(f.m_index[f.m_terms - 1] == 0)
		{
			std::cout << f.m_coeff[f.m_terms - 1];
		}
		
		else
		{
			std::cout << "x^" << f.m_index[f.m_terms - 1];
		}	
	}

	else if(f.m_index[f.m_terms - 1] == 1)
	{
		std::cout << f.m_coeff[f.m_terms - 1] << "x"; 
	}

	else
	{
		std::cout << f.m_coeff[f.m_terms - 1] << "x^" << f.m_index[f.m_terms - 1];
	}

return out;
}


Polynomial operator+(const Polynomial &f1, const Polynomial &f2)
{
	Polynomial add(f1.m_terms + f2.m_terms);
	int x1(0) , x2(0);

	for(int i = 0; i < f1.m_terms; ++i)
	{
		add.m_index[x1++] = f1.m_index[i];
		add.m_coeff[x2++] = f1.m_coeff[i];
	}

	for(int i = 0; i < f2.m_terms; ++i)
	{
		add.m_index[x1++] = f2.m_index[i];
		add.m_coeff[x2++] = f2.m_coeff[i];
	}

	add.renew();

return add;
}


Polynomial operator-(const Polynomial &f1, Polynomial &f2)
{
	f2 = -f2;
	
	return f1 + f2; 
}


Polynomial operator*(const Polynomial &f1,const Polynomial &f2)
{
	Polynomial mul(f1.m_terms * f2.m_terms);
	int x1(0), x2(0);


	for(int i = 0; i < f1.m_terms; ++i)
	{
		for(int j = 0; j < f2.m_terms; ++j)
		{
			mul.m_index[x1++] = f1.m_index[i] + f2.m_index[j];
			mul.m_coeff[x2++] = f1.m_coeff[i] * f2.m_coeff[j];
		}
	}

	mul.renew();

return mul;
}


int main()
{
	Polynomial f1(3);
	Polynomial f2(2);
	Polynomial f3;
	
	std::cin >> f1;
	std::cout << f1 << "\n\n";

	std::cin >> f2;
	std::cout << f2 << "\n\n";

	std::cout << f1 * f2 << '\n';

return 0;
}
