#include<iostream>

struct Student
{
	int roll_no;
	int marks;
	char x;  // x denotes present or absent

};

double average(Student *s, int length)
{
	double sum = 0.0;
	double average = 0.0;

	for(int i = 0; i < length; i++)
	{
		sum = sum + s[i].marks;
	}

	average = sum/length;

return average;
}


int greatest(int *s,int length)
{
	int i = 0;

	for(int j = i + 1; j < length ; j++)
	{
		if(s[j] > s[i])
		{
			i = j;
		}
	}

return i;
}


int greatest(Student *s,int length)
{
	int i = 0;

	for(int j = i + 1; j < length ;j++)
	{
		if(s[j].marks > s[i].marks)
		{
			i = j;
		}
	}

return i;
}


int smallest(Student *s,int length)
{
	int i = 0;

	for(int j = i + 1; j < length ;  j++)
	{
		if(s[j].marks < s[i].marks)
		{
			i = j;
		}
	}

return i;
}


int absent(Student *s, int length)
{
	int counter = 0;

	for(int i = 0; i < length; i++)
	{
		if(s[i].x == 'A')
		{
			++counter;
		}	
	}

return counter;
}

int maxMarks(Student *s, int length)
{
	int counter[length];

	for(int i = 0; i < length ; i++)
	{
		counter[i] = 0;
	}

	for(int j = 0; j < length; j++)
	{	 
		for(int i = 0; i < length; i++)
		{
			if(s[j].marks == s[i].marks)
			{
				++counter[j];
			}
		}
	}

	for(int i = 0; i < length; i++)
	{
		if(counter[0] == counter[i])
		{
			return 0;
		}
	}
	
	return greatest(counter, length);
}

int main()
{
	int n;  // n is number of students

	std::cout << "Enter number of students\n";
 
	std::cin >> n;

	Student s[n]; 
	
	std::cout << "Enter roll number and marks sequentially\n";

	for(int i = 0; i < n; i++)
	{
		std::cout << "Enter roll of student " << i + 1 <<" : "; 
		std::cin >> s[i].roll_no;
	
		std::cout << "Enter marks of student " << i + 1 <<" : "; 
		std::cin >> s[i].marks;

		std::cout << "Enter prencense of student " << i + 1 <<" : "; 	
		std::cin >> s[i].x;
	}

	std::cout << "The average is " << average(s,n);

	std::cout << "\nThe highest marks are " << s[greatest(s,n)].marks << " scored by roll no. " << s[greatest(s,n)].roll_no << '\n';

	std::cout << "The lowest marks are " << s[smallest(s,n)].marks << " scored by roll no. " << s[smallest(s,n)].roll_no << '\n';

	std::cout << "The Marks mode is " << s[maxMarks(s,n)].marks << '\n';

	std::cout << "The number of absent students are " << absent(s,n) << '\n';

return 0;
}
