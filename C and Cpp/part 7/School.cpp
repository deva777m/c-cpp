#include<iostream>
#include<vector>
#include<cassert>

// class Person will have name as a member.

class Person
{
protected: // we make our access specifier protected and not priavte since we want it to be accessable to other inhereted classes.

	std::string m_name;

public:

	Person(std::string name = "") : m_name(name)  // initialise name using constructors.
	{
	}

	inline std::string getName() { return m_name; }
};


// Class student will have roll number and name as properties 
// so it will inhert from Person class

class Student : public Person
{
protected:

	int m_roll_no;
	
public:
	
	Student(int roll_no = 0 , std::string name = "") : m_roll_no(roll_no) , Person(name)  // will call the Person Constrcutor 
											      // to initialize name.
	{
	}


	void setData()
	{	
		std::cout << "Enter Name :- ";
		std::cin >> m_name;

		std::cout << "Enter Roll no. :- ";
		std::cin >> m_roll_no;
	}	


	inline int getRollNo() { return m_roll_no; } 

	friend std::istream& operator>>(std::istream &in, Student &s);
	
	friend std::ostream& operator<<(std::ostream &out, const Student &s);

};


std::istream& operator>>(std::istream &in, Student &s)
{
	s.setData();
	
return in;
}

std::ostream& operator<<(std::ostream &out, const Student &s)
{
	out << s.m_roll_no << " : " << s.m_name << '\n';

return out;
}


void swap(Student &s1, Student &s2)
{
	Student temp;
		
	temp = s1;	
	s1 = s2;
	s2 = temp;
}


class Game
{
protected:

	std::vector<int>Cricket;
	std::vector<int>Football;
	std::vector<int>Other;
	std::vector<int>None;

	std::vector<int>* Sports[4]{&Cricket, &Football, &Other, &None};

	Game()
	{
	}

public:

	void getSportsRollNos(int num)
	{
		std::cout << "Roll numbers playing Sports " << num + 1 << " are :- \n"; 

		for(int i = 0; i < Sports[num]->size(); ++i)
		{
			std::cout << (*(Sports[num]))[i] << " ";
		}

		std::cout << '\n';
	}

	void bothCricketFootball()
	{
		for(int i = 0; i < Cricket.size(); ++i)
		{
			for(int j = 0; j < Football.size(); ++j)
			{
				if(Cricket[i] == Football[j])
				{
					std::cout << Cricket[i] << " "; 
				}
			}
		}
	}

	void onlyCricket()
	{
		for(int i = 0; i < Cricket.size(); ++i)
		{
			bool flag1 = false;
				
			for(int j = 1; j < 3; ++j)
			{
				for(int k = 0; k < Sports[j]->size(); ++k)
				{
					if(Cricket[i] == (*(Sports[j]))[k])
					{
						flag1 = true;
						break;
					}
				}
					
				if(flag1)
				{
					break;
				}
				
			}		
				
			if(flag1)
			{
				continue;
			}
				
			else
			{
				std::cout << Cricket[i] << " ";
			}
		}	
	}


	void onlyFootball()
	{
		for(int i = 0; i < Football.size(); ++i)
		{
			bool flag1 = false;
				
			for(int j = 0; j < 3; j = j + 2)
			{
				for(int k = 0; k < Sports[j]->size(); ++k)
				{
					if(Football[i] == (*(Sports[j]))[k])
					{
						flag1 = true;
						break;
					}
				}
					
				if(flag1)
				{
					break;
				}
				
			}

	
			if(flag1)
			{
				continue;
			}
				
			else
			{
				std::cout << Football[i] << " ";
			}
		}	

	}


	void eitherCricketFootballOrBoth()
	{	
		onlyCricket();
		onlyFootball();
		bothCricketFootball();
	}

};


// class  Class :- Will have Students array as a property.
// and Strength as number of students


class Class : public Game 
{
protected:

	Student *m_students;  // class will have an array of students lets allocate it dynamically.
	int m_strength;       // It will have some total number of students.

public:

	Class(int strength = 0) : m_strength(strength)
	{
		m_students = new Student[m_strength];

	}

	~Class()
	{
		delete[] m_students;
	}

	void getClassData()
	{	
		for(int i = 0; i < m_strength; ++i)  // we sort the roll numbers in acsending order. 
		{
			int k = i;			

			for(int j = i + 1; j < m_strength; ++j)
			{
				if(m_students[j].getRollNo() < m_students[k].getRollNo())
				{
					k = j;
				}
			}
			
			swap(m_students[i],m_students[k]);
		}

		for(int i = 0; i < m_strength; ++i)
		{
			std::cout << m_students[i].getRollNo() << " : " << m_students[i].getName() << '\n';
		}
	}
	
