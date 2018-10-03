#include<iostream>

void swap(int &x, int &y)		// Swaps any two numbers.
{
	int temp = x;
	x = y;
	y = temp;
}

void ascend(int **matrix,int length)	// makes any row in the matrix in ascnding order and also aligns the respetive column value.
{
	for(int i = 0; i < length; ++i)
	{
		int k = i;
		
		for(int j = k + 1; j < length ; j++)
		{
			if(matrix[0][j] < matrix[0][k])
			{
				k = j;
			}
		}
		
		swap(matrix[0][i],matrix[0][k]);	// swaps row value
		swap(matrix[1][i],matrix[1][k]);	// swaps col value
		swap(matrix[2][i],matrix[2][k]);	// swaps value(the num value) value
	}

}

void swapArray(int **ptr1, int **ptr2)	// Swaps any two rows in 2d matrix so helpful in transpse
{
	int *temp = NULL;
	
	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
	
}

class Sparse
{

private :
	
	int m_terms;		// number of non zero terms.
	int **matrix;		// 2d matrix.
	int m_r;		// rows of actual matrix.
	int m_c;		// columns of actual matrix.
	
public : 

	Sparse(int terms = 0, int r = 0, int c = 0) :	m_terms(terms) , m_r(r) , m_c(c)
	{
		matrix = new int *[3];		// return an array of pointers which has 3 rows
	
		for(int i = 0; i < 3; ++i)
		{
			matrix[i] = new int[m_terms];	// allocate memorys for the row arrays
		}
	}
	
	Sparse transpose()
	{
		Sparse temp = *this;	// assign temp to current object
		
		temp.m_r = this->m_c;	// since this is transpose.
		temp.m_c = this->m_r; 
	
		swapArray(&(temp.matrix[0]), &(temp.matrix[1]));	// swap the row and col.
		ascend(temp.matrix, temp.m_terms);			// align row in ascending order.
		
	return temp;
	}
	
	friend std::istream& operator>>(std::istream &in, Sparse &m);
	
	friend std::ostream& operator<<(std::ostream &out, const Sparse &m);
	
	friend Sparse operator+(const Sparse &m1, const Sparse &m2);
	
};


std::istream& operator>>(std::istream &in, Sparse &m)
{
	for(int j = 0; j < m.m_terms; ++j)
	{
		for(int i = 0; i < 3; ++i)
		{
			if(i == 0)
			{
				std::cout << "Enter Row number :- ";
			}
			
			else if(i == 1)
			{
				std::cout << "Enter Column number :- ";
			}
			
			else 
			{
				std::cout << "Enter corresponding value :- ";			
			}
			
			in >> m.matrix[i][j];
		}
	}

return in;
}


std::ostream& operator<<(std::ostream &out, const Sparse &m)
{
	std::cout << "\nR C V\n";
	std::cout << m.m_r << " " << m.m_c << " " << m.m_terms << "\n\n";

	for(int i = 0; i < m.m_terms; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			out << m.matrix[j][i] << " ";
		}
		
		std::cout << '\n';
	}
	
return out;	
}


