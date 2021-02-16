#include "roster.h"
#include <string>
#include <iostream>

using std::string;

//implement the constructor
Roster::Roster()
{
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}
//implement constructor setting max int capacity of the roster
Roster::Roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [capacity];
}
//parse the studentData, create and add each object to Roster (Add function)
void Roster::parseAdd(string datarow)
{
	if (lastIndex < capacity) {
		lastIndex++;
		int darray[Student::daysInCourseSize];//temporary array to hold classRosterArray avg daysInCourse
		//Create student object using constructor
		if (datarow[0] == 'A') {
			this->classRosterArray[lastIndex] = new Student();//add new student to the array of pointers classRosterArray[lastIndex]

			//parse through each student datarow string, delimitting on the comma
			//extact each substring, set each field for the student that was just created

			//setID
			//rhs - right hand side (of variable being parsed) find the first comma to delimit on in each datarow
			int rhs = studentData[lastIndex].find(",");
			classRosterArray[lastIndex]->setID(studentData[lastIndex].substr(0, rhs));

			//setFirstName
			//lhs - left hand side: one index after the previous rhs
			int lhs = rhs + 1;
			rhs = studentData[lastIndex].find(",", lhs);
			classRosterArray[lastIndex]->setFirstName(studentData[lastIndex].substr(lhs, rhs - lhs));

			//setLastName
			lhs = rhs + 1;
			rhs = studentData[lastIndex].find(",", lhs);
			classRosterArray[lastIndex]->setLastName(studentData[lastIndex].substr(lhs, rhs - lhs));

			//setEmail
			lhs = rhs + 1;
			rhs = studentData[lastIndex].find(",", lhs);
			classRosterArray[lastIndex]->setEmail(studentData[lastIndex].substr(lhs, rhs - lhs));

			//setAge
			lhs = rhs + 1;
			rhs = studentData[lastIndex].find(",", lhs);
			classRosterArray[lastIndex]->setAge(stoi(studentData[lastIndex].substr(lhs, rhs - lhs)));

			//read each dayInCourse, convert str to int (3 total to each be stored in darray[] temporarily)
			lhs = rhs + 1;
			rhs = studentData[lastIndex].find(",", lhs);
			darray[0] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

			lhs = rhs + 1;
			rhs = studentData[lastIndex].find(",", lhs);
			darray[1] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

			lhs = rhs + 1;
			rhs = studentData[lastIndex].find(",", lhs);
			darray[2] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

			//setDaysInCourse using the temp darray
			classRosterArray[lastIndex]->setDaysInCourse(darray);

			//setDegreeProgram
			lhs = rhs + 1;
			rhs = studentData[lastIndex].find(",", lhs);
			
			string program = studentData[lastIndex].substr(lhs, rhs - lhs);
			if (program == degreeProgramStrings[0]) {
				classRosterArray[lastIndex]->setDegreeProgram(SECURITY);
			}
			else if (program == degreeProgramStrings[1]) {
				classRosterArray[lastIndex]->setDegreeProgram(NETWORK);
			}
			else if (program == degreeProgramStrings[2]) {
				classRosterArray[lastIndex]->setDegreeProgram(SOFTWARE);
			}
		}
	}
}

void Roster::printAll()
{
	for (int i{ 0 }; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
}

bool Roster::remove(string sID)
{
	bool found = false;
	for (int i{ 0 }; i < lastIndex; i++)
	{
		if (this->classRosterArray[i]->getID() == sID)
		{
			found = true;
			std::cout << "Done!\n";
			//delete the student from the array
			delete this->classRosterArray[i];
			//move last student to this (previously deleted) position to close gap in array
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
		}
	}
	return found;
}

void Roster::printAverageDaysInCourse(string sID)
{
	bool found = false;
	for (int i{ 0 }; i <= lastIndex; i++)
	{
		if (this->classRosterArray[i]->getID() == sID)
		{
			found = true;
			int* p = classRosterArray[i]->getDaysInCourse();
			std::cout << sID << " - Average days to complete course: " << (p[0] + p[1] + p[2]) / 3.0 << "\n";
		}
	}
	if (!found) std::cout << "Student not found!\n";
}

void Roster::printInvalidEmails()
{
	for (int i{ 0 }; i < lastIndex; i++)
	{
		string email = classRosterArray[i]->getEmail();
		if (email.find(" ") != string::npos) {
			std::cout << email << std::endl;
		}
		else if (email.find(".") == string::npos || email.find("@") == string::npos) {
			std::cout << email << std::endl;
		}
	}
	std::cout << "\n";
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	std::cout << "\nPrint by degree program: " << degreeProgramStrings[degreeProgram] << std::endl;
	for (int i{ 0 }; i < numStudents; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
	}
}

Roster::~Roster() {
	for (int i{ 0 }; i < numStudents; i++)
	{
		delete this->classRosterArray[i];
	}
	delete this;
}