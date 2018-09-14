#include<iostream>
namespace animals
  {
     enum animals
     {
        MAN,
        CAT,
        DOG,
        ELEPHANT,
        SPIDER,
        CENTIPEDE,
        MAX_ANIMALS
     };
   }

int main()
{
 
  int legs[animals::MAX_ANIMALS]{2,4,4,4,8,100};
  printf("%d\n",legs[animals::CENTIPEDE]);
}
