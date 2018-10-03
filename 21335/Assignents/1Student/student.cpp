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

return s[i].marks;
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

return s[i].marks;
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

	
	int count = 0;		

	for(int i = 0; i < length; i++)
	{
		if(counter[0] == counter[i])
		{
			++count;
		}
		
		if(count == length)
		{
			return 404;
		}
	}

	return greatest(counter, length);
}

int main()
{
	int n,c;  // n is number of students   // x is switch case number

	std::cout << "Enter number of students\n";

	std::cin >> n;

	Student s[n];

	std::cout << "Enter roll number and marks sequentially\n";

	for(int i = 0; i < n; i++)
	{
		std::cout << "Enter roll of student " << i + 1 <<" : ";
		std::cin >> s[i].roll_no;

		std::cout << "Enter prencense of student " << i + 1 <<" : ";
		std::cin >> s[i].x;
		
		if(s[i].x == 'A')
		{
			s[i].marks = 0;
		}

		else
		{
			std::cout << "Enter marks of student " << i + 1<<" : ";
			std::cin >> s[i].marks;
		}
	}

	std::cout << "\nEnter 1 for highest marks scored.\n";
	std::cout << "Enter 2 for lowest marks scored.\n";
	std::cout << "Enter 3 for average marks scored.\n";
	std::cout << "Enter 4 for mode Marks.\n";
	std::cout << "Enter 5 for number of absent students\n";
	
	while(true)
	{
		char input;
		
		std::cout << "Enter the number : ";
	
		std::cin >> c;
	
		switch(c)
		{
			case 1:
			{
				int max = greatest(s,n);
	
				for(int i = 0; i < n; i++)
				{
					if(s[i].marks == max)
					{
						std::cout << s[i].roll_no << " ";
					}
				}
	
				std::cout << "\nAbove roll nos scored highest marks : " << max << "\n";

			break;
			}

			case 2:
			{
				int min = smallest(s,n);
	
				for(int i = 0; i < n; i++)
				{
					if(s[i].marks == min)
					{
						std::cout << s[i].roll_no << " ";
					}
				}

				std::cout << "\nAbove roll nos scored lowest marks : " << min << "\n";

			break;
			}

			case 3:
			{
				std::cout << "The average marks scored is : " << average(s,n) << "\n";

			break;
			}

			case 4:
			{
				int temp = maxMarks(s,n);
			
				int mode = s[temp].marks;
				
				if(temp == 404)
				{
					std::cout << "The mode marks is null\n"; 				
				}

				else
				{
					for(int i = 0; i < n; i++)
					{
						if(s[i].marks == mode)
						{
							std::cout << s[i].roll_no << " ";
						}
					}

					std::cout << "\nThe mode marks is : " << mode << "\n";
				}
			break;
			}

			case 5:
			{
				std::cout << "\n Total absen students are : " << absent(s,n) << '\n';
	
			break;
			}
	
			default :
			{
				std::cout << "Invalid case";
	
			break;
			}
		}
		
		std::cout << "Do you want to continue enter 'Y' or 'N' : ";
		
		std::cin >> input;
		
		if((input == 'N') || (input == 'n'))
		{
			break;
		}
		
		else if((input == 'Y') || (input == 'y'))
		{
			continue;
		}
		
		else
		{
			std::cout << "Invalid input.\n";
		}
		
	
		
	}	

return 0;
}

