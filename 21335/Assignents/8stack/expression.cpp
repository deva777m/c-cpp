#include<iostream>

class Node
{
public :

	char _data;
	Node *_down;

	Node(char data) : _data(data)
	{
		_down = NULL;
	}        
};


class Stack
{
private :

	Node *top;

public :

	Stack()
	{
		top = NULL;
	}

	void push(char ip)
	{
		if(!top)
		{
			top = new Node(ip);

		return;
		}
		
		Node *_new = new Node(ip);

		_new-> _down = top;
		top = _new;
	}

	void pop()
	{
		if(!top)
		{
			return;
		}

		Node *temp = top;
		Node *temp1 = top-> _down;

		temp-> _data = '\0';
		temp-> _down = NULL;
		temp = NULL;

		delete temp;

		top = temp1;
	}

	
	void check(std::string exp)
	{
		int i = 0;

		while(exp[i] != '\0')
		{
			char check = exp[i];

			if(check == '(' || check == '{' || check == '[')
			{
				this-> push(check);
				++i;
			}

			else if(check == ')' || check == '}' || check == ']')
			{
				char cur = top-> _data;
				
				if(check == ')' && cur == '(')
				{
					this-> pop();
					++i;
				}

				else if(check == '}' && cur == '{')
				{
					this-> pop();
					++i;
				}

				else if(check == ']' && cur == '[')
				{
					this-> pop();
					++i;
				}

				else
				{
					std::cout << "Expression invalid\n";
		
				return;
				}
				
			}

			else 
			{
				++i;
			}

		}

		if(top)
		{
			std::cout << "Expression invalid\n";		
		return;
		}

		else
		{
			std::cout << "Expression is valid\n";
		}
	}
	
	
};

int main()
{
	Stack Expression;

	std::string exp;

	getline(std::cin, exp);

	Expression.check(exp);

return 0;
}
