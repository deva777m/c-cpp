#include<iostream>

int main()
{
	const int &ref = 3;
//	int &ref = 3;	// Compile error. Cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’.
		
return 0;	
}

// We will generally encounter this problem while operator overloading when we return a object by value and mistakely pass it by reference.
// So it is highly recommended to make your argument const references so it will handle the r-values.
