// SE-3 F-3
// Roll no 21335

#include<iostream>
#include<cassert>

class MyString
{
private:

	int m_length;
	char *m_string;
	
public:
	
	MyString(const char* string="") : m_length(0)
	{
		for(int i = 0; string[i] != '\0'; ++i)
		{
			++m_length;
		}
		
		m_string = new char[m_length + 1];
		
		for(int i = 0; string[i] != '\0'; ++i)
		{
			m_string[i] = string[i];
		}
		
		m_string[m_length] = '\0';
	}	
	
	MyString(char* string) : m_length(0)
	{
		for(int i = 0; string[i] != '\0'; ++i)
		{
			++m_length;
		}
		
		m_string = new char[m_length + 1];
		
		for(int i = 0; string[i] != '\0'; ++i)
		{
			m_string[i] = string[i];
		}
		
		m_string[m_length] = '\0';
	}	
	
	MyString(int length) : m_length(length)
	{
		m_string = new char[m_length + 1];
	}
	
	MyString(const MyString &s)
	{
		m_length = s.getLength();
		
		m_string = new char[m_length + 1];
		
		for(int i = 0; i < m_length ; ++i)
		{
			m_string[i] = s.m_string[i];
		}
		
		m_string[m_length] = '\0';
	}
	
	~MyString()
	{
		delete[] m_string;
	}
	
	
	static int constStringLength(const char *str)
	{
		int length = 0;
	
		for(int i = 0; str[i] != '\0'; ++i)
		{
			++length;
		}
	return length;	
	}
	
	void print() { std::cout << m_string << '\n'; } 

	int getLength() { return m_length; }
	
	int getLength() const { return m_length; }
	
	
	MyString& operator=(const MyString &s)
	{
		
		if(this == &s)
		{
			return *this;
		}
	
		m_length = s.getLength();
		
		m_string = new char[m_length];
			
		for(int i = 0; i < m_length ; ++i)
		{
			m_string[i] = s.m_string[i];
		}
			
		m_string[m_length] = '\0';
		
	return *this;
	}
	
	
	friend MyString operator+(const MyString &a, const MyString &b)
	{
		MyString add(a.getLength() + b.getLength());
		
		int temp1(0),temp2(0);
		
		temp1 = a.getLength();
		temp2 = b.getLength();
		
		int i; 
		
		for(i = 0; i < temp1; ++i)
		{
			add.m_string[i] = a.m_string[i];
		}
		
		for(int j = 0; j < temp2; ++j)
		{
			add.m_string[i++] = b.m_string[j];
	
		}
		
		add.m_string[add.m_length] = '\0';
	
	return add;	
	} 
	
	
	friend bool operator==(const MyString &s1, const MyString &s2)
	{
		int length = s1.m_length > s2.m_length ? s1.m_length : s2.m_length;
	
		for(int i = 0; i < length; ++i)
		{
			if(s1.m_string[i] != s2.m_string[i])
			{
				return false;
			}
		}
		
		return true;
	}
	
	MyString reverse()
	{
		MyString rev(m_length);
		
		for(int i = 0; i < m_length; ++i)
		{
			rev.m_string[m_length - 1 - i] = m_string[i];
		}
		
		rev.m_string[m_length] = '\0';
	
	return rev;	
	}
	
	void checkSubstring(char *str)
	{
		int length = 0;
		int counter = 0;
	
		for(int i = 0; str[i] != '\0'; ++i)
		{
			++length;
		}
		
		for(int i = 0; i < m_length; ++i) // Hello
		{
			
			if(m_string[i] == str[counter++])
			{	
				if(counter == length)
				{
					std::cout << "Yes substring ("<< str <<")  present.\n";
					
				return;
				}
			}
			
			else
			{
				counter = 0;
			}
		}
		
		std::cout << "No the substring (" <<  str  << ") is absent.\n";
	}
	
	
	int charOccur(char c)
	{
		int counter = 0;
	
		for(int i = 0; i < m_length; ++i)
		{
			if(m_string[i] == c)
			{
				++counter;
			}
		}
		
	return counter;	
	}
	
	
	MyString removeSubstring(int start, int len)
	{
		int end = start + len - 1;
		
		int i = 0;
		int length = m_length;
		
		length = length - (end - start + 1);
		
		MyString temp(length);
	
		for(; i < start; ++i)
		{
			temp.m_string[i] = m_string[i];
		}
		
		for(int j = end + 1; j < m_length; j++)
		{
			temp.m_string[i++] = m_string[j];
		}
		
		temp.m_string[temp.m_length] = '\0';
		
	return temp;	
	}
	
	
	MyString charDelete(char c)
	{
		int count = this->charOccur(c);
		
		int length = m_length - count;
		
		MyString temp(length);
		
		int i = 0, j = 0 ;
		
		for(; i < m_length; i++)
		{
			if(m_string[i] == c)
			{
				i++;
			}
			
			temp.m_string[j++] = m_string[i];
		}
		
	return temp;
	}
	
	bool palindrome()
	{
		for(int i = 0; i < m_length; ++i)
		{
			if(m_string[i] != m_string[m_length - i - 1])
			{
				return false;
			}
		}
		
	return true;
	}
	
