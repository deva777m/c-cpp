#include<iostream>

enum Game
{
	badminton, // 0
	cricket,   // 1
	both,      // 2 
	other,	   // 3
	none           // 4
};

struct Student
{
	int roll_no;
	Game game;
};

std::istream& operator>>(std::istream &in, Game &game)
{
	int x;	

	in >> x;

	game = static_cast<Game>(x);

return in;
}


std::string Print(int game)
{
	switch(game)
	{
		case 0:
		{
			return "only badminton";
		}

		case 1:
		{
			return "only cricket";
		}

		case 2:
		{
			return "both";
		}

		case 3:
		{	
			return "other";
		}
		
		case 4: 
		{
			return "none";
		}
	}
}

void whichCase(int case1,Student *s , int length)
{
		if(case1 == 5)
		{
			"Number of student playing either cricket badminton or both are.\n";			

			for(int i = 0; i < length; ++i)
			{
				if((s[i].game != static_cast<Game>(5)) && (s[i].game != static_cast<Game>(4)))
					{
						std::cout << s[i].roll_no << " ";
					}
			}
		return;	
		}

		std::cout << "Number of student playing " << Print(case1) << " are.\n";
	
		for(int i = 0; i < length; ++i)
		{
			if(s[i].game == static_cast<Game>(case1))
			{
				std::cout << s[i].roll_no << " ";
			}
		}

		std::cout << '\n';
	
}

int main()
{
	int length,input;

	std::cout << "Enter number of students.\n";

	std::cin >> length;

	Student s[length];

	std::cout << "\nEnter roll number and corresponding game\n";

	std::cout << "\nEnter 0 for only badminton.\nEnter 1 for only cricket.\nEnter 2 for both.\nEnter 3 for other.\n";
	std::cout << "Enter 4 for none.\n\n";

	for(int i = 0; i < length; ++i)
	{
		std::cout << "Roll no : ";
		std::cin >> s[i].roll_no;
	
		std::cout << "Game : ";
		std::cin >> s[i].game;
	}
	
	while(true)
	{
		int ip;
		char ans;

		std::cout << "\nEnter Y to continue or N to exit : ";

		std::cin >> ans;

		if(ans == 'N')
		{
			return 0;
		}

		std::cout << "\nEnter 0 for only badminton.\nEnter 1 for only cricket.\nEnter 2 for both.\nEnter 3 for other.\n";
		std::cout << "Enter 4 for none.\nEnter 5 for union of cricket and badminton.\n\n";
	
		std::cout << "Enter input : ";

		std::cin >> ip;

		std::cout << '\n';

		whichCase(ip,s,length);
	}

}
