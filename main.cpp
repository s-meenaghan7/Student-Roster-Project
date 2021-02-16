#include "student.h"
#include "roster.h"
#include "degree.h"
#include <iostream>
#include <string>

int main() {
    // Print out to the screen, via your application, the course title, the programming language used, and your name.
    string title{ "Scripting and Programming - Applications - C867 | Written in C++ | Sean Meenaghan" };
    std::cout << title << std::endl;

    //create an instance of the Roster class called classRoster
    Roster* classRoster = new Roster(numStudents);//created classRoster dynamically
    std::cout << "\nParsing data from table, adding students to roster:...";
    
    for (int i{ 0 }; i < numStudents; i++)
    {
        classRoster->parseAdd(studentData[i]);
    }

    // display all students in the classRosterArray
    std::cout << "\nDisplaying students:\n" << std::endl;
    classRoster->printAll();

    //classRoster.printInvalidEmails();
    std::cout << "\nDisplaying invalid emails:" << std::endl;
    classRoster->printInvalidEmails();
    
    //loop through classRosterArray and for each element:
    //classRoster.printAverageDaysInCourse(current_object's student id);
    for (int i{ 1 }; i <= numStudents; i++) {
        string ID = "A";
        string objectID = ID + std::to_string(i);
        classRoster->printAverageDaysInCourse(objectID);
    }
    //classRoster->printAverageDaysInCourse("A1");//prints only the specified ID. Cannot loop through.


    classRoster->printByDegreeProgram(SOFTWARE);
    
    std::cout << "\nRemoving A3...";
    if (classRoster->remove("A3")) classRoster->printAll();
    else std::cout << "Student not found!" << std::endl;

    std::cout << "\nRemoving A3...";
    if (classRoster->remove("A3")) classRoster->printAll();
    else std::cout << "Student not found!" << std::endl;

    system("pause");
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
