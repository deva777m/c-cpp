#include<iostream>
#include<chrono>

class Timer
{
private:
	// Type aliases to make accessing nested type easier
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;
 
	std::chrono::time_point<clock_t> m_beg;
 
public:
	Timer() : m_beg(clock_t::now())
	{
	}
 
	void reset()
	{
		m_beg = clock_t::now();
	}
 
	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};
 
const int length=100; 
long unsigned static int seed = 733738;

void swap(int &x,int &y)
{
   int temp;
   temp=x;
   x=y;
   y=temp;
}

int getrand()
{
   seed=(seed*8253732229+23922326403);
   return seed%100;
}
int main()
{
  
   int array[length];
   
   for(int i=0;i<length;i++)
   {
      array[i]=getrand();

      std::cout<<array[i]<<" ";
   }
  
   std::cout<<"\n\n";

   for(int i=0;i<length;i++)
   {
      int k=i;
      for(int j=1+k;j<length;j++)
      {
         if(array[j]<array[k])
            k=j;
      }
      swap(array[i],array[k]);
   }
   
   for(int i=0;i<length;i++)
   {
      std::cout<<array[i]<<" ";
   }

   std::cout<<"\n";

   Timer t;
   std::cout << "Time taken: " << t.elapsed() << "\n";
 return 0;   
}  

