#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
void sortarray(string *names,int num)
{
   for(int i=0;i<num-1;i++)
  {
    int k=i;
    for(int j=i+1;j<num;j++)
    {
      if(names[j]<names[k])
        k=j;
    }
    swap(names[k],names[i]);
  } 
}
int main()
{
  int num;
  cout<<"Enter number of names:";
  cin>>num;
  string *names = new string[num];
  for(int p=0;p<num;p++)
    cin>>names[p];
  sortarray(names,num);
  for(int n=0;n<num;n++)
    cout<<names[n]<<"\n";
  delete[] names;
} 

