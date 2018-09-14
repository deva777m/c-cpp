#include<iostream>
#include<string>
int main()

{
  const std::string names[]={"deva","dukya","tiruk","saumi","wadi","sush","akhya"};
  std::string s;
  std::cin>>s;
  bool found(false);
  for(const auto &ref : names)
    if(ref==s)
    {  
      found=true;
      break;
    }  
  if(found)
  std::cout<<s<<" is found\n";   
  else
  std::cout<<s<<" is not found\n";
}
