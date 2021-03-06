#include<iostream>
#include<cassert>

class Matrix
{
private:

	int m_row;   //  for rows
	int m_col;   //  for columns

	int **matrix;

public:

	Matrix(int row = 1, int col = 1) : m_row(row) , m_col(col)
	{
		matrix = new int *[m_row];
		
		for(int i = 0; i < m_row; ++i)
		{
			matrix[i] = new int[m_col];
		}
	}
	
	Matrix(const Matrix &a) : m_row(a.m_row) , m_col(a.m_col) , matrix(a.matrix)
	{
		std::cout << "Copy constructor called.\n";
	}

	~Matrix()
	{
		for(int i = 0; i < m_row; ++i)
		{
			delete[] matrix[i];
		}
		
		delete[] matrix;
	}

	
	Matrix transpose()
	{
		Matrix t(m_col , m_row);
	
		for(int i = 0; i < m_row; ++i)
		{
			for(int j = 0; j < m_col; ++j)
			{
				t.matrix[j][i] = matrix[i][j];
			}
		}
	
	return t;
	}
	
	int diagonalAddition()
	{
		int sum = 0;
	
		assert(m_row == m_col);
		
		for(int i = 0; i < m_row; ++i)
		{
			sum += matrix[i][i];
		}
	return sum;	
	}
	
	void isUpperTriangular()
	{
		int counter = 0;
		int check= (m_row * (m_row + 1))/2;
		
		for(int i = 0; i < m_row; ++i)
		{
			for(int j = i; j < m_col; ++j)
			{
				if(matrix[i][j] == 0)
				{
					++counter;
				}
			}
		}
		
		if(check == counter)
		{
			std::cout << "Yes it is a upper triangular matrix.\n";
		}
		
		else
		{
			std::cout << "No it is NOT a upper triangular matrix.\n";
		}
	}


	void saddlePoint()
	{
		Matrix temp(this->transpose());
		
		int j = 0;
		
		for(int i = 0; i < m_row; ++i)
		{
			j = smallest(matrix[i],m_col);
			
			if(matrix[i][j] == greatest(temp.matrix[j],m_row))
			{
				std::cout << matrix[i][j]<< " is the saddle point.\n";
				
			return;
			}
		}
		
		std::cout << "No saddle point.\n";
			
	}

	
	int** getMatrix() { return matrix; }


	static int greatest(int *s,int length);
	
	static int smallest(int *s,int length);

	
	friend std::istream& operator>>(std::istream &in, Matrix &A);
	
	friend std::ostream& operator<<(std::ostream &out, const Matrix &A);
	
	friend Matrix operator*(const Matrix &A, const Matrix &B);
	
	friend Matrix operator+(const Matrix &A, const Matrix &B);
	
	friend Matrix operator-(const Matrix &A, const Matrix &B);

};


int Matrix::greatest(int *s,int length)
{
	int i = 0;

	for(int j = i + 1; j < length ; j++)
	{
		if(s[j] > s[i])
		{
			i = j;
		}
	}

return s[i];	
}


int Matrix::smallest(int *s,int length)
{
	int i = 0;

	for(int j = i + 1; j < length ; j++)
	{
		if(s[j] < s[i])
		{
			i = j;
		}
	}

return i;
}



std::istream& operator>>(std::istream &in, Matrix &A)
{
	for(int i = 0; i < A.m_row; ++i )
	{
		for(int j = 0; j < A.m_col; ++j)
		{
			in >> A.matrix[i][j];
		}
	}
	
return in;	
}
	
std::ostream& operator<<(std::ostream &out, const Matrix &A)
{
	std::cout << '\n';
	
	for(int i = 0; i < A.m_row; ++i )
	{
		for(int j = 0; j < A.m_col; ++j)
		{
			out << A.matrix[i][j] << " ";
		}
	
			std::cout << '\n';	
	}
		
	std::cout << '\n';
	
return out;	
}


Matrix operator*(const Matrix &A, const Matrix &B)
{
	assert(A.m_col == B.m_row);

	Matrix mul(A.m_row , B.m_col);

	for(int i = 0; i < A.m_row; ++i)
	{
		for(int j = 0; j < B.m_col; ++j)
		{
			for(int k = 0; k < A.m_col; ++k)
			{
				mul.matrix[i][j] += A.matrix[i][k] * B.matrix[k][j];
			}
		}
	}
	
return mul;
}


Matrix operator+(const Matrix &A, const Matrix &B)
{
	assert((A.m_row == B.m_row) && (A.m_col == B.m_col));

	Matrix add(A.m_row , A.m_col);

	for(int i = 0; i < A.m_row; ++i)
	{
		for(int j = 0; j < A.m_col; ++j)
		{
			add.matrix[i][j] = A.matrix[i][j] + B.matrix[i][j];
		}
	}

return add;
}


Matrix operator-(const Matrix &A, const Matrix &B)
{
	assert((A.m_row == B.m_row) && (A.m_col == B.m_col));

	Matrix sub(A.m_row , A.m_col);

	for(int i = 0; i < A.m_row; ++i)
	{
		for(int j = 0; j < A.m_col; ++j)
		{
			sub.matrix[i][j] = A.matrix[i][j] - B.matrix[i][j];
		}
	}

return sub;
}


int main()
{
	int row1,col1,row2,col2;
	
	std::cout << "Enter rows and columns of A.\n";
	
	std::cin >> row1 >> col1;

	Matrix A(row1,col1);

	std::cout << "Enter elements of A :-\n";
	
	std::cin >> A;
	
	std::cout << A;

	{
		Matrix B = A;
	
	}

	//std::cout << A.transpose();
	
	A.getMatrix();
	
	//A.saddlePoint();
	
	
return 0;	
	
}
