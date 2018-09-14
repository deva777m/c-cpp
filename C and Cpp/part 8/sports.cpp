#include<iostream>

int main()
{
	int length1,length2;

	std::cin >> length1 >> length2;

	std::string *badminton = new std::string[length1];

	std::string *cricket = new std::string[length2];

	for(int i = 0; i < length1 ; ++i)
	{
		std::cin >> badminton[i];
	}

	for(int i = 0; i < length2 ; ++i)
	{
		std::cin >> cricket[i];
	}

	for(int i = 0; i < length1; ++i)
	{
		std::cout << badminton[i] << " ";
	}

	for(int i = 0; i < length2 ; ++i)
	{
		
	}

	


}