	void setClassData()
	{
		for(int i = 0; i < m_strength; ++i)
		{
			while(true)
			{
				bool x = false;	// to check if the if loop is executed.
	
				std::cin >> m_students[i];	
	
				for(int j = 0; j < i; ++j)
				{
					if(m_students[i].getRollNo() == m_students[j].getRollNo())
					{
						x = true; // is executed then break, we have to have a bool variable since
							  // it might also be the case that the for loop  actally completed 
							  // executing the loop without ever entering the if loop so we wont be able
							  // to differentiate between break and for loop being completed.
						break;
					}
				}
				
				if(x) // if number already present then again ask for input.
				{
					std::cout << m_students[i].getRollNo() << " roll no already present enter other number\n";
						
					continue;
				}
				
				else
				{
					break;
				}			
		}	
	
		}	
	}

	std::string getStudent(int roll_no)
	{
		for(int i = 0; i < m_strength; ++i)
		{
			if(roll_no == m_students[i].getRollNo())
			{
				return m_students[i].getName();			
			}
		}

		std::cout << "Roll number not found.\n";
	} 	


	void setDataSports()
	{
		char input;		

		while(true)
		{
			int number;
	
			std::cout << "\nEnter 1 for inputing Criket data\n";
			std::cout << "Enter 2 for inputing Football data\n";
			std::cout << "Enter 3 for inputing data of students playing game other than cricket or football\n";

			std::cout << "\nNumber : - ";
	
			while(true)
			{
				std::cin >> number;
					
				if((number != 1) && (number != 2) && (number != 3))
				{
					std::cout << "\nInvalid input enter again\n";
	
					continue;
				}
				
				else
				{
					break;
				}
			}

			int roll_no;
			char ip;
		
			std::cout << "\nEnter roll numbers for the selected game\n\n";
			
			while(Sports[number - 1]->size() < m_strength)
			{
				bool flag1(false),flag2(false);
	
				std::cout << "Enter roll number :- ";
				std::cin >> roll_no;
	
				for(int i = 0; i < m_strength; ++i)
				{
					if(roll_no == m_students[i].getRollNo())	
					{
						flag1 = true;
					
						break;
					}
				}

				for(int i = 0; i < Sports[number - 1]->size(); ++i)
				{
					

					if(roll_no == (*(Sports[number - 1]))[i])
					{
						flag2 = true;

						std::cout << "Roll number already present Enter another roll number.\n";
					
						break;
					}
				}
				
				if(flag2)
				{
					continue;
				}
				
				if(!flag1)
				{
					std::cout << "Roll number not present Enter again\n";
					
					continue;
				}
	
				else
				{
					Sports[number - 1]->push_back(roll_no);

					if(Sports[number - 1]->size() == m_strength)
					{
							break;
					}

					std::cout << "Want to Continue : ";
	
					std::cin >> ip;
	
					if((ip == 'N') || (ip == 'n'))
					{
						std::cout << "Total students in this game are : " << Sports[number - 1]->size() << '\n';
					
						break;
					}
				}
			}
		
			std::cout << "Do you want to enter for other Sports :- ";
			std::cin >> input;	
	
			if(input == 'N')
			{
				int num1 = 3;
				
				bool flag = false;

				while(num1 > 1)
				{
					num1--;					

					if(Sports[num1 - 1]->size() == m_strength)
					{
						flag = true;
						break;
					}
					
				}
				
				if(flag)
				{
					break;
				}
	
				for(int i = 0; i < m_strength; ++i)
				{
					bool flag1 = false;
	
					for(int j = 0; j < 3; ++j)
					{
						for(int k = 0; k < Sports[j]->size(); ++k)
						{
							if(m_students[i].getRollNo() == (*(Sports[j]))[k])
							{
								flag1 = true;
								break;
							}
						}
								
						if(flag1)
						{
							break;
						}
					}

					if(flag1)
					{
						continue;
					}
					
					else
					{
						None.push_back(m_students[i].getRollNo());
					}	
				}
		
			break;	
			}
			
		}	
		
	}

};




int main()
{
	Class SE3(5);

	SE3.setClassData();

	SE3.setDataSports();

	SE3.getClassData();

	for(int i = 0; i < 4; ++i)
	{
		SE3.getSportsRollNos(i);
	}

	std::cout << "Roll numbers playing both Cricket and Football are :- \n";

	SE3.bothCricketFootball();

	std::cout << '\n';

	std::cout << "Roll numbers playing only cricket are :- \n";
		
	SE3.onlyCricket();
	
	std::cout << '\n';
	
	std::cout << "Roll numbers playing only Football are :- \n";

	SE3.onlyFootball();

	std::cout << '\n';

	std::cout << "Roll numbers playing either Cricket or Football or both are :- \n";
		
	SE3.eitherCricketFootballOrBoth();
	
	std::cout << '\n';

return 0;
}


