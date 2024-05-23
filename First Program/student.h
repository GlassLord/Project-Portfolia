#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "degree.h" 

using namespace std;

// Create Student class
class Student {
public:
    
    Student(string studentID, string firstName, string lastName, string emailAddress,
            int age, int numDays1, int numDays2, int numDays3, DegreeProgram degreeProgram);
    
    // Accessors for variables
    string getStudentID() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmailAddress() const;
    int getAge() const;
    int* getDaysInCourse();
    DegreeProgram getDegreeProgram() const;
    string getDegreeProgramName() const;
    int getNumDays1() const;
    int getNumDays2() const;
    int getNumDays3() const;

    // Mutators for variables
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDaysInCourse(int numDays1, int numDays2, int numDays3);
    void setDegreeProgram(DegreeProgram degreeProgram);

    // Print specific studnet data
    void print(const string& targetStudentID) const;

private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int numDays[3];
    DegreeProgram degreeProgram;
};

#endif

