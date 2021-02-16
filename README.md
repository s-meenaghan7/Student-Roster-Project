# Student-Roster-Project
University project written in C++. 

This project served as the final project for a scipting & programming class.
This project demonstates competency and understanding of the C++ programming language, as well as general programming concepts such as object-oriented programming, data structures, the use of functions, pointers, and data types including enumerated types.


The program uses two classes: Student and Roster. Student objects are added to a class Roster (like a database).
The program first initializes an instance of the Roster class. Then, the program parses an array (studentData) containing 5 long strings, each in coma-delimited format. The parseAdd() function creates a new Student object, parses each string to set each Student's private variables (attributes) to those found as they are in each string.


After parsing the studentData array for the values for each Student object, the roster is displayed, showing the roster of 5 students and their values (i.e. studentID, firstName, lastName, email, age, average days to complete a course (for 3 courses), and an enumerated type for each student's degreeProgram, being one of SECURITY, NETWORK, or SOFTWARE. Each row is a record of a single student.

Several functions are performed on the data. 3 Student's email information in the studentData array was incorrectly entered by design to demonstrate a function that displays invalid emails to the console (printInvalidEmails). Then, the average number of days to complete a course for each student is displayed. 3 integers contained in an array represent the number of days required for a student to complete 3 different courses. These numbers are averaged to determine the output for each student of printAverageDaysInCourse(). Next, we print to the console all the students that are in the degree program: SOFTWARE. This displays 2 of the 5 students. Finally, we remove a student from the Roster, then display the updated version of the roster. Before the program ends, the program attempts to remove the same (previously removed) student, to demonstrate the functions behavior whenever this may occur.
