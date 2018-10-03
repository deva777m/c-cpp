#include<iostream>
#include<cmath>

class Node
{
public :

	bool _data;
	Node *_next;
	Node *_prev;

	Node(bool data = false) : _data(data)
	{
		_next = NULL;
		_prev = NULL;
	}
};


class Binary
{
private:

	Node *head;
	
public :

	Binary()
	{
		head = NULL;
	}	

	void append(bool data)
	{
		if(!head)
		{
			head = new Node(data);
		
		return;	
		}
		
		Node *temp = head;
		
		Node *_new = new Node(data);
		
		while(temp-> _next != NULL)
		{
			temp = temp-> _next;
		}
		
		temp-> _next = _new;
		_new-> _prev = temp;
		_new-> _next = NULL;
	}
	
	
	void firstAppend(bool data)
	{
		if(!head)
		{
			head = new Node(data);
		
		return;	
		}
		
		Node *_new = new Node();
		_new-> _data = head-> _data;
		_new-> _next = head-> _next;
		_new-> _prev = head-> _prev;
		_new = head;
		
		head = new Node(data); 
		
		head-> _next = _new;
		head-> _prev = NULL;
		
		_new-> _prev = head;
		}	

	
	void printBinary()
	{
		if(!head)
		{
			std::cout << "Number not found\n";
			return;
		}
	
		Node *temp = head;
		
		while(temp != NULL)
		{
			std::cout << temp-> _data;
			temp = temp-> _next;
		}
		
		std::cout<< '\n';	
	}
	
	void decimalToBinary(int decimal)
	{
		static int count = 0;
	
		if(decimal == 0)
		{
			if(!count)
			{
				this-> append(0);
			
			return;	
			}
		
		return;
		}
		
		++count;
		
		this-> decimalToBinary(decimal/2);
		
		this-> append(decimal % 2);		
	}
	
	
	int binaryToDecimal()
	{
		if(!head)
		{
			return 0;
		}
		
		Node *temp1 = head;
		Node *temp2 = head;
	
		int deci = 0;
		int count = 1;
		
		while(temp1-> _next != NULL)
		{
			temp1 = temp1-> _next;
			++count;
		}

		while(temp2 != NULL)
		{
			--count;
			deci += temp2-> _data * pow(2, count);
			temp2 = temp2-> _next;
		}
	
	return deci;		
	}

	void setBinary(int decimal)
	{
		this-> decimalToBinary(decimal);
	}

	
	void oneS()
	{
		Node *temp = head;
		
		while(temp != NULL)
		{
			temp-> _data = (!temp-> _data);
			temp = temp-> _next;
		}
		
	}
	
	void twoS()
	{
		Binary B1;
		B1.setBinary(1);

		this-> oneS();

		*this = *this + B1;	
	}
	
	void backwardPrint()
	{
		Node *temp = head;
		
		while(temp-> _next != NULL)
		{
			temp = temp-> _next;
		}
		
		while(temp != NULL)
		{
			std::cout << temp-> _data;
			temp = temp-> _prev;
		}
		
		std::cout << '\n';
		
	}
	
	friend Binary operator+(const Binary &B1, const Binary &B2);

};


Binary operator+(const Binary &B1, const Binary &B2)
{
	Binary add;
	bool carry = false;

	Node *temp1 = B1.head;
	Node *temp2 = B2.head;
		
	while(temp1-> _next != NULL || temp2-> _next != NULL)
	{
		if(temp1-> _next)
		{
			temp1 = temp1-> _next;
		}
		
		if(temp2-> _next)
		{
			temp2 = temp2-> _next;
		}
	}
	
	while(temp1 != NULL && temp2 != NULL)
	{
		if(int(temp1-> _data) + int(temp2-> _data) + int(carry) == 0)
		{
			add.firstAppend(false);
			carry = false;
		}
	
		else if(int(temp1-> _data) + int(temp2-> _data) + int(carry) == 1)
		{
			add.firstAppend(true);
			carry = false;
		}
		
		else if(int(temp1-> _data) + int(temp2-> _data) + int(carry) == 2)
		{
			add.firstAppend(false);
			carry = true;
		}
		
		else if(int(temp1-> _data) + int(temp2-> _data) + int(carry) == 3)
		{
			add.firstAppend(true);
			carry = true;
		}
		
		temp1 = temp1-> _prev;
		temp2 = temp2-> _prev;
	}
	
	if(!temp1)
	{
		while(temp2 != NULL)
		{
			if(!carry)
			{
				add.firstAppend(temp2-> _data);
				carry = false;		
			}
			
			else
			{
				if(int(temp2-> _data) + int(carry) == 1)
				{
					add.firstAppend(true);
					carry = false;		
				}

				else
				{
					add.firstAppend(false);
					carry = true;
				}
			}

			temp2 = temp2-> _prev;
		}
	}
	
	if(!temp2)
	{
		while(temp1 != NULL)
		{
			if(!carry)
			{
				add.firstAppend(temp1-> _data);
				carry = false;		
			}
			
			else
			{
				if(int(temp1-> _data) + int(carry) == 1)
				{
					add.firstAppend(true);
					carry = false;		
				}

				else
				{
					add.firstAppend(false);
					carry = true;
				}
			}

			temp1 = temp1-> _prev;
		}
	}

	if(carry)
	{
		add.firstAppend(true);
	}
	

return add;		
}

int main()
{
	int choice;
        char ip;
        bool flag = false;
        Binary B1;
        Binary B2;

        while(true)
        {
                std::cout << "\nEnter 1 for inputing Binary number 1\n";
                std::cout << "Enter 2 for inputing Binary number 2\n";
                std::cout << "Enter 3 for oneS complement of Binary 1\n";
                std::cout << "Enter 4 for twoS complement of Binary 1\n";
                std::cout << "Enter 5 for addition of Binary1 an Binary 2\n";        

                std::cout << "\n:- ";
                std::cin >> choice;

                switch(choice)
                {
                       case 1:
                       {
                                int b;
                                
                                std::cout << "Enter number in decimal :- ";
                                std::cin >> b;

				if(b < 0)
				{
					B1.setBinary(-b);
					B1.twoS();
					//B1.append(1);
					B1.printBinary();
				
				break;				
				}

                                B1.setBinary(b);
                                B1.printBinary();

                       break;
                       }

                       case 2:
                       {
                                int b;
                                
                                std::cout << "Enter number in decimal :- ";
                                std::cin >> b;

                                B2.setBinary(b);
                                B2.printBinary();
                
                       break;
                       }

                       case 3:
                       {
                                Binary temp(B1);
                                temp.oneS();

                                temp.printBinary();

                       break;
                       }

                       case 4:
                       {
                                Binary temp(B1);
                                temp.twoS();

                                temp.printBinary();
                       
                        break;                        
                        } 

                       case 5:
                       {
                                Binary temp(B1 + B2);
                                temp.printBinary();

                       break;
                       }

                       default :
                       {
                                std::cout << "Invalid input enter again\n";
                                continue;
                       }
                }

                std::cout << "\nDo you want to continue\n";
                
                while(true)
                {
                        std::cout << ":- ";
                        std::cin >> ip;

                        if(ip != 'n' && ip != 'N' && ip != 'y' && ip != 'Y')
                        {
                                std::cout << "Invalid input enter again\n";
                                continue;
                        }

                        else if(ip == 'N' || ip == 'n')
                        {
                                flag = true;
                                break;
                        }
                        
                        else
                        {
                                break;
                        }                        
                }
	
        	if(flag)
                {
                        std::cout << "\nThank you !\n";
                        break;
                }
        }
        	

return 0;
}
