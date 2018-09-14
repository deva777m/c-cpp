#include<iostream>

bool answer()
{
	bool flag(false);
	char ip;
	
	while(true)
	{
		std::cin >> ip;

		if((ip == 'n') || (ip == 'N'))
		{
			return false;	
		}
	
		else if((ip == 'Y') || (ip == 'y'))
		{	
			return true;
		}
	
		else
		{
			std::cout << "invalid input enter again\n";
			continue;
		}
	}	
}

int main()
{
// 0 1 2 3

	int a;
	char ip;
	bool x0(false),x1(false),x2(false),x3(false),x4(false),x5(false);	

	while(true)
	{
		std::cout << "enter number : - ";
		std::cin >> a;

		switch(a)
		{
			case 0:
			{
				if(x0)
				{
					std::cout << "you already entered this.Enter again?? : -\n";
					
					if(answer())
					{
						continue;
					}
					
					else
					{
						break;
					}
				}

				x0 = true;
			break;
			}
		
			case 1:
			{
				if(x1)
				{
					std::cout << "you already entered this.Enter again?? : -\n";	

					if(answer())
					{
						continue;
					}
					
					else
					{
						break;
					}	
				}
	
				x1 = true;

			break;
			}
			
			case 2:
			{
				if(x2)
				{
					std::cout << "you already entered this.Enter again?? : -\n";	

					if(answer())
					{
						continue;
					}
					
					else
					{
						break;
					}	
				}

				x2 = true;	
			break;
			}

			case 3:
			{
				if(x3)
				{
					std::cout << "you already entered this.Enter again?? : -\n";	

					if(answer())
					{
						continue;
					}
					
					else
					{
						break;
					}	
				}

				x3 = true;

			break;	
			}

			default:
			{
				x4 = true;				

				std::cout << "Invalid input.";
			break;			
			}
		}

		std::cout << "do you want to continue : - "; 
		
		if(!answer())
		{
			break;
		}		
	}
}
