#include<iostream>
#include<stdio.h>

class Node
{
public :

	std::string _job;
	Node *_next;	

	Node(std::string job) : _job(job)
	{
		_next = NULL;
	}
	
	void erase()
	{
		this-> _job = "";
		this-> _next = NULL;
		
	}
};

class Queue
{
private :

	Node *front;
	Node *rear;
	
public :
	
	Queue()
	{
		front = NULL;
		rear = NULL;
	}
	
	
	Queue ENqueue_back(std::string job)
	{
		if(!front)
		{
			front = new Node(job);
			rear = front;
		
		return *this;
		}
		
		else
		{
				Node *tempr = rear;

				Node *_new = new Node(job);
				
				if(front == rear)
				{
					front-> _next = _new;
				}
					
				tempr-> _next = _new;
				rear = _new;	
		
		return *this;		
		}
	}
	
	
	Queue ENqueue_front(std::string job)
	{
		if(!front)
		{
			front = new Node(job);
			rear = front;
		
		return *this;
		}
		
		else
		{
				Node *tempf = front;

				Node *_new = new Node(job);
				
				_new-> _next = front;	
				
				front = _new;
					
		return *this;		
		}
	}
	
	void Dqueue_front()
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
	
	
	void Dqueue_back()
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
		Node *tempr = rear;
		
		while(temp-> _next != NULL)
		{
			temp = temp-> _next;
		}
		
		rear = temp;
		temp-> _next = NULL;
		tempr-> erase();
		tempr = NULL;
		delete tempr;
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
			std::cout << i-> _job << " "; 
		}
		
		std::cout << "\n";
	}
	
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
	Queue q1;
	
	q1.ENqueue_back("job1");
	q1.ENqueue_back("job2");
	q1.ENqueue_back("job4");
	
	q1.Dqueue_back();
	q1.Dqueue_back();
	q1.Dqueue_back();
	q1.Dqueue_back();
	q1.print();

return 0;
}
