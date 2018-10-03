#include <iostream>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 10
using namespace std;
class stack
{		public:
			int top;
			char data[MAX];
			stack()
			{
				top=-1;
			}
			int full();
			int empty();
			char pop();
			void push(char );
			float evaluate(char* p);
			string postfix(char* );
			int phigh(char x);
			int check(char* );
			int pair(char );
			char peek();
			

};
char stack::peek()
{
	if(!empty())
	{
		return data[top];
	}
	else
		return '#';
}
int stack::phigh(char x)
{
	if(x=='+' || x=='-')
	{
		return 1;
	}
	else if(x=='*' || x=='/')
	{
		return 2;
	}
	else if(x=='^')
	{
		return 3;
	}
	else
		return -1;
}
int stack::pair(char x)
{
	if(x==')' && data[top]=='(') return 1;
	else if(x=='}' && data[top]=='{') return 1;
	else if(x==']' && data[top]=='[') return 1;
	else return 0;	
}
int stack::check(char* str)
{int i=0;
	
	while(str[i]!='\0')
	{
		if(str[i]=='[' || str[i]=='{' || str[i]=='(')
		{
			push(str[i]);
		}
		else if(str[i]==']' || str[i]==')' || str[i]=='}')
		{
			
			if(empty() || !pair(str[i]))
			{
			
				return 0;
				
			}
			if(pair(str[i]))
			pop();	
		}	
	
		i++;
	}
	return empty()?1:0;
}
string stack::postfix(char *p)
{	string s;
	s.assign("");
	int i=0;
	for(i=0;p[i]!='\0';i++)
	{
		if(p[i]>='a' && p[i]<='z')
		{	
			s=s+p[i];
		}
		else if(p[i]=='+'|| p[i]=='-' || p[i]=='*' || p[i]=='/' || p[i]=='^')
		{
			if(phigh(p[i])<=phigh(peek()))
			{
				while(phigh(p[i])<=phigh(peek())){
					char c=pop();
					s=s+c;
				}
				push(p[i]);
			}
			else
			{
				push(p[i]);
			}
		}
		else if(p[i]=='(')
		{
			push(p[i]);
		}
		else if(p[i]==')')
		{
			while(peek()!='(')
			{	char c=pop();
				s=s+c;
			}
			if(peek()=='(')
			{
				pop();
			}
		}
	}
	while(!empty())
	{
		s=s+pop();

	}
	/*i=0;
	cout<<"Postfix expression is:"<<endl;
	while(s[i]!='\0') 
	{	cout<<s[i];
		i++;
	}*/
	return s;
}
int stack::empty()
{
	if(top==-1)
	{
		return 1;
	}
	else return 0;
}
int stack::full()
{
	if(top==MAX-1)
	{
		return 1;

	}
	else return 0;
}
void stack::push(char x)
{
	if(!full())
	{
		top++;
		data[top]=x;
	}
}
char stack::pop()
{	char x;
	if(!empty())
	{
		x=data[top];
		top--;
		return x;
	}
	else
	{
		cout<<"Empty stack";
		return 0;
	}
}
float stack::evaluate(char *a)
{
	int i=0;float ans,x;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]>='a' && a[i]<='z')
		{
		cout<<"Enter numerical value of:"<<a[i]<<endl;
		cin>>x;
		push(x);	
		}
		else if(a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='^' || a[i]=='/')
		{	float b;
			float a1;
			float a2;
			a1=pop();
			a2=pop();
			switch(a[i])
			{
				case '+':
							b=a2+a1;
							push(b);
							break;
				case '-':
							b=a2-a1;
							push(b);
							break;
				case '*':
							b=a2*a1;
							push(b);
							break;
				case '/':
							b=a2/a1;
							push(b);
							break;
				case '^':
							b=pow(a2,a1);
							push(b);
							break;
							
			}
		}
	}
	ans=pop();
	cout<<"Answer:"<<ans<<endl;
}

int main() 
{
	stack obj;
	string str,postf,infix;
	cout<<"Enter the expression(in terms of alphabets):"<<endl;
	cin>>ws;
	getline(cin,str);
	if(obj.check(&str[0]) )
	{
		postf=obj.postfix(&str[0]);
	}
	else
	{
		cout<<"Expression not well parenthesized,cant evaluate"<<endl;
	}
	cout<<"Evaluation of:"<<postf<<endl;
	obj.evaluate(&postf[0]);

}
