#include<iostream>
class Mystring {

private:
	std::string m_string;

public:
	Mystring(std::string s)
			: m_string(s) {
	}
	
	std::string operator()(int index ,int numofchars); 
	
};

std::string Mystring::operator()(int index ,int numofchars) {

	std::string temp;
	
	for(int i=index;i<(index+numofchars);i++) {
				
		temp=temp+m_string[i];
		
	}
	return temp;
}

int main() {

    Mystring string("Hello, world!");
    std::cout << string(7, 5)<<"\n"; // start at index 7 and return 5 characters
 
    return 0;
}
