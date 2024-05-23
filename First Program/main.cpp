#include <iostream>
#include "roster.h"
#include "degree.h"
#include "student.h"  

using namespace std;

int main() {
    
    //Print course title, programming language, student id, and name.
    cout << "Scripting and Programming - Applications" << endl;
    cout << "C++" << endl;
    cout << "000761395" << endl;
    cout << "Matthew Ryther" << endl;

    //create instance of classRoster
    Roster classRoster;
    //Add students to class roster
    classRoster.ParseData();
    
    //prints all students
    classRoster.printAll();
    cout << endl;

    //prints invalid emails
    classRoster.printInvalidEmails();
    cout << endl;

    //loops through the class roster array, to prints the average days in courses for each student.
    for (const auto& student : classRoster.getClassRosterArray()) {
        classRoster.printAverageDaysInCourse(student.getStudentID());
    }
    cout << endl;

    //prints out students of a specific degree program
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    //removes a student from the roster by ID 
    classRoster.remove("A3");
    cout << endl;

    // prints student data again to show succesful removal
    classRoster.printAll();
    cout << endl;

    // tries to remove the same student
    classRoster.remove("A3");
    cout << endl;

    // destructor
    classRoster.~Roster();

return 0;
};

