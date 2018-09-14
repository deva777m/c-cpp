#include<iostream>
#include<cstring>
struct students //4,5,3,5
{
  std::string name;
  int grade;
};
void selsort(int nos,students *studs)
{
     for(int i=0;i<=nos-1;i++)
   {
     int k=i;  //so that we can manipulate i in for2 without changing its value in for1
     for(int j=i+1;j<=nos;j++) //for2 for fixing 1st element and comparing with rest of them
     {
       if(studs[j].grade>studs[k].grade) // if this then start comparing from the index which we found smaller than first index 
       {             //this way we find the smallest and swap it with 1st element  
          k=j;       //then we repeat the procedure for remaining values ignoring the first.
       }
     }
     std::swap(studs[k],studs[i]);
   }  
    
}
int main()
{
  int nos;  //number of students
  std::cout<<"Enter number of student\n";
  std::cin>>nos;
  students *studs =new students[nos];
  for(int i=0;i<nos;i++)
  {
    std::cout<<"Enter name: "; 
    std::cin>>studs[i].name;
    std::cout<<"Enter grade: ";
    std::cin>>studs[i].grade;
  }
  selsort(nos,studs);
  for(int i=0;i<nos;i++)
  {
     std::cout<<studs[i].name<<" has "<<studs[i].grade<<"\n";
  }
  delete[] studs;
}
