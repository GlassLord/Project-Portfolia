#include "student.h"
#include <iostream>
#include "degree.h"
#include "roster.h"
using namespace std;

//Student constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress,
                 int age, int numDays1, int numDays2, int numDays3, DegreeProgram degreeProgram)
    : studentID(studentID), firstName(firstName), lastName(lastName), emailAddress(emailAddress),
      age(age), degreeProgram(degreeProgram) {
    numDays[0] = numDays1;
    numDays[1] = numDays2;
    numDays[2] = numDays3;
}

//accessors
string Student::getStudentID() const {
    return studentID;
}
string Student::getFirstName() const {
    return firstName;
}
string Student::getLastName() const {
    return lastName;
}
string Student::getEmailAddress() const {
    return emailAddress;
}
int Student::getAge() const {
    return age;
}
int* Student::getDaysInCourse() {
    return numDays;
}
DegreeProgram Student::getDegreeProgram() const {
    return degreeProgram;
}
string Student::getDegreeProgramName() const {
    if (degreeProgram == SECURITY) {
    return "Security";
} 
    else if (degreeProgram == NETWORK){
    return "Network";
}
    else if (degreeProgram == SOFTWARE){
    return "Software";
}
    else {
    return "UNKNOWN";
}
}
int Student::getNumDays1() const{
    return numDays[0];
}
int Student::getNumDays2() const{
    return numDays[1];
}
int Student::getNumDays3() const{
    return numDays [2];
}

//mutators
void Student::setStudentID(string studentID) {
    this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
    this->firstName = firstName;
}
void Student::setLastName(string lastName) {
    this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
}
void Student::setAge(int age) {
    this->age = age;
}
void Student::setDaysInCourse(int numDays1, int numDays2, int numDays3) {
    numDays[0] = numDays1;
    numDays[1] = numDays2;
    numDays[2] = numDays3;
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

//print specific student data
void Student::print(const string& targetStudentID) const {
    if (studentID == targetStudentID) {
        cout << studentID << "\tFirst Name: " << firstName << "\tLast Name: " << lastName
              << "\tEmail Address: " << emailAddress << "\tAge: " << age << "\tDays in Course: "
              << numDays[0] << ", " << numDays[1] << ", " << numDays[2] << "\tDegree Program: "
              << (degreeProgram == SECURITY ? "Security" : (degreeProgram == NETWORK ? "Network" : "Software"))
              << endl;
    }
}

              
              