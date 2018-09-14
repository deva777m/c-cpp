#include<iostream>
#include<vector>
void printstack(std::vector<int>&stack)
{
   for(const auto &elem : stack)
      std::cout<<elem<<" ";
   std::cout<<"The capacity is "<<stack.capacity()<<", The length is "<<stack.size()<<"\n";
}
int main()
{
   std::vector<int>stack{1,2,3,4,5};
   stack.reserve(4);
   printstack(stack);
   stack.push_back(6);
   printstack(stack);
}