Sparse operator+(const Sparse &m1, const Sparse &m2)
{
	int count = 0;
	int k1(0), k2(0);
	
	for(int j = 0; j < m1.m_terms; ++j)		// count the number of row and col values which are same.
	{
		for(int k = 0; k < m2.m_terms; ++k)
		{	
			if((m1.matrix[0][j] == m2.matrix[0][k]) && (m1.matrix[1][j] == m2.matrix[1][k]))
			{
				++count;
			}
		}	
	}
	
	Sparse temp(m1.m_terms + m2.m_terms - count, m1.m_r , m1.m_c);	// make a temp matrix with this terms.
	
	for(int i = 0; i < temp.m_terms; ++i)		// Logic of merge sort.
	{
		if(k1 == m1.m_terms)		
		{
			if(k2 == m2.m_terms)
			{
				break;
			}
		
			for(int j = 0; j < 3; ++j)
			{
				temp.matrix[j][i] = m2.matrix[j][k2];
			}
			
			k2++;
			
			continue;
		}
	
		if(k2 == m2.m_terms)
		{
			if(k1 == m1.m_terms)
			{
				break;
			}
		
			for(int j = 0; j < 3; ++j)
			{
				temp.matrix[j][i] = m1.matrix[j][k1];
			}
			
			k1++;
			
			continue;
		}

		if(m1.matrix[0][k1] == m2.matrix[0][k2] && m1.matrix[1][k1] == m2.matrix[1][k2])
		{
			for(int j = 0; j < 2; ++j)
			{
				temp.matrix[j][i]= m1.matrix[j][k1];
			}
			
			temp.matrix[2][i] = m1.matrix[2][k1] + m2.matrix[2][k2];
			
			++k1; ++k2;
		}
	
		else if(m1.matrix[0][k1] == m2.matrix[0][k2])
		{
			if(m1.matrix[1][k1] < m2.matrix[1][k1])
			{
				for(int j = 0; j < 3; ++j)
				{
					temp.matrix[j][i]= m1.matrix[j][k1];
				}
				
				++k1;
			}
			
			else
			{
				for(int j = 0; j < 3; ++j)
				{
					temp.matrix[j][i]= m2.matrix[j][k2];
				}
				
				++k2;
			}
		}
	
		else if(m1.matrix[0][k1] != m2.matrix[0][k2])
		{
			if(m1.matrix[0][k1] < m2.matrix[0][k2])
			{
				for(int j = 0; j < 3; ++j)
				{
					temp.matrix[j][i]= m1.matrix[j][k1];
				}
				
				++k1; 
			}
		
			else
			{
				for(int j = 0; j < 3; ++j)
				{
					temp.matrix[j][i]= m2.matrix[j][k2];
				}
				
				++k2;
			}
		}
	}
		
return temp;
}

int main()
{
	
	int num,t1,t2,r1,r2,c1,c2;	// num = switch choice, t = non zero terms, r = rows, c = columns
	char ip;			// ip for chechking input.
	bool flag(false);		// For input validation.

	std::cout << "Enter number of rows of matrix 1 :- ";
	std::cin >> r1;	

	std::cout << "Enter number of columns of matrix 1 :- ";
	std::cin >> c1;	

	std::cout << "Enter number of non zero terms in matrix 1 :- ";
	std::cin >> t1;
	
	std::cout << "\nEnter number of rows of matrix 2 :- ";
	std::cin >> r2;	

	std::cout << "Enter number of columns of matrix 2 :- ";
	std::cin >> c2;	
	
	std::cout << "Enter number of non zero terms in matrix 2 :- ";
	std::cin >> t2;
	

	Sparse m1(t1,r1,c1);
	Sparse m2(t2,r2,c2);
	
	while(true)
	{
	
		std::cout << "\nEnter 1 to input matrix 1.\n";
		std::cout << "Enter 2 to input matrix 2.\n";
		std::cout << "Enter 3 to transpose matrix 1.\n";
		std::cout << "Enter 4 to add to matries.\n";
	
		std::cout << ":- ";
		std::cin >> num;
	
		switch(num)
		{
			case 1 :
			{
				std::cin >> m1;
				std::cout << m1 << '\n';
				
			break;	
			}
			
			case 2 :
			{
				std::cin >> m2;
				std::cout << m2 << '\n';
			
			break;	
			}
			
			case 3 :
			{
				std::cout << m1.transpose() << '\n';
				
			break;	 
			}
			
			case 4 :
			{
				std::cout << m1 + m2 << '\n';
			
			break;	
			}
			
			default :
			{
				std::cout << "\nInvalid input enter again\n";
				continue;
			}
		}
		
		std::cout << "Want to continue :- ";
		
		while(true)
		{
			std::cin >> ip;
			
			if(ip == 'N' || ip == 'n')
			{
				flag = true;
				break;
			}
			
			else if(ip != 'n' && ip != 'N' && ip != 'y' && ip != 'Y')
			{
				std::cout << "\nInvalid input enter again\n";
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
