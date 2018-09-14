#include<iostream>


class Student
{
public:

	enum Game
	{
		Badminton,
		Cricket,
		Both,
		Other,
		None
	};
	
private:

	int m_roll_no;
	Game m_game;

public:

	Student(int roll_no = 0, Game game = None) : m_roll_no(roll_no) , m_game(game) 
	{
	}
};

int main()
{
	Student s[5];
	
}


