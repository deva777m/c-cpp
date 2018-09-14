#include<iostream>
#include<typeinfo>
void printarr(int *arr)
{
   std::cout<<sizeof(arr);
}
int main()
{
   int array[5]{1,2,3,4,5};
   printarr(array);
}

