// SE-3 F-3
// Roll no 21335

#include<iostream>
#include<cassert>
#include<cmath>

class Polynomial
{

private :
	
	int m_terms;
	int *m_index;
	int *m_coeff;

public :
	
	Polynomial(int terms = 0) : m_terms(terms)
	{
		assert(m_terms > 0);
	
		m_index = new int[m_terms];
		m_coeff = new int[m_terms];
	}


	Polynomial(const Polynomial &f) // Copy Constructor does deep copying.
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
			m_index = NULL;
			m_coeff = NULL;
		}
	}


	Polynomial& operator=(const Polynomial &f) // Assignment operator does deep copying.
	{
		if(this == &f)
		{
			return *this; // if same poly return *this something like f1 = f1.
		}
		
		this->erase(); // if already present poly them erase it.

		m_terms = f.m_terms;

		m_index = new int[m_terms];
		m_coeff = new int[m_terms];
	
		for(int i = 0; i < m_terms; ++i)
		{
			m_index[i] = f.m_index[i];
			m_coeff[i] = f.m_coeff[i];
		}
	}

	~Polynomial()
	{
		delete[] m_index;
		delete[] m_coeff;
	}

	friend std::istream& operator>>(std::istream &in, Polynomial &f);
	
	friend std::ostream& operator<<(std::ostream &out, const Polynomial &f);

	friend Polynomial operator+(const Polynomial &f1, const Polynomial &f2);

	friend Polynomial operator-(const Polynomial &f1, Polynomial &f2);

	friend Polynomial operator*(const Polynomial &f1,const Polynomial &f2);


	Polynomial& operator-() // To negate poly.
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
		m_index = NULL;
		m_coeff = NULL;
	}


	void renew() // To renew matrix if any same index term or 0 coefficient terms exsist.
	{
		int count = 0, x1 = 0, x2 = 0;
		
		for(int i = 0; i < m_terms; ++i)
		{
			for(int j = i + 1; j < m_terms ; ++j)
			{
				if(m_index[i] == m_index[j])  // if same degree present
				{
					m_coeff[i] += m_coeff[j]; // add coefficient
					m_coeff[j] = 0;		  // make the other coeff 0.
					++count;		  // count how many repeated index terms.
				}
			}
		}

		Polynomial renewed(m_terms - count); // make a renewed temp Poly for copying into current poly to modify it.
		
		for(int i = 0; i < m_terms; ++i)
		{
			if(m_coeff[i] == 0)
			{
				continue;
			}

			else
			{
				renewed.m_index[x1++] = m_index[i]; // if coeff not 0 add the previous modified terms to new poly.
				renewed.m_coeff[x2++] = m_coeff[i]; // if coeff not 0 add the previous modified terms to new poly.			
			}
		}

		this->erase(); // clear the current poly
		
		m_terms = renewed.m_terms; // and copy our renewed poly into current poly.
		m_index = new int[m_terms];
		m_coeff = new int[m_terms];

		for(int i = 0; i < m_terms; ++i)
		{
			m_index[i] = renewed.m_index[i];
			m_coeff[i] = renewed.m_coeff[i];
		}
	}
	
	int evaluate(int x) // to evalute value of poly for particular x.
	{
		int y = 0;
		
		for(int i = 0; i < m_terms; ++i)
		{
			y += m_coeff[i] * pow(x,m_index[i]) ;
		}
		
	return y;	
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
		if(f.m_coeff[i] == 1 && f.m_index[i] == 1) // if index 1 and coeff 1 print only x.
		{
			std::cout << "x" << " + ";
		}
		
		else if(f.m_coeff[i] == 1) // if coeff 1
		{
			if(f.m_index[i] == 0) // and index zero print only 1.
			{
				std::cout << f.m_coeff[i] << " + ";
			}

			else // if index not zero then ignore coeff.
			{
				std::cout << "x^" << f.m_index[i] << " + ";
			}
		}
		
		else if(f.m_index[i] == 0) // if index zero print only 
		{
			std::cout << f.m_coeff[i] << " + ";
		}

		else if(f.m_index[i] == 1) // if only index 1 ignore the ^ sign.
		{
			std::cout << f.m_coeff[i] << "x" << " + "; 
		}	

		else	// else print normally.
		{
			std::cout << f.m_coeff[i] << "x^" << f.m_index[i] << " + ";
		}	
	}
	
	// same logic as above but differrent for the last term since we have to ignore the + sign.
	
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
	
	else if(f.m_index[f.m_terms - 1] == 0)
	{
		std::cout << f.m_coeff[f.m_terms - 1];
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
	Polynomial add(f1.m_terms + f2.m_terms); // temp Poly with terms as max terms later we will renew the poly by calling renew fuction.
	int x1(0) , x2(0);

	for(int i = 0; i < f1.m_terms; ++i) // add all terms in poly f1
	{
		add.m_index[x1++] = f1.m_index[i];
		add.m_coeff[x2++] = f1.m_coeff[i];
	}

	for(int i = 0; i < f2.m_terms; ++i) // add all terms in poly f2
	{
		add.m_index[x1++] = f2.m_index[i];
		add.m_coeff[x2++] = f2.m_coeff[i];
	}

	add.renew(); // call the renew fuction to check if extra terms are present.

return add;
}


