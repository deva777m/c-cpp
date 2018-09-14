#include<iostream>
#include<vector>

struct StudentGrade {

	std::string name;
	char grade;

};

class GradeMap {

private:

	std::vector<StudentGrade>m_map;

public:

	GradeMap() {}

	char& operator[] (const std::string &s);

};

char& GradeMap::operator[] (const std::string &s) {

	for(StudentGrade &ref : m_map) {
		if(ref.name==s)
			return ref.grade;
    }

    StudentGrade temp{s,' '};
    
	m_map.push_back(temp);
  
    std::cout<<m_map.capacity()<<"\n";

	return m_map.back().grade;
}

int main()
{   
 
	GradeMap grades;
 
	char& gradeJoe = grades["Joe"];
	gradeJoe = 'A'; // does a push_back
 
	char& gradeFrank = grades["Frank"];
	gradeFrank = 'B'; // does a push_back	
 
	char& gradeSaumi = grades["Saumi"];
	gradeSaumi = 'F'; // does a push_back
 
	std::cout << "Joe has a grade of " << gradeJoe << '\n';
	std::cout << "Frank has a grade of " << gradeFrank << '\n';
    std::cout << "Saumi has a grade of " << gradeSaumi << '\n';
 	return 0;
}
