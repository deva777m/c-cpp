#include<iostream>

int main()
{
	int a[5]{1,2,3,4,5};

	int (*ptr)[5] = &a; // here paranthesis ensures that ptr is a pointer pointing to array containing 5 elements 
			   // and is not a array of 5 pointer, Array of 5 pointers will be decalred as follows.

	int *p[3]{ &a[0], &a[1], &a[2]};  // This is the declaration of array of 3 pointers in contrast to above example.  


	std::cout << a << " " << p[0] << '\n';  // both prints address of 1st element

	std::cout << ptr << '\n';  // even this prints the address of 1st elemnt

/*      This might seem confusing, since our assumtion is that 'a' itself is pointer cointaing address of 1st element say 1000 
				
				i.e     a  [1000]  // value
					    2000   // address

	and when we declare line 7 that is ptr pointing to array that is ptr is pointing to 'a' so ptr will contain value 2000 i.e address  		of 'a' and itself will have some address 

				i.e     ptr [2000]  // value
					     3000   // address

	But when we print ptr in 15 it still print 1000 , this concludes that a itself doesnt have any significance that is having its own 		memory but it decays into ptr when we force it or pass it to any function.
	
	So to conclude ptr will contain the address of first element.

	This can also be simply declared as

	int *ptr = a;  

	but the sytax int (*ptr)[5] even though similar to *ptr is actually important in multidimentional arrays. */ 
}