Polynomial operator-(const Polynomial &f1, Polynomial &f2)
{
	f2 = -f2; // calls negation op
	 
	return f1 + f2; // does f1 + -f2 same as f1 - f2.
}


Polynomial operator*(const Polynomial &f1,const Polynomial &f2)
{
	Polynomial mul(f1.m_terms * f2.m_terms); // temp poly with max terms.
	int x1(0), x2(0);


	for(int i = 0; i < f1.m_terms; ++i) // fix one term and multiply to all terms of anoter poly.
	{
		for(int j = 0; j < f2.m_terms; ++j)
		{
			mul.m_index[x1++] = f1.m_index[i] + f2.m_index[j]; 
			mul.m_coeff[x2++] = f1.m_coeff[i] * f2.m_coeff[j];
		}
	}

	mul.renew(); // call the renew fuction to check if extra terms are present.

return mul;
}


int main()
{
	int terms1,terms2;

	std::cout << "Enter number of terms of polynomial 1 :- ";
	std::cin >> terms1;
	
	std::cout << "Enter number of terms of polynomial 2 :- ";
	std::cin >> terms2;
	
	Polynomial f1(terms1);
	Polynomial f2(terms2);
	
	int num;
	char ip;
	
	std::cout << "\nEnter 1 to input Polynomial 1\n";
	std::cout << "Enter 2 to input Polynomial 2\n";
	std::cout << "Enter 3 to add Polynomial 1 and 2\n";
	std::cout << "Enter 4 to multiply Polynomial 1 and 2\n";
	std::cout << "Enter 5 to evaluate for particular x value\n"; 
	
	while(true)
	{
		bool flag(false);
	
		std::cout << "Enter the number :- ";
		std::cin >> num;
	
		switch(num)
		{
			case 1 :
			{
				std::cout << "\nEnter the corresponding degrees and coefficients of Polynomial 1\n";
				std::cin >> f1;
				std::cout << "\n" << f1 << "\n";
			
			break;	
			}
			
			case 2 :
			{
				std::cout << "\nEnter the corresponding degrees and coefficients of Polynomial 2\n";
				std::cin >> f2;
				std::cout << "\n" <<  f2 << '\n';
			
			break;	
			}
			
			case 3 :
			{
				std::cout << "\nThe addition is :- \n";
				std::cout << f1 + f2 << "\n";
			
			break;	
			}
			
			case 4 :
			{
				std::cout << "\nThe multiplication is :- \n";
				std::cout << f1 * f2 << "\n";
			
			break;	
			} 
			
			case 5 :
			{
				int x;
				int num;
			
				std::cout << "Enter number to evaluate Polynomial :- ";
				std::cin >> x;
				
				std::cout << "Which polynomial to evaluate :- ";
				std::cin >> num;
				
				if(num == 1)
				{
					std::cout << "\nThe evaluation is " << f1.evaluate(x) << "\n";
				}
				
				else if(num == 2)
				{
					std::cout << "\nThe evaluation is " << f2.evaluate(x) << "\n";
				}
				
				else
				{
					std::cout << "Invalid Input\n";
				}
			break;	
			}
			
			default :
			{
				std::cout << "Invalid entry. Enter again :- ";
				continue;
			}
		}
		
		std::cout << "\nDo you want to continue :- ";
		
		while(true)
		{
			std::cin >> ip;
		
			if(ip == 'N' || ip == 'n')
			{
				flag = true;
				break;
			}
		
			else if(ip != 'N' && ip != 'n' && ip != 'y' && ip != 'Y')
			{
				break;
			}
			
			else
			{
				break;
			}
		}
		
		if(flag)
		{
			break;
		}	
	}	

return 0;
}
