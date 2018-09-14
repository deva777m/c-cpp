#include"test.h"
#include<iostream>
#include<typeinfo>

void fuc(T a)
{
	std::cout<<a<<"is a "<<typeid(a).name()<<'\n';
}
