#include<iostream>
#include<stdio.h>

class Node
{
public :

	std::string _job;
	int _prority;
	Node *_next;	

	Node(std::string job, int prority = 1) : _job(job), _prority(prority)
	{
		_next = NULL;
	}
	
	void erase()
	{
		this-> _job = "";
		this-> _prority = 0;
		this-> _next = NULL;
		
	}
};

class Queue
{
private :

	int _prority;
	Node *front;
	Node *rear;
	
public :
	
	Queue(int pror = 0) : _prority(pror)
	{
		front = NULL;
		rear = NULL;
	}
	
	
	Queue ENqueue(std::string job , int prority)
	{
		if(!front)
		{
			front = new Node(job, prority);
			rear = front;
		
		return *this;
		}
		
		else
		{
				if(prority != front-> _prority)
				{
					return Queue(prority);
				}
		
				Node *tempr = rear;

				Node *_new = new Node(job, prority);
				
				if(front == rear)
				{
					front-> _next = _new;
				}
					
				tempr-> _next = _new;
				rear = _new;	
		
		return *this;		
		}
	}
	
	
	void Dqueue()
	{
		if(!front)
		{
			std::cout << "Queue is empty\n";
			
		return;
		}
		
		if(front == rear)
		{
			front-> erase();
			front = NULL;
			delete front;
			
		return;
		}
		
		Node *temp = front;
		
		front = front-> _next;
		temp-> erase();
		temp = NULL;
		delete temp;
	}
	
	
	void print()
	{
		if(!front)
		{
			std::cout << "Queue is empty\n";
		
		return;
		}
	
		for(Node *i = front; i != NULL  ; i = i-> _next)
		{
			std::cout << i-> _job << "(" << i-> _prority << ") "; 
		}
		
		std::cout << "\n";
	}
	
	inline int getPror() { return this-> _prority; }
	
	bool is_empty() 
	{ 
		if(front == NULL) 
			return true; 
		else 
			return false; 
	}
	
};

int main()
{
	Queue q1(1), q2(2), q3(3);
	
	int choice;
	char ip;
	
	while(true)
	{
		std::cout << "\nEnter 1 to add to queue\n";
		std::cout << "Enter 2 to delete from queue\n";
		std::cout << "Enter 3 to print Queue\n";
	
		std::cout << ":- ";	
		std::cin >> choice;
		
		switch(choice)
		{
			case 1 :
			{
				std::string job;
				int pror;
	
				std::cout << "Enter job\n:- ";
				std::cin >> job;
		
				std::cout << "Enter prority\n:- ";
				std::cin >> pror;
				
				if(q1.getPror() != pror)
				{
					if(q2.getPror() != pror)
					{
						if(q3.getPror() != pror)
						{
							std::cout << "Prority not allowed\n";
						}
						
						else
						{		
							q3.ENqueue(job, pror);
						}	
					}
					
					else
					{
						q2.ENqueue(job, pror);
					}					
				}
				
				else
				{
					q1.ENqueue(job, pror);
				}
					
			break;
			}
			
			case 2 :
			{
				if(q1.is_empty())
				{
					if(q2.is_empty())
					{ 
						if(q3.is_empty())
						{
							std::cout << "All Tasks are done, well done CPU\n";
						}
						
						else
						{
							q3.Dqueue();
						}
					}
					
					else
					{
						q2.Dqueue();
					}
				}
				
				else
				{
					q1.Dqueue();
				}
			
			break;
			}
			
			case 3 :
			{
				q1.print();
				std::cout << '\n';
				q2.print();
				std::cout << '\n';
				q3.print();
				std::cout << '\n';
				
			break;
			}
			
			default:
			{
				std::cout << "\n Invalid choice enter again\n";
			}
		}
	}
	
return 0;
}
