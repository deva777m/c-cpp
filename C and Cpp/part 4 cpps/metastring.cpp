#include<iostream>

void swap(char &a,char &b) 
{
	char temp;
	temp = a;
	a = b;
	b = temp;
}

bool check(char (&a)[1000], char (&b)[1000],const int length) // g e e k s
{
	int count1 = 0;

	for(int i=0;i<length;i++) 
	{
		if(a[i]==b[i])
		{
			count1++;
		}

		if(count1 == length)
		{
			return false;
		}
	}
	
	for(int i=0;i<length-1;i++)  // g e    g e
	{
		for(int j=i+1;j<length;j++) 
		{
			int count = 0;
	
			if(b[i]==b[j])
			{
				continue;
			}

			swap(b[i],b[j]);

			for(int i=0;i<length;i++) 
			{
						
				
				if(a[i]==b[i]) 
				{
					count++;
				}
			}

			if(count == length) 
			{
				return true;
			}

			else
			{
				swap(b[i],b[j]);
			}

		}

	}
				
return false;		
}

int main() 
{

    int T;
    
    std::cin>>T;

    while(T--)
    {
	char a[1000];
	char b[1000];
	int length;
	
	std::cin>>length;

	for(int i=0;i<length;i++) 
	{		
		std::cin>>a[i];
	}

	for(int i=0;i<length;i++) 
	{
		std::cin>>b[i];
	}
	
	std::cout<<(check(a,b,length))<<'\n';
    }
        
}
	
