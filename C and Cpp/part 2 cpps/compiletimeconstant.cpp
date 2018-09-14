#include<iostream>
int main()
{
  int num;
  std::cin>>num; 
  int array[num];
  for(int i=0;i<num;i++)
  std::cin>>array[i];
  for(int i=0;i<num;i++)
  std::cout<<array[i]<<" ";
  
}
