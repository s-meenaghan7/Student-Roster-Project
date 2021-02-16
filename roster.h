#pragma once
#include "student.h"

class Roster {
public:
	int lastIndex;//index of last student in roster
	int capacity;//capacity of the roster
	Student** classRosterArray;//array of pointers to hold data provided in the studentData string
	Roster();//empty constructor
	Roster(int capacity);//constructor setting capacity of roster
	void parseAdd(string datarow);//add function. parses strings, comma separated. Creates objects, adds to roster
	void printAll();//prints all classRosterArray student objects in roster using student's print() method
	bool remove(string sID);//remove student based on studentID.  If the student ID does not exist, the function prints an error message indicating that the student was not found.

	void printAverageDaysInCourse(string sID); // correctly prints student’s average number of days in the three courses. Student identified by studentID.
	void printInvalidEmails(); // verifies student email addresses, displays all invalid email addresses.
	void printByDegreeProgram(DegreeProgram degreeProgram);
	

	~Roster();//destructor
};

const int numStudents = 5;
const string studentData[numStudents] =
{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Sean,Meenaghan,seanmeenaghan@gmail.com,26,28,14,21,SOFTWARE"
};

