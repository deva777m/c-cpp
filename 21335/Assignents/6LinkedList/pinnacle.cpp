#include<iostream>


class Node
{
public :

	int _PRN;
	std::string _name;
	Node *_next;

	Node(int PRN = 0,std::string name="") : _PRN(PRN), _name(name)
	{
		_next = NULL;		
	}
};		
 

class LinkedList
{
private :

	Node *head;
	int _members;

public :

	LinkedList()
	{
		head = NULL;
	}
	
	Node* getHead(){ return head; }

	
	void Append(int PRN, std::string name)
	{
		if(head == NULL)
		{	
			 head = new Node;
			 head-> _name = name;
			 head-> _PRN = PRN;
			 head-> _next = NULL; 
		
		return;	
		}
	
		Node *temp = head;
	
		Node *_new = new Node;
		_new-> _name = name;
		_new-> _PRN = PRN;
		
		while(temp-> _next != NULL)
		{
			temp = temp-> _next;
		}
		
		temp-> _next = _new;
		_new-> _next = NULL; 
	}
	
	void printClub()
	{
		Node *temp = head;
	
		while(temp != NULL)
		{
		
			std::cout << temp-> _PRN << "." << temp-> _name << '\n';
			
			temp = temp-> _next;
		}
	}
	
	void erase(Node *temp)
	{
		temp-> _name = '\0';
		temp-> _next = NULL;
		temp-> _PRN = 0;
		
		delete temp;	
	}
	
	void reversePrint(Node *temp)
	{
		if(temp-> _next == NULL)
		{
			std::cout << temp-> _PRN << "." << temp-> _name << '\n';
		
		return;
		}
		
		reversePrint(temp-> _next);
		
		std::cout << temp-> _PRN << "." << temp-> _name << '\n';
	}
	
	void remove(int PRN)
	{
		if(head-> _PRN == PRN)
		{
			Node *temp = head;
			
			head = head-> _next;
			
			erase(temp);
			
		return;	
		}
	
		Node *temp = head;
	
		while(temp-> _next-> _PRN != PRN)
		{
			temp = temp-> _next;
		}
		
		Node *temp2 = temp-> _next;
		
		temp-> _next = temp-> _next-> _next;
		
		erase(temp2);  
	}
	
	void swapNode(Node *x, Node *y)
	{	
		Node *temp = x;
		
		temp-> _PRN = x-> _PRN;
		temp-> _name = x-> _name;
		
		x-> _PRN = y-> _PRN;
		x-> _name = y-> _name;
		
		y-> _PRN = temp-> _PRN;
		y-> _name = temp-> _name;
		
	}
	
	void sort()
	{
		for(Node *i = head; i != NULL; i = i-> _next)
		{
			Node *k = i;
		
			for(Node *j = i-> _next; j != NULL; j = j-> _next)
			{
				if(j-> _PRN  <  k-> _PRN)
				{
					k = j;
				}
			}
			
			swapNode(i,k);
		}
	}

}; 
 
int main()
{

	
	LinkedList pinnacle;
	
	pinnacle.Append(0,"Principal");
	pinnacle.Append(1,"John");
	pinnacle.Append(3,"Saumitra");
	pinnacle.Append(2,"Harry");
	
	pinnacle.printClub();
	pinnacle.sort();
	
	std::cout << '\n';
	
	pinnacle.printClub();	

return 0;	
}
