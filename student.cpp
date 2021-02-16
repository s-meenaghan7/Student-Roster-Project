#include "student.h"
#include <iostream>
#include <iomanip>
#include <string>

using std::string;
using std::left;
using std::cout;
using std::setw;
using std::cerr;

//implement the constructor, using ALL of the input parameters provided in the table
//implementing empty constructor first, setting all to default values, per video 2
Student::Student()
{
	this->studentID = "";
	this->first_name = "";
	this->last_name = "";
	this->email = "";
	this->age = 0;
	this->daysInCourse = new int[daysInCourseSize];
	for (int i{ 0 }; i < daysInCourseSize; i++) this->daysInCourse[i] = 0;
	this->degreeProgram;
}
//implement the constructor, using ALL of the input parameters provided in the table
Student::Student(string sID, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degreeProgram)
{
	this->studentID = sID;
	this->first_name = firstName;
	this->last_name = lastName;
	this->email = email;
	this->age = age;
	this->daysInCourse = new int[daysInCourseSize];
	for (int i{ 0 }; i < daysInCourseSize; i++) this->daysInCourse[i] = daysInCourse[i];
	this->degreeProgram = degreeProgram;
}

//implement the accessors (getter) for each instance variable in student.h
string Student::getID() { return studentID; }
string Student::getFirstName() { return first_name; }
string Student::getLastName() { return last_name; }
string Student::getEmail() { return email; }
int Student::getAge() { return age; }
int* Student::getDaysInCourse() { return daysInCourse; }
DegreeProgram Student::getDegreeProgram() { return degreeProgram; }

//implement the mutators (setter) for each instance variable in student.h
void Student::setID(string sID) { this->studentID = sID; }
void Student::setFirstName(string firstName) { this->first_name = firstName; }
void Student::setLastName(string lastName) { this->last_name = lastName; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInCourse(int daysInCourse[]) {
	this->daysInCourse = new int[daysInCourseSize];
	for (int i{ 0 }; i < daysInCourseSize; i++)
		this->daysInCourse[i] = daysInCourse[i];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

//print() function to print specific student data
void Student::print()
{
	cout << left << setw(5) << studentID;
	cout << left << setw(10) << first_name;
	cout << left << setw(15) << last_name;
	cout << left << setw(30) << email;
	cout << left << setw(5) << age;
	cout << left << setw(5) << daysInCourse[0];
	cout << left << setw(5) << daysInCourse[1];
	cout << left << setw(5) << daysInCourse[2];
	cout << left << setw(10) << degreeProgramStrings[getDegreeProgram()] << std::endl;
}

//Destructor
Student::~Student() {
	if (daysInCourse != nullptr) {
		delete[] daysInCourse;
		daysInCourse = nullptr;
	}
}
