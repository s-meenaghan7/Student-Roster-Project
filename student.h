#pragma once
#include "degree.h"
#include <string>

using std::string;

class Student {
private:
	string studentID;
	string first_name;
	string last_name;
	string email;
	int age;
	int *daysInCourse;
	DegreeProgram degreeProgram;

public:
	const static int daysInCourseSize = 3;
	//Constructors;
	Student();//empty
	Student(string sID, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degreeProgram);//full
	//Accessors (getters)
	string getID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int *getDaysInCourse();
	DegreeProgram getDegreeProgram();

	//Mutators (setters)
	void setID(string sID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDaysInCourse(int daysInCourse[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	//print() function to print specific student data
	void print();

	//Destructor
	~Student();
};
