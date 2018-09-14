#include<iostream>
#include<cassert>

class Matrix
{
private:

	const int m_row;
	const int m_col;
	
	int **matrix;
	
public:
	
	Matrix(const int row = 1, const int col = 1) : m_row(row), m_col(col)
	{
		matrix = new int *[m_row];       // return a address which will  point to array of pointers
					         // will contain null pointers by default	
		for(int i = 0; i < m_row; i++)
		{
			matrix[i] = new int[m_col];   // assign those pointers 
		}
	}


	~Matrix()
	{
		for(int i = 0; i < m_row; i++)
		{
			delete[] matrix[i];
		}

		delete[] matrix;
	}


	bool upperTriagMatrix()
	{
		int counter = 0;
		
		if(m_row != m_col)
		{
			std::cout << "Not a square matrix\n";
			
			return false;
		}

	
		for(int i = 0; i < m_row; i++)
		{
			for(int j = i; j < m_col; j++)
			{		
				if(matrix[i][j] == 0)
				{
					++counter;
				}
			}
		}
	
		if(counter == m_row * (m_row + 1)/2)
		{
			return true;
		}
		
		else
		{
			return false;	
		}
	}


	friend std::ostream& operator<<(std::ostream &out, const Matrix &a);

	friend std::istream& operator>>(std::istream &in, Matrix &a);

	friend Matrix operator*(const Matrix &a, const Matrix &b);

};


std::ostream& operator<<(std::ostream &out, const Matrix &a)
{

	std::cout << '\n';
	
	for(int i = 0; i < a.m_row; i++)
	{
		for(int j = 0; j < a.m_col; j++)
		{		
			out << a.matrix[i][j] << " ";
		}
			
		std::cout << '\n';			
	}

	std::cout << '\n';

return out;
}

std::istream& operator>>(std::istream &in, Matrix &a)
{
	for(int i = 0; i < a.m_row; i++)
	{
		for(int j = 0; j < a.m_col; j++)
		{
			in >> a.matrix[i][j]; 
		}	
	}

return in;
}


Matrix operator*(const Matrix &a, const Matrix &b)
{
	assert(a.m_col == b.m_row);

	Matrix mul(a.m_row , b.m_col);
	
	for(int i = 0; i < a.m_row; i++)
	{
		for(int j = 0; j < b.m_col; j++)
		{
			for(int k = 0; k < a.m_col; k++)
			{
				mul.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j];
			}
		}
	}

	return mul;
}

int main()
{
	
	Matrix A(2,3);

	Matrix B(3,2);

	std::cin >> A;

	std::cout << A;

	std::cin >> B;

	std::cout << B;

	std::cout << A * B ;	

return 0;
}
