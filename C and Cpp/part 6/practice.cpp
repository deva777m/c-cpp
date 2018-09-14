#include<iostream>
#include<string>

void seperate(std::string &s) 
{
	int i{0};

	while(i <= s.length())
	{
		if(s[i] != ' ')
			std::cout<<s[i];
		else
			std::cout<<'\n';
	
		i++;	
	}

	std::cout<<'\n';
}

int main()
{
	std::string s{"Real ass big ass dunak nigga Nigga"};

	seperate(s);

return 0;	
}
