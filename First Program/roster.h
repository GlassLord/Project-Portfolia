#ifndef ROSTER_H
#define ROSTER_H

#include <vector>
#include <string>
#include "student.h"
#include "degree.h"
#include <sstream>
#include <iostream>

class Roster {
public:

    //Constructor and Destructor
    Roster(){};
    ~Roster(){};

    //add or remove objects
    void add(string studentID, string firstName, string lastName, string emailAddress,
             int age, int numDays1, int numDays2, int numDays3, DegreeProgram degreeProgram);
    void remove(string studentID);

    //print data
    void printAll() const;
    void printAverageDaysInCourse(string studentID) const;
    void printInvalidEmails() const;
    void printByDegreeProgram(DegreeProgram degreeProgram) const;

    //gets student object
    const vector<Student>& getClassRosterArray() const {
        return classRosterArray;
    }    
    //parses student data
    void ParseData();

private:
    // Array for studentData
    vector<Student> classRosterArray;

    // Function to check if an email is valid
    bool isValidEmail(const string& email) const;
};



#endif 
