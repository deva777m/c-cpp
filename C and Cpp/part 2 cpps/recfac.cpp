#include<iostream>
int facto(int n)
{
   int factorial;
   if(n>1)
     factorial = n*facto(n-1);
   else
     return 1;
}

int main()
{
   int n;
   std::cout<<"Enter number\n";
   std::cin>>n;
   std::cout<<"The factorial of "<<n<<" is "<<facto(n)<<"\n";
}