	MyString replaceSubstring(int start, int len, char *replace)
	{
		int end = start + len - 1;
	
		int length1 = constStringLength(replace);
		int length2 = end - start + 1;
	
		int i = 0;
		int length = m_length - length2 + length1;
		
		MyString temp(length);
	
		for(; i < start; i++)
		{
			temp.m_string[i] = m_string[i];
		}
		
		for(int k = 0; k < length1; ++k)
		{
			temp.m_string[i++] = replace[k];
		}
		
		for(int j = end + 1; j < m_length; j++)
		{
			temp.m_string[i++] = m_string[j];
		}
		
		temp.m_string[temp.m_length] = '\0';
		
	return temp;	
	}
};


int main()
{
	char string[100],ip;
	int option; 
	
	std::cout << "Enter string : - ";
	
	std::cin >> string;
	
	MyString s(string);
	
	std::cout << "\nEnter 1 to get Length of the String.\n";
	std::cout << "Enter 2 for printing the Current string.\n";
	std::cout << "Enter 3 for checking if a substring.\n";
	std::cout << "Enter 4 for replacing a substring.\n";
	std::cout << "Enter 5 to check the occurance of a character.\n";
	std::cout << "Enter 6 for deleting a character.\n";
	std::cout << "Enter 7 to check if the string is palindrome or not.\n";
	std::cout << "Enter 8 to reverse the string.\n";
	std::cout << "Enter 9 to remove a substring.\n";
	std::cout << "Enter 10 to concatanate to string.\n";
	std::cout << "Enter 11 to check if to strings are equal.\n\n";
	
	while(true)
	{
	
		std::cout << "Enter number : - ";
		std::cin >> option;
	
		switch(option)
		{
			case 1:
			{
				std::cout << "The length is " << s.getLength() << '\n';
			break;	
			}
			
			case 2:
			{
				s.print();
			break;	
			}
			
			case 3:
			{
				char sub[50];
				
				std::cout << "Enter the Substring : - ";
				std::cin >> sub;
				
				s.checkSubstring(sub);
			break;	
			}
			
			case 4:
			{
				char sub1[50]; 
				int start,end,len;
				
				int length = s.getLength();
				
				std::cout << "Enter the Substring to replace : - ";
				std::cin >> sub1;
				
				std::cout << "Enter the start position and length to replace : - ";
				std::cin >> start >> len;
				
				end = start + len - 1;
				
				if(end > length)
				{
					std::cout << "Length exceeding string.\n";
				
				break;	
				}
				
				else if(start <= 0)
				{
					std::cout << "Invalid start.\n";
				}
				
				s.replaceSubstring(start - 1, len , sub1).print();
			
			break;	
			}
			
			case 5:
			{
				char temp;
				
				std::cout << "Enter the character whose occurance you want to check : - ";
				std::cin >> temp;
				
				std::cout << "The character has occured " << s.charOccur(temp) << '\n'; 
				
			break;	
			}
			
			case 6:
			{
				char temp1;
				
				std::cout << "Enter the character which you want to delete : - ";
				std::cin >> temp1;
				
				s.charDelete(temp1).print();
				
			break;		
			}
			
			case 7:
			{
				if(s.palindrome())
				{
					std::cout << "Yes it is a palindrome.\n";
				}
				
				else
				{
					std::cout << "No it isnt a palindrome.\n";
				}
				
			break;	
			}
			
			case 8:
			{
				s.reverse().print();

			break;	
			}
			
			case 9:
			{
				int s1,e,len;
				int length = s.getLength();
				
				std::cout << "Enter the start position and length to delete : - ";
				std::cin >> s1 >> len;
				
				e = s1 + len - 1;
				
				if(e > length)
				{
					std::cout << "Length exceeding string.\n";
				
				break;	
				}
				
				else if(s1 <= 0)
				{
					std::cout << "Invalid start.\n";
				
				break;	
				}
				
				s.removeSubstring(s1 - 1, len).print();
			
			break;	
			}
			
			case 10:
			{
				char string1[100];
				
				std::cout << "Enter the string you want to concatenate : - ";
				std::cin >> string1;
				
				MyString s1(string1);
				
				(s + s1).print();
	
			break;	
			}
			
			case 11:
			{
				char string2[100];
				
				std::cout << "Enter the other string : - ";
				std::cin >> string2;
				
				MyString s1(string2);
				
				if(s == s1)
				{
					std::cout << "They are equal.\n";
				}
				
				else
				{
					std::cout << "No, they arent equal.\n";
				}
				
			break;	
			}
			
			default:
			{
				std::cout << "Invalid input enter again\n";
				continue;
			}
			
		}
		
		std::cout << "Do you want to continue : - ";
		
		bool check = false;
		
		while(true)
		{
			std::cin >> ip;
			
			if((ip == 'Y') || (ip == 'y'))
			{
				break;
			}
		
			else if(((ip == 'N') || (ip == 'n')))
			{
				check = true;
				break;
			}
		
			else
			{
				std::cout << "Invalid input enter again : - ";
				continue; 
			}
		}
		
		if(check)
		{
			std::cout << "Thank you.\n";
			break;
		}	
	}
}
